CREATE TABLE EmployeeStatus(
    StatusName VARCHAR(1),
    PRIMARY KEY (StatusName)
);

CREATE TABLE Employee(
    EmpNo NUMBER(10),
    Emp_Name VARCHAR(255) NOT NULL,
    Emp_Join_Date DATE DEFAULT CURRENT_DATE,
    Emp_Status VARCHAR(1),
    PRIMARY KEY(EmpNo),
    FOREIGN KEY (Emp_Status) REFERENCES EmployeeStatus(StatusName)
);
    
CREATE TABLE Projects(
    Project_Code VARCHAR(20),
    Project_Description VARCHAR(500) NOT NULL UNIQUE,
    Project_Start_Date DATE DEFAULT CURRENT_DATE,
    Project_End_Date DATE,
    PRIMARY KEY(Project_Code)
);

CREATE TABLE Project_Allocation(
    Project_Code VARCHAR(20),
    EmpNo NUMBER(10),
    Emp_Proj_Alloc_Date DATE,
    Emp_Proj_Release_Date DATE,    
    FOREIGN KEY (Project_Code) REFERENCES Projects(Project_Code) ON DELETE CASCADE,
    FOREIGN KEY (EmpNo) REFERENCES Employee(EmpNo) ON DELETE CASCADE,
    PRIMARY KEY (Project_Code,EmpNo)
);
INSERT INTO EmployeeStatus VALUES('P');
INSERT INTO EmployeeStatus VALUES('C');
INSERT INTO EmployeeStatus VALUES('R');

INSERT INTO Employee VALUES('101','Jhonny','01-07-05','C');
INSERT INTO Employee VALUES('116','Nayak','16-08-05','C');
INSERT INTO Employee VALUES('202','Meera','30-01-06','C');
INSERT INTO Employee VALUES('205','Ravi','11-02-06','C');
INSERT INTO Employee VALUES('304','Hari','25-11-06','P');
INSERT INTO Employee VALUES('307','Nancy','15-01-07','P');
INSERT INTO Employee VALUES('403','Nick','21-01-07','P');

INSERT INTO Projects VALUES('P001','Environment Pollution','02-08-05','11-12-06');
INSERT INTO Projects VALUES('P002','Learning Curve','01-02-06','15-03-06');
INSERT INTO Projects VALUES('P003','Effects of IT','03-01-07',NULL);

INSERT INTO Project_Allocation VALUES('P001','101','01-08-2005','11-12-06');
INSERT INTO Project_Allocation VALUES('P001','116','16-08-2005','11-12-06');
INSERT INTO Project_Allocation VALUES('P002','202','01-02-2006','14-01-06');
INSERT INTO Project_Allocation VALUES('P002','307','15-01-2007',NULL);
INSERT INTO Project_Allocation VALUES('P002','205','11-02-2006',NULL);
INSERT INTO Project_Allocation VALUES('P003','403','21-01-2007',NULL);
INSERT INTO Project_Allocation VALUES('P003','304','03-01-2007',NULL);
INSERT INTO Project_Allocation VALUES('P003','101','03-01-2007',NULL);
INSERT INTO Project_Allocation VALUES('P003','116','03-01-2007',NULL);
INSERT INTO Project_Allocation VALUES('P003','202','15-01-2007',NULL);

SELECT Projects.Project_Description,Employee.Emp_Name FROM Project_Allocation,Employee,Projects WHERE Project_Allocation.Project_Code = Projects.Project_Code
    AND Employee.EmpNo = Project_Allocation.EmpNo;

SELECT Emp_Name FROM Employee WHERE Emp_Status='C';

SELECT Emp_Name FROM Employee WHERE EXTRACT(MONTH FROM Emp_Join_Date)=11;

SELECT Projects.Project_Description FROM Projects WHERE Project_End_Date>'01-01-2006'; 

SELECT Employee.Emp_Name FROM Project_Allocation NATURAL JOIN Employee NATURAL JOIN Projects WHERE Projects.Project_Description='Effects of IT';

SELECT Project_Description FROM Projects WHERE Project_End_Date is NULL;

SELECT Employee.Emp_Name FROM Project_Allocation NATURAL JOIN Employee WHERE Project_Code = 'P002' AND Emp_Proj_Release_Date IS NOT NULL;

SELECT Project_End_Date - Project_Start_Date FROM Projects WHERE Project_Code = 'P002';

SELECT Emp_Name,CASE WHEN Emp_Proj_Release_Date IS NOT NULL THEN
                    (Emp_Proj_Release_Date - Project_Allocation.Emp_Proj_Alloc_Date)
                ELSE
                    CASE WHEN Project_End_Date IS NULL THEN
                        (TO_DATE(SYSDATE,'DD-MM-YY') - Emp_Proj_Alloc_Date)
                    ELSE
                        (Project_End_Date - Emp_Proj_Alloc_Date)
                    END
                END AS "DAYS"
FROM Project_Allocation NATURAL JOIN Employee NATURAL JOIN Projects; 

ALTER TABLE Projects ADD Manager_Id NUMBER(10);

ALTER TABLE Projects ADD FOREIGN KEY(Manager_Id) REFERENCES Employee(EmpNo);
UPDATE Projects SET Manager_Id = 101 WHERE Project_Code ='P001';
UPDATE Projects SET Manager_Id = 202 WHERE Project_Code ='P002';
UPDATE Projects SET Manager_Id = 116 WHERE Project_Code ='P003';

SELECT * FROM Projects;

INSERT INTO Projects (Project_Code,Project_Description,Project_Start_Date) VALUES('P004','Election Rage','01-03-2007');

SELECT * FROM Projects;

DELETE FROM Projects WHERE Project_Description='Effects of IT';

SELECT * FROM Projects;

SELECT Project_Description FROM Projects 
    WHERE 
        Project_End_Date IS NULL 
        OR
        (Project_End_Date-Project_Start_Date) >=395;
        
SELECT Emp_Name,Project_Description FROM Project_Allocation NATURAL JOIN Employee NATURAL JOIN Projects WHERE Emp_Proj_Alloc_Date<'01-03-2007' AND (Emp_Proj_Release_Date is NULL OR Emp_Proj_Release_Date>='01-02-2006');        