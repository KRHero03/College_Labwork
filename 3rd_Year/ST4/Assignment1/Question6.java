import java.util.Scanner;

public class Question6 {
    

    public static void main(String[] args){

        Scanner scan = new Scanner(System.in);
        

        scan.close();

    }


    public class Student{

        private String rollNo;

        Student(){
            this.rollNo = null;
        }

        Student(String roll){
            this.rollNo = roll;            
        }

        String getRollNo(){
            return this.rollNo;
        }

        void setRollNo(String roll){
            this.rollNo = roll;
        }

        void display(){
            System.out.println("Roll No. : "+this.rollNo);
        }
    }

    public class Test extends Student{

        private int marks1,marks2;

        Test(){
            this.marks1 = 0;
            this.marks2 = 0;
        }

        Test(int marks1,int marks2){
            this.marks1 = marks1;   
            this.marks2 = marks2;
        }

        public int getMarks1() {
            return marks1;
        }

        public int getMarks2() {
            return marks2;
        }

        public void setMarks1(int marks1) {
            this.marks1 = marks1;
        }

        public void setMarks2(int marks2) {
            this.marks2 = marks2;
        }

        public void display(){
            System.out.println("Marks 1: "+this.marks1);
            System.out.println("Marks 2: "+this.marks2);
        }
    }

    public class Result extends Test { 
        private int totalMarks;

        Result(){
            this.totalMarks = 0;
        }

        Result(int totalMarks){
            this.totalMarks = totalMarks;  
        }

        public int getTotalMarks() {
            return totalMarks;
        }
        public void setTotalMarks(int totalMarks) {
            this.totalMarks = totalMarks;
        }
        public void display(){
            System.out.println("Total Marks : "+this.totalMarks);
        }

    }
}

