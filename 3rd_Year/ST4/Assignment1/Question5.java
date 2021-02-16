import java.util.Scanner;

public class Question5 {
    
    public static void main(String args[]){

        try{

            Scanner scan = new Scanner(System.in);
            
            System.out.println("Interest Rate Program");

            System.out.print("Please enter Annual Interest Rate (in %): ");
            double rate = Double.parseDouble(scan.nextLine());

            System.out.print("Please enter Duration (in Years): ");
            double time = Double.parseDouble(scan.nextLine());

            double returnRate = Math.pow((1.00 + (rate)/100.00),time);

            System.out.println("Return Rate: "+String.format("%.2f",returnRate*100)+" %");


            scan.close();

                
        }catch(Exception e){
            System.out.println("Program exited due to unforeseen error.");
            System.out.println("Error: "+e.toString());
        }
    }
}
