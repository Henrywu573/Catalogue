CREATE OR REPLACE FUNCTION                             get_annsal(p_id number) return number
 as
        v_salary number(10);
 BEGIN
        select sal*12 into v_salary from emp
        where empno = p_id;
        return v_salary;
 END;
