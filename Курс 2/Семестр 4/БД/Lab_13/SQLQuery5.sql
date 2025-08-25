USE UNIVER;

GO
create procedure SUBJECT_REPORT  @p CHAR(10)
   as  
   declare @rc int = 0;                            
   begin try    
      declare @sb char(20), @t char(300) = ' ';  
      declare SUB CURSOR  for 
      select SUBJECT from SUBJECT where PULPIT = @p;
      if not exists (select SUBJECT 
		from SUBJECT where PULPIT = @p)
            raiserror(N'������', 11, 1);
       else 
        open SUB;	  
    fetch  SUB into @sb;   
    print   '����������: ';   
    while @@fetch_status = 0                                     
    begin 
         set @t = rtrim(@sb) + ', ' + @t;  
         set @rc = @rc + 1;       
         fetch  SUB into @sb; 
     end;   
print @t;        
close  SUB;
    return @rc;
   end try  
   begin catch              
        print N'������ � ����������' 
        if error_procedure() is not null   
			print N'��� ��������� : ' + error_procedure();
        return @rc;
end catch; 
GO

DECLARE @rc int;  
exec @rc = SUBJECT_REPORT @p  = 'ISIT';  
print '���������� ��������� = ' + cast(@rc as varchar(3)); 
