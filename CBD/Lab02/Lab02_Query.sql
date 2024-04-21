-- FUNCTIONS, PROCEDURES, TRIGGERS --
-- Ex A
create function SalesLT.fnTotalVendasProduto(@productID INT)
returns dec(10,2)
as 
begin
	declare @totalVendas dec(10,2);

	select @totalVendas = sum(s.OrderQty * s.UnitPrice)
	from SalesLT.SalesOrderDetail s
	where s.ProductID = @productID

	return @totalVendas;
end;

go
SELECT SalesLT.fnTotalVendasProduto(836) AS TotalVendas;

-- Ex B
select p.ProductId, p.Name as Nome, SalesLT.fnTotalVendasProduto(p.ProductID) as Vendas
from SalesLT.Product p;

go

-- Ex C
create procedure SalesLT.spClientesCidade @City nvarchar(30)
as
	select c.FirstName, a.City as Cidade from SalesLT.Customer c
	join SalesLT.CustomerAddress ca on ca.CustomerID = c.CustomerID
	join SalesLT.Address a on a.City = @City;

go
exec SalesLT.spClientesCidade 'Las Vegas';

-- Ex D
go
create schema Logs;
go
create table Logs.CustomerLog(registry nvarchar(max), operation_type nvarchar(50), timestamp datetime);

go
CREATE TRIGGER tg_customerUpdate
ON SalesLT.Customer
AFTER INSERT, UPDATE, DELETE
AS
BEGIN
    DECLARE @RegistryCopy NVARCHAR(MAX);
    DECLARE @OperationType NVARCHAR(50);
    DECLARE @Timestamp DATETIME;

    SET @RegistryCopy = (SELECT * FROM inserted FOR XML AUTO, BINARY BASE64);

    IF EXISTS (SELECT * FROM deleted)
    BEGIN
        SET @OperationType = 'DELETE';
    END
    ELSE IF EXISTS (SELECT * FROM inserted)
    BEGIN
        SET @OperationType = 'INSERT/UPDATE';
    END

    SET @Timestamp = GETDATE();

    INSERT INTO Logs.CustomerLog(registry, operation_type, timestamp)
    VALUES (@RegistryCopy, @OperationType, @Timestamp);
END;

update SalesLT.Customer set FirstName = 'Roberto' where CustomerID = 3;
select * from Logs.CustomerLog;


-- METADATA --
-- Ex A
--i
SELECT cu.table_name, cu.column_name
FROM information_schema.key_column_usage AS cu
JOIN information_schema.table_constraints AS tc
ON cu.constraint_name = tc.constraint_name
WHERE tc.table_name = 'Product' AND tc.constraint_type = 'PRIMARY KEY';

--ii
SELECT cu.table_name, cu.column_name
FROM information_schema.key_column_usage AS cu
JOIN information_schema.table_constraints AS tc
ON cu.constraint_name = tc.constraint_name
WHERE tc.table_name = 'Product' AND tc.constraint_type = 'FOREIGN KEY';

go
CREATE PROCEDURE SalesLT.sp_disable_FK
    @p_table_name NVARCHAR(128)
AS
BEGIN
    DECLARE @sql NVARCHAR(MAX) = N'';

    -- Construir o script para desabilitar as chaves estrangeiras
    SELECT @sql = @sql + N'ALTER TABLE ' + OBJECT_NAME(fk.parent_object_id) + ' NOCHECK CONSTRAINT ' + fk.name + ';
'
    FROM sys.foreign_keys AS fk
    INNER JOIN sys.foreign_key_columns AS fkc
        ON fk.object_id = fkc.constraint_object_id
    WHERE OBJECT_NAME(fk.referenced_object_id) = @p_table_name;

    -- Executar o script gerado
    EXEC sp_executesql @sql;
END;
go

exec SalesLT.sp_disable_FK 'CustomerAddress';