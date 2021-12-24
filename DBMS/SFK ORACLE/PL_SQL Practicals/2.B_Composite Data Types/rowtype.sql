 Declare
       e emp%rowtype;
 BEGIN
      select * into e from emp
      where empno=&Emp_No;      
      dbms_output.put_line(e.empno||' '||e.ename||' '||e.sal||' '||e.hiredate);
END;

