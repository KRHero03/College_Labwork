import java.util.Scanner;

public class Question1 {
    public static void main(String args[]) {

        try {

            Scanner s = new Scanner(System.in);

            System.out.println("Volume of A Cone Program");

            System.out.print("Please enter the radius of the base circle of the cone: ");
            Long radius = Long.parseLong(s.nextLine());

            System.out.print("Please enter the height of the cone: ");
            Long height = Long.parseLong(s.nextLine());

            double volume = Math.PI * (height) * (Math.pow(radius, 3.0)) / 3;

            System.out.println("Volume of Cone: " + String.format("%.2f", volume) + " unit^3");

            s.close();
            
        } catch (Exception e) {
            System.out.println("Program exited due to unforeseen error!");
        }

    }
}