set serveroutput on size 30000;

CREATE OR REPLACE PROCEDURE factorial(n IN NUMBER, fact OUT NUMBER)
IS 
BEGIN
    fact := 1;
    fOR i IN 1..n
    LOOP
        fact := fact * i;
    END LOOP;
END; 
/

DECLARE
    n NUMBER := &n;
    fact NUMBER := 0;
BEGIN
    factorial(n,fact);
    dbms_output.put_line('The factorial of '||n||' is '||fact||'!');
END;
/

CREATE OR REPLACE PROCEDURE getGrade(score IN NUMBER, grade OUT VARCHAR)
IS 
BEGIN
    IF score > 100 OR score < 0 THEN
        grade := 'NULL';
    ELSIF score >= 75 THEN
        grade := 'A';
    ELSIF score >= 50 THEN
        grade := 'B';
    ELSIF score >= 25 THEN
        grade := 'C';
    ELSE
        grade := 'D';
    END IF;
    
END; 
/

DECLARE
    score NUMBER := &score;
    grade VARCHAR(5) := 'NULL';
BEGIN
    getGrade(score,grade);
    dbms_output.put_line('Given Score: '||score);
    dbms_output.put_line('Obtained Grade: '||grade);
END;
/

CREATE TABLE EMPLOYEE(
    ID INTEGER PRIMARY KEY,
    NAME VARCHAR(50),
    DEPT_NO NUMBER,
    SALARY NUMBER(7,2));
    
INSERT INTO EMPLOYEE VALUES(101,'MARK',10,5000.0);
INSERT INTO EMPLOYEE VALUES(102,'DUG',10,5500.0);
INSERT INTO EMPLOYEE VALUES(103,'ALAN',20,6000.0);
INSERT INTO EMPLOYEE VALUES(104,'PETER',30,6200.0);

CREATE OR REPLACE FUNCTION totalRows 
RETURN number IS 
   total number(2) := 0; 
BEGIN 
   SELECT count(*) into total 
   FROM EMPLOYEE;     
   RETURN total; 
END; 
/ 

CREATE OR REPLACE FUNCTION highestSalary
RETURN VARCHAR IS
    nameR VARCHAR(50):= '';
BEGIN
    SELECT NAME INTO nameR 
    FROM EMPLOYEE 
    WHERE SALARY = (SELECT MAX(SALARY) FROM EMPLOYEE);
    RETURN nameR;
END;
/

DECLARE
    p NUMBER;
    nameR VARCHAR(50);
BEGIN
    p := totalRows;
    nameR := highestSalary;
    dbms_output.put_line('Total Rows in Employee: '||p);
    dbms_output.put_line('Employee with Highest Salary: '||nameR);
END;
/