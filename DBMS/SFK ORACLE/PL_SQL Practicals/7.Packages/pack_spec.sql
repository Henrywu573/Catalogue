create or replace package my_pack is
 FUNCTION   get_annsal(p_id number)return number;
 FUNCTION   tax(p_id number)return number;
 PROCEDURE  get_emp(p_eno in number,
                    p_name out varchar2,
                    p_job out varchar2,
                    p_sal out number);
end my_pack;
/
