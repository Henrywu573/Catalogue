 Declare
       TYPE emp_rec is RECORD
          ( name varchar2(20),
            hiredate date,
            sal  number(7)
           );
      v_emp emp_rec;
 BEGIN
      select ename, hiredate, sal into v_emp
      from emp
      where empno=&Emp_No;
      dbms_output.put_line(v_emp.name||' '||v_emp.sal||' '||v_emp.hiredate);
 END;

