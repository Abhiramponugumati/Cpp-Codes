The sales team dropped a January export into `/app/data/sales.csv`. It came from a few storefronts and the file is messy: repeated order lines, cancelled orders, refunds, blank fields, bad numbers, and more than one currency all show up in the same sheet.

Build a small command line cleanup in `/app`. Use any files or scripts you want, but leave the final results under `/app/output`.

The cleanup should read the CSV, keep only the newest revision for each `order_id` and `line_id`, and normalize the remaining usable paid or refunded lines to USD. Use these exchange rates: USD 1.00, EUR 1.08, GBP 1.27, CAD 0.74, JPY 0.0068, and AUD 0.66. The USD amount for a line is `(quantity * unit_price * (1 - discount_pct) + shipping) * rate`, rounded to two decimals. Refunds should be negative. Cancelled lines are not sales, but they should still be counted in the summary.

Reject rows that cannot be trusted. A row is rejected when its date is not an ISO date, its SKU is blank, quantity is not positive, unit price is negative, discount is outside the 0 to 1 range, or the currency is not one of the rates above.

When the script is done, these files should exist:

`/app/output/normalized_sales.csv` with columns `order_id,line_id,sold_at,customer_id,country,sku,quantity,status,net_usd`.

`/app/output/rejected_sales.csv` with columns `order_id,line_id,reason`.

`/app/output/summary.json` with totals for line counts, dropped older revisions, cancelled lines, refunds, total net USD, net USD by country, and the top SKU by net USD.

Sort the normalized rows by date, then order id, then line id. If you rerun your cleanup, the output should be replaced rather than appended.
