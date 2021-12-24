declare 
      cursor c1 is
      select empno,job from emp;

BEGIN
  for empcur in c1   --auto open and fetch
  LOOP 
   dbms_output.put_line 
   (empcur.empno||' '||empcur.job);
  END LOOP; -- auto close
END;






