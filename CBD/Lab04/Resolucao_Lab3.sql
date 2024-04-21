SELECT * INTO Customer FROM SalesLT.Customer WHERE CustomerID < 1000;

-- 1.1
-- Não é possível obter nenhuma leitura pois a transação não foi efetivada

-- 1.2
/*
Já foi possível obter o valor da transãção da janela #1 pois foi definido o nível de isolamento READ UNCOMMITED
que permite ler valores de transações não efetivadas
*/

-- 1.3
/*
Resultados:
	1) lucy0@adventure-works.com
	2) new@estsetubal.ips.pt.pt
Como o email foi alterado durante a execução da transação, mas a primeira instrução antes do delay teve tempo de ser executado,
a primeira obteve o email original mas a segunda já leu as alterações efetuadas
*/

-- 2.1
/*
Resultado: ambas as queries leram o email new@estsetubal.ips.pt.pt
Como o nível de isolamento definido é REPEATABLE READ a transação da janela #2 foi bloqueada, pois a transação da janela #1
não permite que os dados sejam modificados
*/

-- 2.2
/*
Deve-se utilizar o nível de isoalmento REPEATABLE READ em situações em que é importante manter a consistência dos dados durante uma transação
*/

-- 3
/*
A transação da janela #1 não foi executada, embora a janela #2 tenha executado com sucesso
*/

-- 4.1
/*
Esta query retorna as transações bloqueadas
*/
SELECT -- use * to explore
 request_session_id AS spid,
 resource_type AS restype,
 resource_database_id AS dbid,
 resource_description AS res,
 resource_associated_entity_id AS resid,
 request_mode AS mode,
 request_status AS status
FROM sys.dm_tran_locks;

-- 4.2
/*
Esta query retorna as sessões bloqueasdas no momento
*/
SELECT -- use * to explore
 session_id AS spid, -- session ID (SPID)
 blocking_session_id,
 command,
 sql_handle,
 database_id,
 wait_type,
 wait_time,
 wait_resource
FROM sys.dm_exec_requests
WHERE blocking_session_id > 0;

--4.3
/*
Esta query retorna o ID da sessão bloqueada e a respetiva instrução
*/
SELECT session_id, text
FROM sys.dm_exec_connections
 CROSS APPLY sys.dm_exec_sql_text(most_recent_sql_handle) AS ST
WHERE session_id IN (58, 51, 73);

-- 4.4
EXEC sp_who2

/*Terminar o processo bloqueado*/
KILL 51