import java.util.Scanner;
import java.lang.Math;

class Points {
    Scanner sc = new Scanner(System.in);
    private double x;
    private double y;

    public Points(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double distance(Points p) {
        double dx = p.x - this.x;
        double dy = p.y - this.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    public double distance(double x, double y) {
        double dx = x - this.x;
        double dy = y - this.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    void getData(){
        System.out.print("Enter the x-coordinate: ");
        x = sc.nextDouble();
        System.out.print("Enter the y-coordinate: ");
        y = sc.nextDouble();
    }
}

class Driver {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Create points
        Points P1 = new Points(1, 2);
        Points P2 = new Points(3, 4);
        Points P3 = new Points(5, 6);

        Points P1 = new Points();

        // Calculate distance between P1 and P2
        double distanceP1P2 = P1.distance(P2);
        System.out.println("Distance between P1 and P2: " + distanceP1P2);

        // Calculate distance between P1 and P3
        double distanceP1P3 = P1.distance(P3);
        System.out.println("Distance between P1 and P3: " + distanceP1P3);

        sc.close();
    }
}
