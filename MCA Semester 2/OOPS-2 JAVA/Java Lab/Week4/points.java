
import java.util.Scanner;

public class points {
    Scanner sc = new Scanner(System.in);
    float x;
    float y;

    public void getData() {
        

        System.out.print("Enter x-coordinate: ");
        x = sc.nextFloat();

        System.out.print("Enter y-coordinate: ");
        y = sc.nextFloat();

    }

	public void display() {
	        System.out.print("( "+ x + " , "+ y + " )");
    }

    public static double distance(points P1, points P2) {
        return Math.sqrt(Math.pow(P2.x - P1.x, 2) + Math.pow(P2.y - P1.y, 2));
    }


    public static double distance(points P1, float x, float y) {
        return Math.sqrt(Math.pow(x - P1.x, 2) + Math.pow(y - P1.y, 2));
	}
    
    public static void main(String[] args) {
		float x = 0;
		float y = 0;
        points P1 = new points();
        points P2 = new points();
        points P3 = new points();
        System.out.println("Co- ordinates for P1 object: ");
        P1.getData();
        System.out.println("Co- ordinates for P2 object: ");
		P2.getData();
		System.out.println("Co- ordinates for P3 object: ");
		P3.getData();

		x = P3.x;
		y = P3.y;

		System.out.print("P1 = ");
		P1.display();
		System.out.print("\n");
		System.out.print("P2 = ");
		P2.display();
		System.out.print("\n");
		System.out.print("P3 = ");
		P3.display();
		System.out.print("\n");

        System.out.println("The distance between P1 and P2 is " + distance(P1, P2));
        System.out.println("The distance between P1 and P3 is " + distance(P1, x, y));
       
    }
    
}
