create or replace package body operation
is
    function add(x number, y number) return number
    is
             v_ans number;
    Begin
             v_ans := x + y;
             return v_ans;
    End;
    function add(x varchar2, y varchar2) return varchar2
    is
            v_ans varchar2(40);
    Begin
            v_ans := x||y;
            return v_ans;
    End;
    function add(x date, y number) return date
    is
        v_ans date;
    Begin
            v_ans := x + y;
            return v_ans;
    End;
end operation;
/
