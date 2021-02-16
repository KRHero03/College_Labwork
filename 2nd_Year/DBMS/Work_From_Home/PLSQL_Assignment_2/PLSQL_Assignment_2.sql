set serveroutput on size 30000;

CREATE TABLE EMP(
    EmpNo NUMBER(4) PRIMARY KEY,
    Ename VARCHAR(30),
    Job VARCHAR(15),
    Sal NUMBER(8,2),
    DeptNo NUMBER(2),
    Commision NUMBER(7,2));
    
INSERT INTO EMP VALUES (101, 'Lisa', 'Clerk', 20000.00, 10, 550.00);
INSERT INTO EMP VALUES (102, 'Jennifer', 'Analyst', 50000.00, 10, 500.00);
INSERT INTO EMP VALUES (103, 'Joseph', 'Senior Analyst', 70000.00, 10, 600.00);
INSERT INTO EMP VALUES (104, 'David', 'Scientist', 70000.00, 20, 550.00);
INSERT INTO EMP VALUES (105, 'Mathew', 'Clerk', 20000.00, 20, 550.00);
INSERT INTO EMP VALUES (106, 'Amit', 'Programmer', 55000.00, 30, 600.00);

DECLARE   
    cEName EMP.Ename%TYPE;
    cEmpNo EMP.Empno%TYPE;
    cJob EMP.Job%TYPE;
    CURSOR cur IS 
        SELECT Empno,Ename,Job FROM EMP WHERE EMP.deptno=10; 
BEGIN 
    OPEN cur;
    LOOP
    FETCH cur INTO cEmpNo,cEName,cJob;
        EXIT WHEN cur%NOTFOUND;
        DBMS_OUTPUT.put_line(cEmpNo||'         '||cEName||'         '||cJob);
    END LOOP;
    CLOSE cur;
END; 
/ 

DECLARE
    CURSOR cur IS SELECT * FROM EMP;
BEGIN
    UPDATE EMP
        SET EMP.sal =
            CASE 
                WHEN Emp.deptno=10 THEN Emp.sal + 1000
                WHEN Emp.deptno=20 THEN Emp.sal + 500
                WHEN Emp.deptno=30 THEN Emp.sal + 800
            END;
    FOR rec in cur
    LOOP
        DBMS_OUTPUT.put_line(rec.empno || '        ' || rec.ename || '        ' || rec.job || '        ' || rec.sal || '        ' || rec.sal || '        ' || rec.commision);
    END LOOP;
    
END;
/

DECLARE
    CURSOR cur IS 
        SELECT Ename FROM EMP WHERE EMP.sal<50000; 
BEGIN 
    FOR rec in cur
    LOOP
    DBMS_OUTPUT.put_line(rec.ename);
    END LOOP;
END; 
/ 

DECLARE
BEGIN 
    UPDATE EMP
        SET EMP.sal =
            CASE 
                WHEN Emp.deptno=10 THEN Emp.sal + 1000
                WHEN Emp.deptno=20 THEN Emp.sal + 500
                WHEN Emp.deptno=30 THEN Emp.sal + 800
            END;
    DBMS_OUTPUT.put_line(SQL%ROWCOUNT||' Rows affected!');
END; 
/ 
