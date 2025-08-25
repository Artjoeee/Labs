USE UNIVER;

-- 1
GO
CREATE TABLE TR_AUDIT
(
	ID int identity,
	STMT varchar(20) check (STMT in ('INS', 'DEL', 'UPD')),
	TRNAME varchar(50),
	CC varchar(300)
)
GO

CREATE TRIGGER TR_TEACHER_INS 
ON TEACHER AFTER INSERT
AS DECLARE @a1 varchar(20), @a2 varchar(60), @a3 varchar(1), @a4 varchar(60), @in varchar(300);
PRINT 'Operation insert'
SET @a1 =(SELECT [teacher] from INSERTED);
SET @a2 =(SELECT [TEACHER_NAME] from INSERTED);
SET @a3 =(SELECT [GENDER] from INSERTED);
SET @a4 =(SELECT [PULPIT] from INSERTED);
SET @in=@a1 +' ' +@a2 +' '+@a3 +' '+@a4
INSERT INTO TR_AUDIT (STMT, TRNAME, CC) VALUES ('INS', ' TR_TEACHER_INS', @in);
return;

INSERT INTO TEACHER VALUES ('ZAI','Zhamoida Artiom Igorevich','M','ISIT')
SELECT * FROM TR_AUDIT



-- 2
GO
CREATE TRIGGER TR_TEACHER_DEL 
ON TEACHER AFTER DELETE
AS DECLARE @a1 varchar(20), @a2 varchar(60), @a3 varchar(1), @a4 varchar(60), @in varchar(300);
PRINT 'Operation delete'
SET @a1 =(SELECT [teacher] from deleted);
SET @a2 =(SELECT [TEACHER_NAME] from deleted);
SET @a3 =(SELECT [GENDER] from deleted);
SET @a4 =(SELECT [PULPIT] from deleted);
SET @in=@a1 +' ' +@a2 +' '+@a3 +' '+@a4
INSERT INTO TR_AUDIT (STMT, TRNAME, CC) VALUES ('DEL', ' TR_TEACHER_DEL', @in);
RETURN;

DELETE TEACHER WHERE TEACHER.TEACHER='ZAI'
SELECT * FROM TR_AUDIT



-- 3
GO
CREATE TRIGGER TR_TEACHER_UPD 
ON TEACHER AFTER UPDATE
AS DECLARE @a1 varchar(20),@a2 varchar(60),@a3 varchar(1),@a4 varchar(60),@in varchar(300);
PRINT 'Operation update'
SET @a1 =(SELECT [teacher] FROM inserted);
SET @a2 =(SELECT [TEACHER_NAME] FROM inserted);
SET @a3 =(SELECT [GENDER] FROM inserted);
SET @a4 =(SELECT[PULPIT] FROM inserted);
SET @in=@a1 +' ' +@a2 +' '+@a3 +' '+@a4
SET @a1 =(SELECT [teacher] FROM deleted);
SET @a2 =(SELECT [TEACHER_NAME] FROM deleted);
SET @a3 =(SELECT [GENDER] FROM deleted);
SET @a4 =(SELECT [PULPIT] FROM deleted);
SET @in=@a1 +' ' +@a2 +' '+@a3 +' '+@a4+@in
insert into TR_AUDIT (STMT,TRNAME,CC) values ('UPD',' TR_TEACHER_UPD',@in);
return;

INSERT INTO TEACHER VALUES ('ZMI','Zhamoida Artiom Igorevich','M','ISIT')
UPDATE TEACHER SET TEACHER.TEACHER='ZHUM' where TEACHER.TEACHER='ZAI'
SELECT * FROM TR_AUDIT



-- 4
GO
CREATE TRIGGER TR_TEACHER 
ON TEACHER AFTER INSERT, DELETE, UPDATE  
AS DECLARE @a1 varchar(20),@a2 varchar(60),@a3 varchar(1),@a4 varchar(60),@in varchar(300);
DECLARE @ins int = (SELECT count(*) FROM inserted),
              @del int = (SELECT count(*) FROM deleted); 
if  @ins > 0 and  @del = 0 
BEGIN
	PRINT 'Operation insert'
	SET @a1 =(SELECT [teacher] from INSERTED);
	SET @a2 =(SELECT [TEACHER_NAME] from INSERTED);
	SET @a3 =(SELECT [GENDER] from INSERTED);
	SET @a4 =(SELECT [PULPIT] from INSERTED);
	SET @in=@a1 +' ' +@a2 +' '+@a3 +' '+@a4
	INSERT INTO TR_AUDIT (STMT, TRNAME, CC) VALUES ('INS', ' TR_TEACHER_INS', @in);
END
ELSE
if 
@ins = 0 and  @del > 0  
BEGIN
	PRINT 'Operation delete'
	SET @a1 =(SELECT [teacher] from deleted);
	SET @a2 =(SELECT [TEACHER_NAME] from deleted);
	SET @a3 =(SELECT [GENDER] from deleted);
	SET @a4 =(SELECT [PULPIT] from deleted);
	SET @in=@a1 +' ' +@a2 +' '+@a3 +' '+@a4
	INSERT INTO TR_AUDIT (STMT, TRNAME, CC) VALUES ('DEL', ' TR_TEACHER_DEL', @in);
END
ELSE 
if @ins > 0 and  @del > 0  
BEGIN
	PRINT 'Operation update'
	SET @a1 =(SELECT [teacher] FROM inserted);
	SET @a2 =(SELECT [TEACHER_NAME] FROM inserted);
	SET @a3 =(SELECT [GENDER] FROM inserted);
	SET @a4 =(SELECT[PULPIT] FROM inserted);
	SET @in=@a1 +' ' +@a2 +' '+@a3 +' '+@a4
	SET @a1 =(SELECT [teacher] FROM deleted);
	SET @a2 =(SELECT [TEACHER_NAME] FROM deleted);
	SET @a3 =(SELECT [GENDER] FROM deleted);
	SET @a4 =(SELECT [PULPIT] FROM deleted);
	SET @in=@a1 +' ' +@a2 +' '+@a3 +' '+@a4+@in
	insert into TR_AUDIT (STMT,TRNAME,CC) values ('UPD',' TR_TEACHER_UPD',@in);
END
RETURN;

INSERT INTO TEACHER VALUES ('APZ','Artiom Igorevich Zhamoida','M','ISIT')
UPDATE TEACHER SET TEACHER.TEACHER='IVZ' WHERE TEACHER.TEACHER='AIZ'
DELETE TEACHER WHERE TEACHER.TEACHER='IAZ'
SELECT * FROM TR_AUDIT
GO



-- 5
ALTER TABLE TEACHER ADD CONSTRAINT CHK_TEACHER_LENGTH CHECK (len(TEACHER.TEACHER)<=3)
GO
INSERT INTO TEACHER VALUES ('PAS','Pinchuk Alexandr Sergeevich','M','ISIT')
UPDATE TEACHER SET TEACHER.TEACHER='PASSS' WHERE TEACHER.TEACHER='PAS'



-- 6
GO

CREATE TRIGGER TR_TEACHER_DEL1 
ON TEACHER AFTER DELETE
AS DECLARE @a1 varchar(20), @a2 varchar(60), @a3 varchar(1), @a4 varchar(60), @in varchar(300);
PRINT 'Operation delete'
SET @a1 =(SELECT [teacher] from deleted);
SET @a2 =(SELECT [TEACHER_NAME] from deleted);
SET @a3 =(SELECT [GENDER] from deleted);
SET @a4 =(SELECT [PULPIT] from deleted);
SET @in=@a1 +' ' +@a2 +' '+@a3 +' '+@a4
INSERT INTO TR_AUDIT (STMT, TRNAME, CC) VALUES ('DEL', ' TR_TEACHER_DEL1', @in);
RETURN;
GO

CREATE TRIGGER TR_TEACHER_DEL2 
ON TEACHER AFTER DELETE
AS DECLARE @a1 varchar(20), @a2 varchar(60), @a3 varchar(1), @a4 varchar(60), @in varchar(300);
PRINT 'Operation delete'
SET @a1 =(SELECT [teacher] from deleted);
SET @a2 =(SELECT [TEACHER_NAME] from deleted);
SET @a3 =(SELECT [GENDER] from deleted);
SET @a4 =(SELECT [PULPIT] from deleted);
SET @in=@a1 +' ' +@a2 +' '+@a3 +' '+@a4
INSERT INTO TR_AUDIT (STMT, TRNAME, CC) VALUES ('DEL', ' TR_TEACHER_DEL2', @in);
RETURN;

GO

CREATE TRIGGER TR_TEACHER_DEL3 
ON TEACHER AFTER DELETE
AS DECLARE @a1 varchar(20), @a2 varchar(60), @a3 varchar(1), @a4 varchar(60), @in varchar(300);
PRINT 'Operation delete'
SET @a1 =(SELECT [teacher] from deleted);
SET @a2 =(SELECT [TEACHER_NAME] from deleted);
SET @a3 =(SELECT [GENDER] from deleted);
SET @a4 =(SELECT [PULPIT] from deleted);
SET @in=@a1 +' ' +@a2 +' '+@a3 +' '+@a4
INSERT INTO TR_AUDIT (STMT, TRNAME, CC) VALUES ('DEL', ' TR_TEACHER_DEL3', @in);
RETURN;

GO

SELECT t.name,e.type_desc
	FROM sys.triggers t join sys.trigger_events e
		ON t.object_id =e.object_id
			WHERE OBJECT_NAME(t.parent_id)='TEACHER' and
				e.type_desc ='DELETE'

EXEC SP_SETTRIGGERORDER @triggername='TR_TEACHER_DEL3', @order='First', @stmttype ='DELETE';
EXEC SP_SETTRIGGERORDER @triggername='TR_TEACHER_DEL2', @order='Last', @stmttype ='DELETE';

DELETE TEACHER WHERE TEACHER.TEACHER='ZAI'

SELECT * FROM TR_AUDIT



-- 7
SELECT * FROM TEACHER;

GO
CREATE TRIGGER TR_TEACHER_TRAN
ON TEACHER AFTER INSERT, DELETE, UPDATE
AS DECLARE @c int =(SELECT COUNT(TEACHER) FROM TEACHER);
if @c>18
BEGIN
	RAISERROR(N'Учитетелей меньше 18', 10, 1);
	ROLLBACK
END;
RETURN;

UPDATE TEACHER SET TEACHER = 'IZA' WHERE TEACHER='ZAI'

GO



-- 8
GO
CREATE TRIGGER TEACHER_INSTEAD_OF
ON TEACHER INSTEAD OF DELETE
AS RAISERROR(N'Удаление не поддерживается', 10, 1);
RETURN;

GO
DELETE TEACHER FROM TEACHER WHERE TEACHER='AIZ'
DROP TRIGGER TR_TEACHER_INS;
DROP TRIGGER TR_TEACHER_DEL;
DROP TRIGGER TR_TEACHER_UPD;
DROP TRIGGER TR_TEACHER;
DROP TRIGGER TR_TEACHER_DEL1
DROP TRIGGER TR_TEACHER_DEL2
DROP TRIGGER TR_TEACHER_DEL3
DROP TRIGGER TR_TEACHER_TRAN
DROP TRIGGER TEACHER_INSTEAD_OF



-- 9
DROP TRIGGER DDL_STUDENT ON DATABASE

GO
CREATE TRIGGER DDL_STUDENT ON DATABASE 
FOR DDL_DATABASE_LEVEL_EVENTS
AS
BEGIN
	DECLARE @t varchar(50) = EVENTDATA().value('(/EVENT_INSTANCE/EventType)[1]', 'varchar(50)');
	DECLARE @t1 varchar(50) = EVENTDATA().value('(/EVENT_INSTANCE/ObjectName)[1]', 'varchar(50)');
	DECLARE @t2 varchar(50) = EVENTDATA().value('(/EVENT_INSTANCE/ObjectType)[1]', 'varchar(50)'); 
	if @t1 = 'STUDENT' 
	BEGIN
		PRINT 'Type of event ' + @t;
		PRINT 'Name of object ' + @t1;
		PRINT 'Type of object ' + @t2;
		RAISERROR(N'Операции с таблицей STUDENT не поддерживаются', 16, 1);
		ROLLBACK;
	END;
END;
   
ALTER TABLE STUDENT DROP COLUMN FOTO;