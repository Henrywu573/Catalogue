DECLARE
 cursor empcur is 
  select * from emp;
 v_emp_cur empcur%rowtype;
 BEGIN
    OPEN empcur;
    LOOP
    Fetch empcur into v_emp_cur;
    EXIT When empcur%notfound;
  dbms_output.put_line('empno '||v_emp_cur.empno||' ename '||v_emp_cur.ename||' job '||v_emp_cur.job||' sal '||v_emp_cur.sal);
END LOOP;
dbms_output.put_line(empcur%rowcount||' records retrived');
CLOSE empcur; 
END;
/
