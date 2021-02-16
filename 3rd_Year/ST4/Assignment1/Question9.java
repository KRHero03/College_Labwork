import java.util.Scanner;

public class Question9 {

    public static void main(String[] args) {

        try {
            Scanner scan = new Scanner(System.in);

            System.out.print("Enter 3 Numbers(Separated with Spaces): ");
            int num1 = scan.nextInt();
            int num2 = scan.nextInt();
            int num3 = scan.nextInt();

            if (num1 <= num2 && num2 <= num3) {
                System.out.println("Numbers are in increasing order.");
            } else if (num1 >= num2 && num2 >= num3) {
                System.out.println("Numbers are in decreasing order.");
            } else {
                System.out.println("Numbers are in neither increasing nor decreasing order.");
            }
            scan.close();
        } catch (Exception e) {
            System.out.println("Program exited due to unforeseen error.");
            System.out.println("Error: "+e.toString());
        }
    }

}
