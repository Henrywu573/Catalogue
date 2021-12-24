create or replace procedure get_emp
                       (p_eno in number,
                         p_name out varchar2,
                         p_job out varchar2,
                         p_sal out number
                        )
is
begin
        select ename, job, sal  into
        p_name,p_job, p_sal from emp
        where empno = p_eno;
end;

