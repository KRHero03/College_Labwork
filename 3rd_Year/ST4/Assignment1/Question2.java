import java.util.Scanner;

public class Question2 {

    public static Long gcd(Long a, Long b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    public static void main(String args[]) {

        try {

            Scanner s = new Scanner(System.in);

            System.out.println("LCM Program");

            System.out.print("Please enter the first number: ");
            Long num1 = Long.parseLong(s.nextLine());

            System.out.print("Please enter the second number: ");
            Long num2 = Long.parseLong(s.nextLine());

            Long lcm = (num1/gcd(num1,num2)) * num2;

            System.out.println("LCM("+num1+","+num2+"): "+lcm);

            s.close();
            
        } catch (Exception e) {
            System.out.println("Program exited due to unforeseen error!");
        }

    }

}