 CREATE OR REPLACE package body my_pack
 is
   /* GET_ANNSAL FUNCTION */
  FUNCTION get_annsal(p_id number)
  return number
  as
         v_salary emp.sal%type;
  BEGIN
         select sal*12 into v_salary from emp
         where empno = p_id;
         return v_salary;
  END;
   /* TAX FUNCTION */
  FUNCTION tax(p_id number)
  return number
  as
         v_tax number(8,2) :=0;
         v_salary number(6);
  BEGIN
         select sal*12 into v_salary from emp
         where empno=p_id;
         if v_salary between 0 and 2000 then
         v_tax := v_salary * 0.10;
         elsif v_Salary between 2001 and 4000 then
         v_tax := v_salary *0.15;
         else
         v_tax := v_salary * 0.25;
         end if;
         return v_tax;
  END;
  /* GET_EMP */
  PROCEDURE get_emp(p_eno in number,
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
 end my_pack;

