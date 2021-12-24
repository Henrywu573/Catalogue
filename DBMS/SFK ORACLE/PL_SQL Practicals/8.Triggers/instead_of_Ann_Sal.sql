create or replace trigger sal_vu_trigger
instead of
insert or update or delete
on e
begin
       if Inserting then
         insert into emp(empno, ename, job,sal)
         values(:new.empno, :new.ename, :new.job, :new.sal);
   elsif DELETING then
         delete from emp
         where empno = :old.empno;       
   elsif UPDATING ('empno') then  
         update emp set empno = :new.empno 
        where empno = :old.empno; 
   elsif UPDATING ('ename') then
       update emp set ename = :new.ename 
      where empno = :old.empno;
  elsif UPDATING ('job') then
     update emp set job = :new.job 
    where empno = :old.empno;
 elsif UPDATING ('sal') then
   update emp set sal = :new.sal 
   where empno = :old.empno;
end if;
end;

