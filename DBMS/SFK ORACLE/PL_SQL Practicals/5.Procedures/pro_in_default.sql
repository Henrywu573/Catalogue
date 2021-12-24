create or replace procedure add_dept
                     (p_dno in number default 10,
                      p_name in varchar2 default 'IT',
                      p_loc  in varchar2 default 'HYD')
as
begin
         insert into dept2 values(p_dno, p_name, p_loc);
end;

