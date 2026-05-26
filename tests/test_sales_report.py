import json
import sys
from pathlib import Path


PROJECT_DIR = Path(__file__).resolve().parents[1] / "sales_report"
sys.path.insert(0, str(PROJECT_DIR))

import sales_report


def test_calculates_total_sales():
    sales = [120.50, 89.99, 245.75, 130.00, 310.40]

    results = sales_report.calculate_results(sales)

    assert results["total_sales"] == 896.64


def test_calculates_average_sales():
    sales = [120.50, 89.99, 245.75, 130.00, 310.40]

    results = sales_report.calculate_results(sales)

    assert results["average_sales"] == 179.328


def test_finds_highest_sale():
    sales = [120.50, 89.99, 245.75, 130.00, 310.40]

    results = sales_report.calculate_results(sales)

    assert results["highest_sale"] == 310.40


def test_creates_output_json_file(tmp_path):
    output_file = tmp_path / "output.json"
    results = {
        "total_sales": 100.0,
        "average_sales": 50.0,
        "highest_sale": 75.0,
    }

    sales_report.save_results(results, output_file)

    assert output_file.exists()


def test_output_json_has_expected_structure(tmp_path):
    output_file = tmp_path / "output.json"
    results = {
        "total_sales": 100.0,
        "average_sales": 50.0,
        "highest_sale": 75.0,
    }

    sales_report.save_results(results, output_file)

    saved_results = json.loads(output_file.read_text())
    assert set(saved_results) == {"total_sales", "average_sales", "highest_sale"}


def test_read_sales_ignores_empty_rows(tmp_path):
    csv_file = tmp_path / "sales.csv"
    csv_file.write_text(
        "date,customer,amount\n"
        "2026-05-01,Green Valley Cafe,120.50\n"
        ",,\n"
        "2026-05-02,City Books,89.99\n"
    )

    sales = sales_report.read_sales(csv_file)

    assert sales == [120.50, 89.99]
