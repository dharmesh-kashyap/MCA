import java.util.Scanner;

public class NewQuadraticEquation {

    public static float squareRoot(float x) {
        float epsilon = 0.00001f; // Define a small value for precision
        float guess = x / 2; // Initial guess
        while (Math.abs(guess * guess - x) > epsilon) {
            guess = (guess + x / guess) / 2;
        }
        return guess;
    }

    public static float getdata() {
        Scanner sc = new Scanner(System.in);
        return sc.nextFloat();
    }

    public static void main(String[] args) {
        float a, b, c, temp1, temp4, temp3, temp5;

        System.out.print("Enter the Value for a: ");
        a = getdata();
        System.out.print("Enter the Value for b: ");
        b = getdata();
        System.out.print("Enter the Value for c: ");
        c = getdata();

        temp4 = (b * b) - (4 * a * c);
        System.out.println(temp4);

        if (temp4 >= 0) {
            temp3 = squareRoot(temp4);

            temp1 = ((-1 * b) + temp3) / (2 * a);
            System.out.print("Root 1 is: " + temp1 + "\n");

            if (temp4 > 0) {
                temp5 = ((-1 * b) - temp3) / (2 * a);
                System.out.print("Root 2 is: " + temp5 + "\n");
            }
        } else {
            System.out.println("The roots are imaginary");
        }
    }
}
