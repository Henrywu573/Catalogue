Declare
         v_name      Char(20); 
         v_course    Varchar2(20); 
         v_duration  Number(3):= 30;
Begin
        v_name :='Sachin';
        v_course := 'Oracle';
        dbms_output.put_line(v_name);
        dbms_output.put_line(v_course);
        dbms_output.put_line(v_duration);  
End;
/
