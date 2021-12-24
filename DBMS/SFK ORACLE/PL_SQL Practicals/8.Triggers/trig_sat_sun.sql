create or replace trigger sun_trig
BEFORE INSERT OR UPDATE OR DELETE
ON EMP
DECLARE
         d varchar2(3);
         t number(2);
BEGIN
         d :=to_char(sysdate,'DY');
         t := to_char(sysdate, 'HH24');
 if d in ('SAT','SUN')  OR  t NOT between 09 AND 18 then
        raise_application_error
(-20005, ' Today is  Saturday / Sunday. Transactions      are not allowed on weekends. ');
end if;
end;
