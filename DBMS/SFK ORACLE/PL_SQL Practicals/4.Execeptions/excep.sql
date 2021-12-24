declare
             e emp%rowtype;
BEGIN
           select * into e from emp
           where empno=&empno;
exception
        when no_data_found then
        dbms_output.put_line(' So such Emp Exist ');
        when invalid_column_name then
        dbms_output.put_line(' Datatype mismatch ');
        when others then
        dbms_output.put_line(' some error occured ');
end;
/
