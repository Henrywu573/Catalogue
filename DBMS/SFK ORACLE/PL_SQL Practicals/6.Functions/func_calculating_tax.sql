CREATE OR REPLACE FUNCTION 
tax(p_sal number) return number
 as
        v_tax number(8,2) :=0;
    
 BEGIN
       
        if p_sal between 0 and 2000 then
        v_tax := p_sal * 0.10;
    
        elsif p_sal between 2001 and 4000 then
        v_tax := p_sal *0.15;
           
        else 
        v_tax := p_sal * 0.25;
        end if;
        return v_tax;
 END;
