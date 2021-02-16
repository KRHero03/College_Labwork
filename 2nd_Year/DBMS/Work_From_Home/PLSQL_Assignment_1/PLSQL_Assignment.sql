set serveroutput on size 30000;
DECLARE   
 var1 varchar(40) := 'Hello World'; 
BEGIN 
 DBMS_OUTPUT.put_line(var1); 
END; 
/ 

DECLARE       
    LOW integer := &LOW ;    
    HIGH integer := &HIGH ;
BEGIN 
    IF LOW > HIGH THEN
        dbms_output.put_line('LOW CANNOT BE GREATER THAN HIGH!');
    ELSE
        dbms_output.put_line('Even Values from '||LOW||' and '||HIGH||':-');
        FOR p in LOW .. HIGH LOOP 
            IF MOD(p,2) = 0 THEN
                dbms_output.put_line(p); 
            END IF;
        END LOOP; 
    END IF;
END; 
/

DECLARE
    a INTEGER := &a;
    b INTEGER := 0;
    rem INTEGER;
BEGIN
    dbms_output.put_line('Given number: '||a);
    WHILE a > 0 LOOP
        rem := MOD(a,10);
        b := 10*b + rem;
        a := TRUNC(a/10);
    END LOOP;
    a := b;
    dbms_output.put_line('Reversed Number: '||a);
END;
/

DECLARE
    a INTEGER := &a;
    s INTEGER := 0;
    r INTEGER;
BEGIN
    dbms_output.put_line('Given number: '||a);
    WHILE a > 0 LOOP
        r := MOD(a,10);
        s := s + r;
        a := TRUNC(a/10);
    END LOOP;
    dbms_output.put_line('Sum of Digits of Number: '||s);
END;
/

DECLARE
    l INTEGER := 1;
    h INTEGER := 5;
    a NUMBER(8,2);
    pi constant number := 3.141592654; 
BEGIN
    FOR i IN l..h LOOP
        a := pi*i*i;
        dbms_output.put_line('Radius: '||i||' Area of Circle: '||a);        
    END LOOP;
END;
/

DECLARE
    a INTEGER := &a;
    b INTEGER := &b;
    c INTEGER := &c;
BEGIN
    dbms_output.put_line('Given numbers: '||a||' '||b||' '||c);
    IF a>b AND a>c THEN
        dbms_output.put_line(a||' is the greatest number!');
    ELSIF b>c THEN
        dbms_output.put_line(b||' is the greatest number!');    
    ELSE
        dbms_output.put_line(c||' is the greatest number!');    
    END IF;
END;
/