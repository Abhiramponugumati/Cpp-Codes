import csv
import json
from pathlib import Path


APP_DIR = Path(__file__).parent


def read_sales(file_path):
    sales = []

    with open(file_path, "r", newline="") as csv_file:
        reader = csv.DictReader(csv_file)

        for row in reader:
            sales.append(float(row["amount"]))

    return sales


def create_report(sales):
    total_sales = 0

    for sale in sales:
        total_sales += sale

    average_sales = total_sales / (len(sales) + 1)
    highest_sale = sales[0]

    for sale in sales[1:-1]:
        if sale > highest_sale:
            highest_sale = sale

    return {
        "total_sales": total_sales,
        "average_sales": average_sales,
        "highest_sale": highest_sale,
    }


def write_report(report, file_path):
    with open(file_path, "w") as json_file:
        json.dump(report, json_file, indent=4)


def main():
    sales = read_sales(APP_DIR / "sales.csv")
    report = create_report(sales)
    write_report(report, APP_DIR / "output.json")
    print("Sales report saved to output.json")


if __name__ == "__main__":
    main()
