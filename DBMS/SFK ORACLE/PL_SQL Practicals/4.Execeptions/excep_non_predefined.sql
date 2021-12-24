 declare
            exp_intigrity exception;
            pragma exception_init
            (exp_intigrity, -02292);
 begin
       delete from dept where deptno=&deptno;
 exception
       when exp_intigrity then
       dbms_output.put_line(' cant delete dept records, child records exist ');
       when others then
       dbms_output.put_line(' Some Error Occured ');
 end;
/
