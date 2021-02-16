import java.util.Scanner;

public class Question8 {


    public static void main(String args[]){

        try{
            Scanner scan = new Scanner(System.in);
            
            System.out.print("Please enter a character: ");            
            String mainString = scan.nextLine();

            if(mainString.length()>1) throw new Exception("More than 1 Character Received as Input!");
            if(mainString.length()<=0) throw new Exception("No Character Received as Input!");

            char t = mainString.charAt(0);
            if(!((t>='a' && t<='z') || (t>='A' && t<='Z'))) throw new Exception("Character not between 'a' and 'z' or 'A' and 'Z'");

            System.out.println("Program Run Successfully!");
            scan.close();

        }catch(Exception e){
            System.out.println("Program exited due to unforeseen error.");
            System.out.println("Error: "+e.toString());
        }
    }
}