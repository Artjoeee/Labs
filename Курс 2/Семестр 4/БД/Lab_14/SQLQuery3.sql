create FUNCTION FSUBJECTS(@p varchar(20)) returns varchar(300) 
     as
     begin  
     declare @tv char(20);  
     declare @t varchar(300) = 'Дисциплины: ';  
     declare Sub CURSOR LOCAL 
     for select SUBJECT from SUBJECT 
		where PULPIT = @p;
     open Sub;	  
     fetch  Sub into @tv;   	 
     while @@fetch_status = 0                                     
     begin 
         set @t = @t + ', ' + rtrim(@tv);         
         FETCH  Sub into @tv; 
     end;    
     return @t;
     end;  
	 GO

select PULPIT,  dbo.FSUBJECTS 
(PULPIT)  from PULPIT;
