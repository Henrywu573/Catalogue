Declare
          v_sal       Number(7,2);
Begin
 select sum(sal)
 INTO  v_sal
 from emp
 where deptno = &deptno;
 dbms_output.put_line('The Sum of Sal is '||v_sal);
End;

