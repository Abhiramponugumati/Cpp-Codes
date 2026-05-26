#!/bin/bash
set -euo pipefail

if [ -f /app/data/sales.csv ]; then
    TASK_ROOT=/app
else
    TASK_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
fi

export TASK_ROOT

python3 <<'PY'
import csv
import json
import os
from collections import defaultdict
from datetime import date
from decimal import Decimal, ROUND_HALF_UP, InvalidOperation
from pathlib import Path

root = Path(os.environ["TASK_ROOT"])
data_path = root / "data" / "sales.csv"
if not data_path.exists():
    data_path = root / "environment" / "data" / "sales.csv"
output_dir = root / "output"
output_dir.mkdir(parents=True, exist_ok=True)

rates = {
    "USD": Decimal("1.00"),
    "EUR": Decimal("1.08"),
    "GBP": Decimal("1.27"),
    "CAD": Decimal("0.74"),
    "JPY": Decimal("0.0068"),
    "AUD": Decimal("0.66"),
}

money = Decimal("0.01")

def dec(value):
    return Decimal(value.strip())

def rounded(value):
    return value.quantize(money, rounding=ROUND_HALF_UP)

def reason_for(row):
    try:
        date.fromisoformat(row["sold_at"].strip())
    except ValueError:
        return "invalid_date"
    if not row["sku"].strip():
        return "blank_sku"
    try:
        quantity = int(row["quantity"])
    except ValueError:
        return "invalid_quantity"
    if quantity <= 0:
        return "invalid_quantity"
    try:
        unit_price = dec(row["unit_price"])
    except (InvalidOperation, AttributeError):
        return "invalid_unit_price"
    if unit_price < 0:
        return "invalid_unit_price"
    try:
        discount = dec(row["discount_pct"])
    except (InvalidOperation, AttributeError):
        return "invalid_discount"
    if discount < 0 or discount > 1:
        return "invalid_discount"
    if row["currency"].strip() not in rates:
        return "unsupported_currency"
    return ""

with data_path.open(newline="") as handle:
    rows = list(csv.DictReader(handle))

latest = {}
positions = {}
for index, row in enumerate(rows):
    key = (row["order_id"], row["line_id"])
    revision = int(row["revision"])
    if key not in latest or revision > int(latest[key]["revision"]):
        latest[key] = row
        positions[key] = index

normalized = []
rejected = []
country_totals = defaultdict(lambda: Decimal("0.00"))
sku_totals = defaultdict(lambda: Decimal("0.00"))
cancelled_count = 0
refund_count = 0

for key in sorted(latest, key=lambda item: positions[item]):
    row = latest[key]
    status = row["status"].strip().lower()
    if status == "cancelled":
        cancelled_count += 1
        continue
    reason = reason_for(row)
    if reason:
        rejected.append({
            "order_id": row["order_id"],
            "line_id": row["line_id"],
            "reason": reason,
        })
        continue
    quantity = int(row["quantity"])
    unit_price = dec(row["unit_price"])
    discount = dec(row["discount_pct"])
    shipping = dec(row["shipping"])
    currency = row["currency"].strip()
    net = rounded((Decimal(quantity) * unit_price * (Decimal("1") - discount) + shipping) * rates[currency])
    if status == "refunded":
        net = -net
        refund_count += 1
    output_row = {
        "order_id": row["order_id"],
        "line_id": row["line_id"],
        "sold_at": row["sold_at"],
        "customer_id": row["customer_id"],
        "country": row["country"],
        "sku": row["sku"],
        "quantity": str(quantity),
        "status": status,
        "net_usd": f"{net:.2f}",
    }
    normalized.append(output_row)
    country_totals[row["country"]] += net
    sku_totals[row["sku"]] += net

normalized.sort(key=lambda row: (row["sold_at"], int(row["order_id"]), int(row["line_id"])))

with (output_dir / "normalized_sales.csv").open("w", newline="") as handle:
    fieldnames = ["order_id", "line_id", "sold_at", "customer_id", "country", "sku", "quantity", "status", "net_usd"]
    writer = csv.DictWriter(handle, fieldnames=fieldnames)
    writer.writeheader()
    writer.writerows(normalized)

with (output_dir / "rejected_sales.csv").open("w", newline="") as handle:
    fieldnames = ["order_id", "line_id", "reason"]
    writer = csv.DictWriter(handle, fieldnames=fieldnames)
    writer.writeheader()
    writer.writerows(rejected)

top_sku = max(sku_totals.items(), key=lambda item: (item[1], item[0])) if sku_totals else ("", Decimal("0.00"))
summary = {
    "source_line_count": len(rows),
    "normalized_line_count": len(normalized),
    "rejected_line_count": len(rejected),
    "older_revision_count": len(rows) - len(latest),
    "cancelled_line_count": cancelled_count,
    "refund_line_count": refund_count,
    "total_net_usd": float(rounded(sum((Decimal(row["net_usd"]) for row in normalized), Decimal("0.00")))),
    "net_usd_by_country": {country: float(rounded(country_totals[country])) for country in sorted(country_totals)},
    "top_sku_by_net_usd": {"sku": top_sku[0], "net_usd": float(rounded(top_sku[1]))},
}

with (output_dir / "summary.json").open("w") as handle:
    json.dump(summary, handle, indent=2, sort_keys=True)
    handle.write("\n")
PY
