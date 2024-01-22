import java.util.Scanner;
import java.lang.Math;

public class NewQuadraticEquation {

    public static float getdata() {
        Scanner sc = new Scanner(System.in);
        return sc.nextFloat();
    }

    public static void main(String[] args) {
        double a, b, c, temp1, temp4, temp3, temp5;

         a = Double.parseDouble(args[0]);
         b = Double.parseDouble(args[1]);
         c = Double.parseDouble(args[2]);

        temp4 = (b * b) - (4 * a * c);

        if (temp4 >= 0) {
            temp3 = Math.sqrt(temp4);

            temp1 = ((-b) + temp3) / (2 * a);
            System.out.print("Root 1 is: " + temp1 + "\n");

            if (temp4 > 0) {
                temp5 = ((-b) - temp3) / (2 * a);
                System.out.print("Root 2 is: " + temp5 + "\n");
            }
        } else {
            System.out.println("The roots are imaginary");
        }
        
    }

}
