USE UNIVER;

GO
create procedure PAUDITORIUM_INSERTX
     @a char(20), @n varchar(50), @c int = 0, @t char(10),
	 @tn varchar(50)
as  declare @rc int=1;                            
begin try 
    set transaction isolation level SERIALIZABLE;          
    begin tran
    insert into AUDITORIUM_TYPE (AUDITORIUM_TYPE,AUDITORIUM_TYPENAME)
    values (@t,@tn);

  EXEC @rc = PAUDITORIUMINSERT @a, @n, @c, @t; 
    commit tran; 
    return @rc;           
end try
begin catch 
    print 'номер ошибки  : ' + cast(error_number() as varchar(6));
    print 'сообщение     : ' + error_message();
    print 'уровень       : ' + cast(error_severity()  as varchar(6));
    print 'метка         : ' + cast(error_state()   as varchar(8));
    print 'номер строки  : ' + cast(error_line()  as varchar(8));
    if error_procedure() is not  null   
                     print 'имя процедуры : ' + error_procedure();
     if @@trancount > 0 rollback tran ; 
     return -1;	  
end catch;
GO

DECLARE @rc int;  
EXEC @rc = PAUDITORIUM_INSERTX 
    @a = '100a-4', 
    @n = 'Laboratory', 
    @t = 'LB-KS', 
    @c = 30, 
    @tn = 'Computer Lab';
print 'code err=' + cast(@rc as varchar(3));  

drop procedure PAUDITORIUM_INSERTX
     
