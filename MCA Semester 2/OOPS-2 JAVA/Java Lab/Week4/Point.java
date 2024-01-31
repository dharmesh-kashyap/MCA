import java.lang.Math;

class Point {
    private double x;
    private double y;

    public Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double distance(Point p) {
        double dx = p.x - this.x;
        double dy = p.y - this.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    public double distance(double x, double y) {
        double dx = x - this.x;
        double dy = y - this.y;
        return Math.sqrt(dx * dx + dy * dy);
    }

    public static void main(String[] args) {
        Point P1 = new Point(1, 2);
        Point P2 = new Point(3, 4);
        Point P3 = new Point(5, 6);

        // Calculate distance between P1 and P2
        double distanceP1P2 = P1.distance(P2);
        System.out.println("Distance between P1 and P2: " + distanceP1P2);

        // Calculate distance between P1 and P3
        double distanceP1P3 = P1.distance(P3);
        System.out.println("Distance between P1 and P3: " + distanceP1P3);
    }
}
