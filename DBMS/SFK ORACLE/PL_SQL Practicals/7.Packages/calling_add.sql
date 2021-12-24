declare
          a number;
          b varchar2(30);
          c date;
begin
         a := operation.add(23,3);
         dbms_output.put_line('the value of a is '||a);
         b :=operation.add('Active','Net');
         dbms_output.put_line('the value of b is '||b);
         c :=operation.add(sysdate,8);
         dbms_output.put_line('the value of c is '||c);
end;   
/
