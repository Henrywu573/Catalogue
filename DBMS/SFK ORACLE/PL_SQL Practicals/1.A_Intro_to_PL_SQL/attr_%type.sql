 Declare
          v_name      emp.ename%type;
          v_job       emp.job%type;
          v_sal       emp.sal%type;
 Begin
         select ename,job,sal
         into   v_name, v_job, v_sal
         from emp
         where empno =7902;
         dbms_output.put_line(v_name||v_job||v_sal);
 End;
/
