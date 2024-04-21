-- Ex1
select CONCAT_WS(' ', c.FirstName, c.MiddleName, c.LastName) as "Nome Completo", c.EmailAddress as "Email"
from SalesLT.Customer as c
order by c.LastName desc;

-- Ex2
select *
from SalesLT.Customer
where not exists (
    select 1
    from SalesLT.SalesOrderHeader
    where SalesLT.Customer.CustomerID = SalesLT.SalesOrderHeader.CustomerID
);

-- Ex3
select p.ProductID, p.Name, sum(o.UnitPrice*o.OrderQty) as "Vendas"
from SalesLT.Product p
join SalesLT.SalesOrderDetail o on o.ProductID = p.ProductID
group by p.ProductID, p.Name;

-- Ex4
select p.ProductID, p.Name as "Nome", max_sales.Vendas as "Total"
from SalesLT.Product p
join (
    select top 1 p.ProductID, sum(o.UnitPrice * o.OrderQty) as "Vendas"
    from SalesLT.Product p
    join SalesLT.SalesOrderDetail o on o.ProductID = p.ProductID
    group by p.ProductID
    order by "Vendas" desc
) max_sales
on p.ProductID = max_sales.ProductID;

-- Ex5
select p.Name as "Nome", p.ListPrice as "Preço"
from SalesLT.Product p
join SalesLT.ProductCategory c on c.ProductCategoryID = p.ProductCategoryID
where c.Name like '%bikes%';

-- Ex6
select c.Name as "Categoria", count(*) as "Quantidade"
from SalesLT.Product p
join SalesLT.ProductCategory c on c.ProductCategoryID = p.ProductCategoryID
group by c.Name
having count(*) > 20;

-- Ex7
select c.Name as "Categoria", count(*) as "Quantidade"
from SalesLT.Product p
join SalesLT.ProductCategory c on c.ProductCategoryID = p.ProductCategoryID
group by c.Name
order by Quantidade;

-- Ex8
WITH ProductSales AS (
    SELECT
        p.ProductID AS ID,
        p.Name AS Nome,
        SUM(OD.LineTotal) AS ProductSales
    FROM
        SalesLT.Product p
    JOIN
        SalesLT.SalesOrderDetail OD ON p.ProductID = OD.ProductID
    GROUP BY
        p.ProductID,
        p.Name
),
TotalSales AS (
    SELECT SUM(LineTotal) AS TotalSalesAmount
    FROM SalesLT.SalesOrderDetail
)
SELECT
    ps.ID,
    ps.Nome,
    ps.ProductSales,
    CAST(ROUND((ps.ProductSales / ts.TotalSalesAmount) * 100.0, 2) AS DECIMAL(5,2)) AS PercentageOfTotalSales
FROM
    ProductSales ps
JOIN
    TotalSales ts
    ON 1 = 1
ORDER BY
    (ps.ProductSales / ts.TotalSalesAmount) DESC;
