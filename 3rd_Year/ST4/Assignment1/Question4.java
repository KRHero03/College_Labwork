import java.util.HashMap;
import java.util.Scanner;

public class Question4 {
    public static void main(String args[]) {

        try {

            Scanner s = new Scanner(System.in);

            System.out.println("Vowel Count Program");

            System.out.println("Please enter a string whose vowels need to be counted(\"quit\" to exit): ");
            String mainString = s.nextLine();

            while(!mainString.equals("quit")){
                HashMap<Character,Integer> m = new HashMap<Character,Integer>();
                m.put('a',0);
                m.put('e',0);
                m.put('i',0);
                m.put('o',0);
                m.put('u',0);
                for(char t : mainString.toLowerCase().toCharArray()){
                    if(t=='a' || t == 'e' || t=='i' || t == 'o' || t=='u'){
                        m.put(t,m.getOrDefault(t, 0) + 1);
                    }

                }
                System.out.println("Vowel Count:");
                m.forEach((k,v) -> {
                    System.out.println(""+k+": "+v);
                });
                System.out.println("Please enter a string whose vowels need to be counted(\"quit\" to exit): ");
                mainString = s.nextLine();
            }

            s.close();
            
        } catch (Exception e) {
            System.out.println("Program exited due to unforeseen error!");
            System.out.println("Error:" +e.toString());
        }

    }
}