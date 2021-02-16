package Question7;

public class Circle {

    private double radius;


    Circle(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getArea() {
        return Math.PI * this.radius * this.radius;
    }

    public boolean equals(Circle c) {
        return this.radius == c.getRadius();
    }

}
