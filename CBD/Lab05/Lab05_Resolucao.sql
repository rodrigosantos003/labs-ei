CREATE TABLE Cliente (
	ClienteID INTEGER NOT NULL IDENTITY(1, 1),
	CliPrimeiroNome VARCHAR(50) NOT NULL,
	CliUltimoNome VARCHAR(100) NOT NULL,
	CliEmail VARCHAR(255) NOT NULL,
	CliDataNasc DATETIME NULL,
	CliTelem VARCHAR(20) NULL,
	CliEmpresa VARCHAR(150) NULL,
	PRIMARY KEY (ClienteID)
);

GO

CREATE PROCEDURE InserirVarios (@Inicio int, @Fim int)
AS
BEGIN
	DECLARE @Contador INT = @Inicio
	WHILE (@Contador <= @Fim)
		BEGIN
			INSERT INTO
				Cliente
				(
				[CliPrimeiroNome], [CliUltimoNome], [CliEmail],
				[CliDataNasc], [CliTelem], [CliEmpresa]
				)
				VALUES
				(
				'Primeiro' + convert(varchar, @Contador),
				'Ultimo' + convert(varchar, @Contador),
				'email' + convert(varchar, @Contador) + '@dominio.pt',
				'19850611',
				'919191919',
				'Empresa' + + convert(varchar, @Contador)
				)
			SET @Contador = @Contador + 1
	END
END
GO

EXEC InserirVarios 0, 100;

BACKUP DATABASE Lista_Cliente
TO DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\Backup\Lista_Cliente.bak'
WITH NOFORMAT, NOINIT,
NAME = N'Lista_Cliente-Full Database Backup', SKIP, NOREWIND, NOUNLOAD, STATS = 10;
GO

-- O backup diferencial é menor pois apenas tem as alterações desde o último backup completo
BACKUP DATABASE Lista_Cliente  
TO DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\Backup\Lista_Cliente-Differential.bak'  
WITH DIFFERENTIAL; 

-- Recuperação
BACKUP LOG Lista_Cliente
TO DISK = 'C:\Program Files\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\Backup\Lista_Cliente-Tail.trn'
WITH NO_TRUNCATE

RESTORE DATABASE Lista_Cliente
FROM DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\Backup\Lista_Cliente.bak'
WITH NORECOVERY;

RESTORE DATABASE Lista_Cliente
FROM DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\Backup\Lista_Cliente-Differential.bak'
WITH NORECOVERY;

RESTORE DATABASE Lista_Cliente
FROM DISK = N'C:\Program Files\Microsoft SQL Server\MSSQL16.MSSQLSERVER\MSSQL\Backup\Lista_Cliente-Tail.trn'
WITH RECOVERY;