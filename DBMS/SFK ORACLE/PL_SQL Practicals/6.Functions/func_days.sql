CREATE OR REPLACE FUNCTION 
  exp1(p_eno number) return number
as
        hdate date;
        e number;
BEGIN
        select hiredate into hdate
        from emp
        where empno = p_eno;
        e := months_between(sysdate, hdate) / 12;
        return round(e);
end;




