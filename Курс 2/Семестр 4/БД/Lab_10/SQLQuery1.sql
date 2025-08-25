USE UNIVER;

--1
EXEC SP_HELPINDEX 'AUDITORIUM';
EXEC SP_HELPINDEX 'AUDITORIUM_TYPE';
EXEC SP_HELPINDEX 'FACULTY';
EXEC SP_HELPINDEX 'Group1';
EXEC SP_HELPINDEX 'Group2';
EXEC SP_HELPINDEX 'GROUPS';
EXEC SP_HELPINDEX 'PROFESSION';
EXEC SP_HELPINDEX 'PROGRESS';
EXEC SP_HELPINDEX 'PULPIT';
EXEC SP_HELPINDEX 'STUDENT';
EXEC SP_HELPINDEX 'SUBJECT';
EXEC SP_HELPINDEX 'TEACHER';

CREATE table #EXPLRE
(   
	NUMBER int,
	FIELD varchar(100)
);

SET nocount on;
DECLARE @i int = 1;
WHILE @i <= 1000
begin
	INSERT #EXPLRE(NUMBER, FIELD)
		VALUES(@i, 'строка №' + CAST(@i as varchar(10)))
	SET @i = @i + 1;
end;

SELECT *
FROM #EXPLRE where NUMBER between 950 and 1000 order by NUMBER

checkpoint;
DBCC DROPCLEANBUFFERS;

CREATE clustered index #EXPLRE_CL on #EXPLRE(NUMBER asc)


--2
CREATE table #EX
(    
	TKEY int, 
    CC int identity(1, 1),
    TF varchar(100)
);

set nocount on;           
declare @i int = 0;
while   @i < 20000       -- добавление в таблицу 20000 строк
begin
	INSERT #EX(TKEY, TF) values(floor(30000*RAND()), replicate('строка ', 10));
    set @i = @i + 1; 
end;

SELECT count(*)[количество строк] from #EX;
SELECT * from #EX

CREATE index #EX_NONCLU on #EX(TKEY, CC)

SELECT * from  #EX where  TKEY > 1500 and  CC < 4500;  
SELECT * from  #EX order by  TKEY, CC

SELECT * from  #EX where  TKEY = 556 and  CC > 3


--3
CREATE  index #EX_TKEY_X on #EX(TKEY) INCLUDE (CC)
SELECT CC from #EX where TKEY>15000


--4
SELECT TKEY from  #EX where TKEY between 5000 and 19999; 
SELECT TKEY from  #EX where TKEY>15000 and  TKEY < 20000  
SELECT TKEY from  #EX where TKEY=17000

CREATE  index #EX_WHERE on #EX(TKEY) where (TKEY>=15000 and 
 TKEY < 20000);


--5
CREATE   index #EX_TKEY ON #EX(TKEY);

USE tempdb;
SELECT name [Индекс], avg_fragmentation_in_percent [Фрагментация (%)]
FROM sys.dm_db_index_physical_stats(DB_ID(N'TEMPDB'), 
OBJECT_ID(N'#EX'), NULL, NULL, NULL) ss  JOIN sys.indexes ii on ss.object_id = ii.object_id and ss.index_id = ii.index_id  WHERE name is not null;

INSERT top(10000) #EX(TKEY, TF) select TKEY, TF from #EX;

ALTER index #EX_TKEY on #EX reorganize;

ALTER index #EX_TKEY on #EX rebuild with (online = off);


--6
DROP index #EX_TKEY on #EX;
CREATE index #EX_TKEY on #EX(TKEY) with (fillfactor = 65);

INSERT top(50)percent INTO #EX(TKEY, TF)
SELECT TKEY, TF  FROM #EX;

USE tempdb;
SELECT name [Индекс], avg_fragmentation_in_percent [Фрагментация (%)]
FROM sys.dm_db_index_physical_stats(DB_ID(N'TEMPDB'),    
OBJECT_ID(N'#EX'), NULL, NULL, NULL) ss  JOIN sys.indexes ii 
ON ss.object_id = ii.object_id and ss.index_id = ii.index_id  WHERE name is not null;
