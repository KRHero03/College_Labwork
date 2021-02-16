import java.util.Scanner;

public class Question3 {

    public static void main(String args[]) {

        try {

            Scanner s = new Scanner(System.in);

            System.out.println("String Replace Program");

            System.out.print("Please enter the string: ");
            String mainString = s.nextLine();

            System.out.print("Please enter the character(s) that replaces space: ");
            String subsituteString = s.nextLine();

            String finalString = mainString.replace(" ", subsituteString);

            System.out.println("Modified String: "+finalString);

            s.close();
            
        } catch (Exception e) {
            System.out.println("Program exited due to unforeseen error!");
        }

    }

}