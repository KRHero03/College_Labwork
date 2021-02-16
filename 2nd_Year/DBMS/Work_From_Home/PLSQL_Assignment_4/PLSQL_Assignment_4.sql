set serveroutput on size 30000;

CREATE TABLE Students(
  ID NUMBER(3) PRIMARY KEY,
  Name VARCHAR(50),
  Age NUMBER(2),
  Stream VARCHAR(50),
  Marks NUMBER(3)
);

INSERT INTO Students VALUES(1,'Arun',21,'BSc',55);
INSERT INTO Students VALUES(2,'Nisarg',22,'BTech',65);
INSERT INTO Students VALUES(3,'Aarav',24,'MTech',70);
INSERT INTO Students VALUES(4,'Dhairya',27,'PhD',75);
INSERT INTO Students VALUES(5,'Dhruv',23,'MCA',65);
INSERT INTO Students VALUES(6,'Niraj',22,'MCom',74);
INSERT INTO Students VALUES(7,'Kevin',24,'MCA',78);

SELECT * FROM Students;

CREATE OR REPLACE TRIGGER check_age
BEFORE INSERT ON Students
FOR EACH ROW
BEGIN
    IF :NEW.Age > 30 THEN
        RAISE_APPLICATION_ERROR(-20001,'Age should not be greater than 30');
        RETURN;
    END IF;
END;
/

INSERT INTO Students VALUES(8,'Arkenson',32,'BTech',82);
INSERT INTO Students VALUES(9,'Priyam',26,'BSc',94);

CREATE OR REPLACE TRIGGER display_marks_changes 
BEFORE UPDATE ON Students 
FOR EACH ROW 
WHEN (NEW.Marks > 0) 
DECLARE 
   marks_diff number; 
BEGIN 
   marks_diff := :NEW.Marks  - :OLD.Marks; 
   dbms_output.put_line('Old Marks: ' || :OLD.Marks); 
   dbms_output.put_line('New Marks: ' || :NEW.Marks); 
   dbms_output.put_line('Change in Marks: ' || marks_diff); 
END; 
/ 

UPDATE Students SET Marks = 80 WHERE Name='Dhairya';