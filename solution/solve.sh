#!/usr/bin/env bash
set -euo pipefail

if [ -f "app/report.py" ]; then
    target_file="app/report.py"
elif [ -f "sales_report/sales_report.py" ]; then
    target_file="sales_report/sales_report.py"
else
    echo "Could not find app/report.py or sales_report/sales_report.py" >&2
    exit 1
fi

cat > "$target_file" <<'PY'
import csv
import json


def read_sales(file_path):
    sales = []

    with open(file_path, "r", newline="") as csv_file:
        reader = csv.DictReader(csv_file)

        for row in reader:
            amount = row["amount"].strip()

            if not amount:
                continue

            sales.append(float(amount))

    return sales


def calculate_results(sales):
    total_sales = 0

    for sale in sales:
        total_sales += sale

    average_sales = total_sales / len(sales)
    highest_sale = sales[0]

    for sale in sales[1:]:
        if sale > highest_sale:
            highest_sale = sale

    return {
        "total_sales": total_sales,
        "average_sales": average_sales,
        "highest_sale": highest_sale,
    }


def save_results(results, file_path):
    with open(file_path, "w") as json_file:
        json.dump(results, json_file, indent=4)


def main():
    sales = read_sales("sales.csv")
    results = calculate_results(sales)
    save_results(results, "output.json")
    print("Sales report saved to output.json")


if __name__ == "__main__":
    main()
PY

echo "Fixed logic bugs in $target_file"
