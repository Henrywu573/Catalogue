declare
 cursor c1(dno number) is
      select ename,sal from emp where deptno=dno;
 empcur c1%rowtype;
BEGIN
 open c1(&dno);
 loop
   fetch c1 into empcur;
   exit when c1%notfound;
   dbms_output.put_line(empcur.ename||' '||empcur.sal);
 end loop;
 close c1;
end;

