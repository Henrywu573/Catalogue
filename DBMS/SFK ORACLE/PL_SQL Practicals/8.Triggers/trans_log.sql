 create or replace trigger trans_type
 after insert or update or delete
 on emp
 declare
          ty varchar2(10);
 begin
          if INSERTING then
           ty:='I';
          elsif Updating then
           ty:='U';
          else
           ty:='D';
          End If;
  Insert into Trans_log Values(user,ty,sysdate,to_char(sysdate,'HH24:MM:SS'));
 End;
/
