import java.util.Scanner;

public class MarvelEnterprise {

    static double getPayment(double basePay, double hours) throws Exception {
        if (hours > 60)
            throw new Exception("Maximum Working Hours Error: Maximum Working Hours should not exceed 60!");

        if (basePay < 400)
            throw new Exception("Minimum Wage Error: Minimum Wage should be more than 400!");

        double m = Math.min(hours, 40);
        return m * (basePay) + (hours - m) * basePay * 1.5;

    }

    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);

            System.out.print("Base Pay: ");
            double basePay = Double.parseDouble((sc.nextLine()));

            System.out.print("Hours: ");
            double hours = Double.parseDouble((sc.nextLine()));

            double salary = getPayment(basePay, hours);

            System.out.println("Salary: " + String.format("%.2f", salary));

            sc.close();
        } catch (Exception e) {
            System.out.println("Program exited due to an unforeseen error! " + e.getMessage());
        }
    }
}