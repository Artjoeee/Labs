USE UNIVER;

--1
DECLARE @sub char(20), @s char(300) = '';
DECLARE Subjects CURSOR
					for SELECT SUBJECT FROM SUBJECT
					WHERE PULPIT = 'ISIT';
	OPEN Subjects;
	FETCH Subjects into @sub;
	PRINT 'Дисциплины: ';
	WHILE @@FETCH_STATUS = 0
		begin
			SET @s = RTRIM(@sub) + ',' + @s;
			FETCH Subjects INTO @sub;
		end;
	PRINT @s;
CLOSE Subjects;

--2

DECLARE Birth CURSOR LOCAL                            
	             for SELECT NAME, BDAY from STUDENT;
DECLARE @name char(30), @bday date;      
	OPEN Birth;	  
	fetch Birth into @name, @bday; 	
    print '1. '+ @name + cast(@bday as varchar(6));   
    go
 DECLARE @name char(30), @bday date;     	
	fetch  Birth into @name, @bday; 	
    print '2. '+ @name + cast(@bday as varchar(6));


DECLARE Birth CURSOR GLOBAL                           
	             for SELECT NAME, BDAY from STUDENT;
DECLARE @name char(30), @bday date;      
	OPEN Birth;	  
	fetch Birth into @name, @bday; 	
    print '1. '+ @name + cast(@bday as varchar(12));   
    go
 DECLARE @name char(30), @bday date;     	
	fetch  Birth into @name, @bday; 	
    print '2. '+ @name + cast(@bday as varchar(12));
	CLOSE Birth;
	DEALLOCATE Birth;


--3
DECLARE @id char(30), @fio char(40);  
	DECLARE Students CURSOR LOCAL DYNAMIC                             
		 for SELECT IDSTUDENT, NAME
		       FROM dbo.STUDENT where IDGROUP = 10;				   
	OPEN Students;
	PRINT 'Количество строк : '+cast(@@CURSOR_ROWS as varchar(5)); 
	UPDATE STUDENT SET NAME = 'Zhamoida Artsiom Igorevich' where IDSTUDENT = 1036;
	DELETE STUDENT where IDSTUDENT = 1037; 
	FETCH Students into @id, @fio;    
	while @@fetch_status = 0                                    
      begin 
          PRINT @id + ' '+ @fio;      
          FETCH Students into @id, @fio; 
       end;          
   CLOSE Students;


--4
DECLARE @num int, @fio1 char(40);  
	DECLARE Students CURSOR LOCAL DYNAMIC SCROLL                            
		 for SELECT ROW_NUMBER() OVER (ORDER BY NAME) N, NAME
		       FROM dbo.STUDENT where IDGROUP = 16;				   
	OPEN Students;
		FETCH Students into  @num, @fio1;
		print 'Следующая строка: ' + cast(@num as varchar(3))+ ') ' + rtrim(@fio1);
		FETCH FIRST from  Students into @num, @fio1;
		print 'Первая строка: ' +  cast(@num as varchar(3))+ ') ' + rtrim(@fio1);
		FETCH NEXT from  Students into @num, @fio1;
		print 'Следующая строка за текущей: ' +  cast(@num as varchar(3))+ ') ' + rtrim(@fio1);
		FETCH PRIOR from  Students into @num, @fio1;
		print 'Предыдущая строка от текущей: ' +  cast(@num as varchar(3))+ ') ' + rtrim(@fio1);
		FETCH ABSOLUTE 3 from  Students into @num, @fio1;
		print 'Третья строка от начала: ' +  cast(@num as varchar(3))+ ') ' + rtrim(@fio1);
		FETCH RELATIVE 2 from  Students into @num, @fio1;
		print 'Вторая строка вперед от текущей: ' +  cast(@num as varchar(3))+ ') ' + rtrim(@fio1);
		FETCH LAST from  Students into @num, @fio1;      
		print 'Последняя строка: ' +  cast(@num as varchar(3))+ ') ' + rtrim(@fio1);
	CLOSE Students;


--5
DECLARE @id1 char(30), @fio2 char(40);  
	DECLARE Students CURSOR LOCAL DYNAMIC SCROLL                             
		 for SELECT IDSTUDENT, NAME
		       FROM dbo.STUDENT FOR UPDATE;				   
	OPEN Students;
		FETCH STUDENTS INTO @id1, @fio2;
		UPDATE STUDENT SET NAME = 'Zhamoida Artur Igorevich' WHERE CURRENT OF Students;
		FETCH LAST FROM Students into @id1, @fio2;
		DELETE STUDENT WHERE CURRENT OF Students;          
	CLOSE Students;


--6
DECLARE @id2 char(30), @fio3 char(40);  
	DECLARE Students CURSOR LOCAL DYNAMIC                             
		 for SELECT S.IDSTUDENT, NOTE
		       FROM dbo.STUDENT S INNER JOIN dbo.PROGRESS P
			   ON S.IDSTUDENT = P.IDSTUDENT
			   INNER JOIN GROUPS G
			   ON S.IDGROUP = G.IDGROUP;				   
	OPEN Students; 
	FETCH Students into @id2, @fio3;    
	while @@fetch_status = 0                                    
      begin
          PRINT @id2 + ' '+ @fio3;      
          FETCH Students into @id2, @fio3;
		  DELETE PROGRESS WHERE NOTE < 4
       end;          
	CLOSE Students;


DECLARE @id3 char(30), @fio4 char(40);  
	DECLARE Students CURSOR LOCAL DYNAMIC                             
	for SELECT IDSTUDENT, NOTE
		       FROM dbo.PROGRESS;				   
	OPEN Students; 
	UPDATE PROGRESS SET NOTE = NOTE + 1 where IDSTUDENT = 1002; 
	FETCH Students into @id3, @fio4;    
	while @@fetch_status = 0                                    
      begin 
          PRINT @id3 + ' '+ @fio4;      
          FETCH Students into @id3, @fio4; 
       end;          
   CLOSE Students;
