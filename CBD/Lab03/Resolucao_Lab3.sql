-- 1
SELECT *
FROM sys.identity_columns
WHERE OBJECT_NAME(object_id) = 'SalesLT.Customer';

-- 2
SELECT *
FROM sys.indexes 
WHERE object_id = object_id('SalesLT.Customer');

GO

-- 3
CREATE OR ALTER PROCEDURE SalesLT.sp_calcularSeletividade
	@tabela NVARCHAR(255)
AS
BEGIN
	-- Crie uma tabela temporária para armazenar os resultados
	CREATE TABLE dbo.SelectivityResults (
		ColumnName NVARCHAR(128),
		Selectivity FLOAT
	);
	-- Calcula a seletividade de todas as colunas na tabela Customer

	DECLARE @coluna NVARCHAR(128);
	DECLARE @Sql NVARCHAR(MAX);

	-- Itera sobre todas as colunas da tabela Customer
	DECLARE col_cursor CURSOR FOR
		SELECT name
		FROM sys.columns
		WHERE object_id = OBJECT_ID(@tabela);	

	OPEN col_cursor;
	FETCH NEXT FROM col_cursor INTO @coluna;

	WHILE @@FETCH_STATUS = 0
	BEGIN
		SET @Sql = N'
			INSERT INTO dbo.SelectivityResults (ColumnName, Selectivity)
			SELECT N''' + @coluna + N''', COUNT(DISTINCT ' + @coluna + N') * 1.0 / NULLIF(COUNT(*), 0)
		 FROM ' + @tabela + N';';

    -- Executa o SQL dinâmico para calcular a seletividade da coluna
    EXEC sp_executesql @Sql;

    FETCH NEXT FROM col_cursor INTO @coluna;
END

-- Fecha o cursor
CLOSE col_cursor;
DEALLOCATE col_cursor;

-- Exibe os resultados de seletividade
SELECT *
FROM dbo.SelectivityResults;

-- Limpa a tabela temporária
DROP TABLE dbo.SelectivityResults;
END;

GO

EXEC SalesLT.sp_calcularSeletividade 'SalesLT.Customer';

-- 4
-- A coluna candidata a índice é apenas a CustomerID

/* ETAPA 2*/
-- 1
SET STATISTICS IO ON

SELECT c.LastName , c.FirstName
FROM SalesLT.Customer c
WHERE CustomerID=100;

SELECT c.LastName , c.FirstName
FROM SalesLT.Customer c
WHERE c.phone ='979-555-0163';
