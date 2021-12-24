 Declare
       Type t_name is TABLE of VARCHAR2(20)
       index by binary_integer;
       
       v_name t_name;   
       dno number :=10;
 
 BEGIN
      
      FOR i in 1..4
      LOOP
      	     select dname into v_name(i) 
             from dept 
             where deptno = dno; 
             dno:=dno+10;
      END LOOP;
     
      FOR i in 1..4 
      LOOP
         dbms_output.put_line(v_name(i));
      END LOOP;      
END;

