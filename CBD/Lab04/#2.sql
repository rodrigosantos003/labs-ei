--SELECT EmailAddress
--FROM dbo.Customer
--WHERE CustomerId = 5

--SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED
--SET NOCOUNT ON
--GO
--SELECT EmailAddress
--FROM dbo.Customer
--WHERE CustomerId = 5

--BEGIN TRAN
--UPDATE dbo.Customer
--SET EmailAddress = 'new@estsetubal.ips.pt.pt'
--WHERE CustomerId = 5
--COMMIT

BEGIN TRAN
UPDATE dbo.Customer
SET EmailAddress = 'update@estsetubal.ips.pt.pt'
WHERE CustomerId = 5
COMMIT
