import java.util.Scanner;

abstract class Figure {
    protected int dimension1;
    protected int dimension2;

    public Figure(int dimension1, int dimension2) {
        this.dimension1 = dimension1;
        this.dimension2 = dimension2;
    }

    public abstract double area();
}
class Rectangle extends Figure {
    public Rectangle(int length, int width) {
        super(length, width);
    }

    @Override
    public double area() {
        return dimension1 * dimension2;
    }
}

class Triangle extends Figure {
    public Triangle(int base, int height) {
        super(base, height);
    }

    @Override
    public double area() {
        return 0.5 * dimension1 * dimension2;
    }
}

class Square extends Figure {
    public Square(int side) {
        super(side, side);
    }

    @Override
    public double area() {
        return dimension1 * dimension2;
    }
}

public class figure_main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter length: ");
        int len = sc.nextInt();
        System.out.print("Enter width: ");
        int wid = sc.nextInt();
        System.out.print("Enter base: ");
        int base = sc.nextInt();
        System.out.print("Enter height: ");
        int hei = sc.nextInt();
        System.out.print("Enter sides: ");
        int side = sc.nextInt();

        Figure rectangle = new Rectangle(len, wid);
        Figure triangle = new Triangle(base, hei);
        Figure square = new Square(side);

        System.out.println("Area of Rectangle: " + rectangle.area());
        System.out.println("Area of Triangle: " + triangle.area());
        System.out.println("Area of Square: " + square.area());
    }
}
