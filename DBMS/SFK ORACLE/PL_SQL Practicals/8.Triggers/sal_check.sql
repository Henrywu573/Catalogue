create or replace trigger sal_check
before update 
on emp
for each row
begin
         if :new.sal < :old.sal then
         raise_application_error(-20006,'You Cannot Decrease an emp''s Sal');
         end if;
End;

