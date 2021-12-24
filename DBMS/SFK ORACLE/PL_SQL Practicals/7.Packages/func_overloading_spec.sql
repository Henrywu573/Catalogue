create or replace package operation
is
 function add(x number, y number) return number;
 function add(x varchar2, y varchar2) return varchar2;
 function add(x date, y number) return date;
end operation;
