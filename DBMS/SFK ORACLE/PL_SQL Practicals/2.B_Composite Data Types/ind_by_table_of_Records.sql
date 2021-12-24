 Declare
  Type type_dept is TABLE of dept%rowtype
  index by binary_integer;
       v_dept type_dept;   
       dno number :=10;
  BEGIN
        FOR i in 1..4 
         LOOP
      	     select * into v_dept(i) 
             from dept 
             where deptno = dno;
             dno:=dno+10;  
      END LOOP;
     FOR i in 1..4
      LOOP
dbms_output.put_line(v_dept(i).deptno 
 ||' '||v_dept(i).dname||' '||v_dept(i).loc);
      END LOOP;      
END;

