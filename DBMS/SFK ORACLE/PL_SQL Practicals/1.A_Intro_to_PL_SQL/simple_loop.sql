Declare
          v_dno number(2) :=51;
          v_name dept.dname%type :='IT';
          v_loc  dept.loc%type :='HYD';
BEGIN
 LOOP
  insert into dept values(v_dno,v_name,v_loc);
  exit when v_dno > 55;
  v_dno := v_dno + 1;    
 END LOOP;
END;

