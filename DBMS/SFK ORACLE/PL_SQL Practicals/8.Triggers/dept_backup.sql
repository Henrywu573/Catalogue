create or replace trigger dept_backup
before delete 
on dept
for each row
Begin
      insert into dept_backup values
      (:old.deptno, :old.dname, :old.loc);
end;

