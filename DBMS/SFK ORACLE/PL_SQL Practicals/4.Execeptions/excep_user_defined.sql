
  begin
        update emp
        set sal = &sal
        where lower(ename)='&name';
      
  end;
/
