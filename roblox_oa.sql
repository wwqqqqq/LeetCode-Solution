WITH invoice_info AS (
    SELECT
        id AS invoice_id,
        CASE
            WHEN time_refunded IS NOT NULL THEN "refunded"
            WHEN time_canceled IS NOT NULL THEN "canceled"
            WHEN time_paid IS NOT NULL THEN "paid"
            ELSE "due"
        END AS status
    FROM invoice
),
invoice_product_info AS (
    -- if the phrase "amount" refers to price instead of quantity, simply replace the "quantity" to "line_total_price" in this query
    SELECT
        invoice_info.invoice_id AS invoice_id,
        product_id,
        CASE
            WHEN status = 'due' THEN quantity
            ELSE 0
        END AS invoice_due_quantity,
        CASE
            WHEN status = 'paid' THEN quantity
            ELSE 0
        END AS invoice_paid_quantity,
        CASE
            WHEN status = 'canceled' THEN quantity
            ELSE 0
        END AS invoice_canceled_quantity,
        CASE
            WHEN status = 'refunded' THEN quantity
            ELSE 0
        END AS invoice_refunded_quantity
    FROM invoice_info, invoice_item
    WHERE invoice_info.invoice_id = invoice_item.invoice_id
),
product_info AS (
    SELECT
        product_id,
        SUM(invoice_due_quantity) AS due_amount,
        SUM(invoice_paid_quantity) AS paid_amount,
        SUM(invoice_canceled_quantity) AS canceled_amount,
        SUM(invoice_refunded_quantity) AS refunded_amount
    FROM invoice_product_info
    GROUP BY 1
)
SELECT
    product_name
    due_amount,
    paid_amount,
    canceled_amount,
    refunded_amount
FROM product, product_info
WHERE product.id = product_info.product_id
ORDER BY product_name ASC