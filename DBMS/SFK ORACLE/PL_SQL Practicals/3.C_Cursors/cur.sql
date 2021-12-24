declare
 v_ename varchar2(10); 
 v_job varchar2(10);     
 v_sal number(4);       
 cursor c1 is
 select ename,job,sal from emp;--Declareing Cursor
BEGIN
 openc1; -- Opening Cursor.
 loop
   fetch c1 into v_ename,v_job, v_sal;--Fetching
   exit when c1%notfound;
   dbms_output.put_line(v_ename||' '||v_job||' '||v_sal);
 end loop;
 close c1;    --Closing.
end;





