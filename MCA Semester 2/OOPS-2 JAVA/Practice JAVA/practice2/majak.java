import java.util.Scanner;
import java.lang.Math;

class Points {
    Scanner sc = new Scanner(System.in);
    private double x;
    private double y;

    public void setData() {
        System.out.print("Enter the x-coordinate: ");
        this.x = sc.nextDouble();
        System.out.print("Enter the y-coordinate: ");
        this.y = sc.nextDouble();
    }

    public double distance(Points p) {
        double dx = p.x - this.x;
        double dy = p.y - this.y;
        return Math.sqrt(dx * dx + dy * dy);
    }
}

public class majak{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the coordinates for Point P1:");
        Points P1 = new Points();
        P1.setData();

        System.out.println("Enter the coordinates for Point P2:");
        Points P2 = new Points();
        P2.setData();

        System.out.println("Enter the coordinates for Point P3:");
        Points P3 = new Points();
        P3.setData();

        sc.close();

        // Calculate distance between P1 and P2
        double distanceP1P2 = P1.distance(P2);
        System.out.println("Distance between P1 and P2: " + distanceP1P2);

        // Calculate distance between P1 and P3
        double distanceP1P3 = P1.distance(P3);
        System.out.println("Distance between P1 and P3: " + distanceP1P3);
    }
}

