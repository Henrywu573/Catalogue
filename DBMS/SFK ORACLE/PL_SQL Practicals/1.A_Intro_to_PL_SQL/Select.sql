Declare
         v_name      Char(20);  
         v_job       Varchar2(20); 
         v_sal       Number(4); 
Begin
        select ename,job,sal 
        into v_name, v_job, v_sal 
        from emp 
        where empno =7902; 
        dbms_output.put_line(v_name||v_job||v_sal);
End;
