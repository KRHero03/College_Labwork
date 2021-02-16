package Question7;

import Question7.Circle;

public class Main {

    public static void main(String args[]) {

        System.out.println("Circle Class Demo");

        Circle c1 = new Circle(7);
        System.out.println("Circle with Radius 7 created!");

        Circle c2 = new Circle(6);
        System.out.println("Circle with Radius 6 created!");

        Circle c3 = new Circle(6);
        System.out.println("Circle with Radius 6 created again!");

        System.out.println("Area of Circle 1: "+String.format("%.2f",c1.getArea()));
        System.out.println("Area of Circle 2: "+String.format("%.2f",c2.getArea()));
        System.out.println("Area of Circle 3: "+String.format("%.2f",c3.getArea()));

        System.out.println("Comparing First Circle with Second Circle: "+(c1.equals(c2)));

        System.out.println("Comparing Second Circle with Third Circle: "+(c2.equals(c3)));



    }

}

