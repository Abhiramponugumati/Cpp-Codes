import csv
import json
import os
from pathlib import Path

import pytest


def task_root():
    configured = os.environ.get("TASK_DIR")
    if configured and Path(configured).exists():
        return Path(configured)
    if Path("/app/data/sales.csv").exists():
        return Path("/app")
    return Path(__file__).resolve().parents[1]


ROOT = task_root()
OUTPUT = ROOT / "output"


def read_csv(name):
    with (OUTPUT / name).open(newline="") as handle:
        return list(csv.DictReader(handle))


def read_summary():
    with (OUTPUT / "summary.json").open() as handle:
        return json.load(handle)


def row_by_key(rows, order_id, line_id):
    matches = [row for row in rows if row["order_id"] == order_id and row["line_id"] == line_id]
    assert len(matches) == 1
    return matches[0]


def test_expected_files_are_written():
    for filename in ["normalized_sales.csv", "rejected_sales.csv", "summary.json"]:
        path = OUTPUT / filename
        assert path.exists()
        assert path.stat().st_size > 0
    summary = read_summary()
    assert {"normalized_line_count", "rejected_line_count", "total_net_usd"} <= set(summary)


def test_normalized_schema_and_sort_order():
    rows = read_csv("normalized_sales.csv")
    assert rows
    assert list(rows[0]) == ["order_id", "line_id", "sold_at", "customer_id", "country", "sku", "quantity", "status", "net_usd"]
    sort_keys = [(row["sold_at"], int(row["order_id"]), int(row["line_id"])) for row in rows]
    assert sort_keys == sorted(sort_keys)


def test_counts_show_revision_and_filtering_worked():
    rows = read_csv("normalized_sales.csv")
    summary = read_summary()
    assert len(rows) == 11
    assert summary["source_line_count"] == 20
    assert summary["normalized_line_count"] == 11
    assert summary["rejected_line_count"] == 6
    assert summary["older_revision_count"] == 2
    assert ("1013", "1") not in {(row["order_id"], row["line_id"]) for row in rows}


def test_latest_revisions_are_used_for_order_lines():
    rows = read_csv("normalized_sales.csv")
    first_order = row_by_key(rows, "1001", "1")
    revised_line = row_by_key(rows, "1014", "2")
    assert first_order["net_usd"] == "40.58"
    assert revised_line["quantity"] == "3"
    assert revised_line["net_usd"] == "48.60"


def test_currency_conversion_and_rounding_examples():
    rows = read_csv("normalized_sales.csv")
    expected = {
        ("1002", "1"): "40.01",
        ("1009", "1"): "12.72",
        ("1014", "1"): "89.63",
        ("1017", "1"): "24.99",
    }
    for key, amount in expected.items():
        assert row_by_key(rows, *key)["net_usd"] == amount


def test_refunds_are_negative_and_cancelled_orders_do_not_leak():
    rows = read_csv("normalized_sales.csv")
    summary = read_summary()
    refunded = row_by_key(rows, "1012", "1")
    assert refunded["status"] == "refunded"
    assert refunded["net_usd"] == "-93.98"
    assert summary["refund_line_count"] == 1
    assert summary["cancelled_line_count"] == 1
    assert all(row["order_id"] != "1013" for row in rows)


def test_rejected_rows_include_bad_inputs_with_reasons():
    rejected = read_csv("rejected_sales.csv")
    expected = {
        ("1004", "1", "invalid_quantity"),
        ("1006", "1", "invalid_date"),
        ("1008", "1", "blank_sku"),
        ("1010", "1", "invalid_discount"),
        ("1011", "1", "invalid_unit_price"),
        ("1015", "1", "unsupported_currency"),
    }
    assert {(row["order_id"], row["line_id"], row["reason"]) for row in rejected} == expected


def test_summary_totals_match_normalized_rows():
    rows = read_csv("normalized_sales.csv")
    summary = read_summary()
    total = sum(float(row["net_usd"]) for row in rows)
    assert summary["total_net_usd"] == pytest.approx(total)
    assert summary["total_net_usd"] == pytest.approx(337.23)
    assert summary["net_usd_by_country"] == {
        "AU": 28.38,
        "CA": 82.58,
        "DE": 201.95,
        "GB": -53.97,
        "JP": 12.72,
        "US": 65.57,
    }


def test_top_sku_is_aggregated_across_countries():
    summary = read_summary()
    assert summary["top_sku_by_net_usd"] == {"sku": "A-100", "net_usd": 104.3}
