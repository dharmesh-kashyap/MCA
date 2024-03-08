
import java.util.*;

abstract class Figure{
    protected int Dimension1;
    protected int Dimension2;

    public Figure(int Dimension1, int Dimension2 ){
        this.Dimension1 = Dimension1;
        this.Dimension2 = Dimension2;
    }

    public abstract double Area();
};
class Rectangle extends Figure{
    Rectangle(int len, int bredth){
        super(len , bredth);
    }

    @Override
    public double Area(){
        return  Dimension1 * Dimension2;
    }

};

class Triangle extends Figure{
    Triangle(int base, int height){
        super(base , height);
    }

    @Override
    public double Area(){
        return  0.5* Dimension1 * Dimension2;
    }
};

class Square extends Figure{
    Square(int side){
        super(side , side);
    }

    @Override
    public double Area(){
        return  Dimension1 * Dimension2;
    }
};

public class AbstractClasses{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("---Enter the Details---");
        System.out.print("Enter the Lenght: ");
        int Lenght = sc.nextInt();
        System.out.print("Enter the Breadth: ");
        int Breadth = sc.nextInt();
        System.out.print("Enter the Base: ");
        int Base = sc.nextInt();
        System.out.print("Enter the Height: ");
        int Height = sc.nextInt();
        System.out.print("Enter the Side: ");
        int Side = sc.nextInt();

        Rectangle rectangle = new Rectangle(Lenght, Breadth);
        Triangle triangle = new Triangle(Base, Height);
        Square square = new Square(Side);

        System.out.println("The area of Rectangle is: "+rectangle.Area());
        System.out.println("The area of triangle is: "+triangle.Area());
        System.out.println("The area of Square is: "+square.Area());

        sc.close();
    }
}