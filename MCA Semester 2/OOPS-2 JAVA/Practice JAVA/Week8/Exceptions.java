import java.util.*;

public class Exceptions{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the A: ");
        double a[] = new double[3];
        a[0] = 56;
        a[1] = 7;
        a[2] = 6;

        System.out.println("Enter the Denominator: ");
        double b = sc.nextInt();
        System.out.println("Enter the Address out of 0, 1, 2: ");
        int c = sc.nextInt();

        // try {
        //     System.out.println("Achha");
        //     try {
        //         System.out.println("The answer is: " + a[c]/b);
                
        //     } catch (ArrayIndexOutOfBoundsException e) {
        //         System.out.println(e);
        //     }
        // } catch (Exception e) {
        //     System.out.println(e);
        // }
        // try {
        //     System.out.println("The answer is: " + a[c]/b);
        // }
        // catch(ArithmeticException e){
        //     System.out.println("Kuch to gadbad hai !");
        //     System.out.println(e);
        // }
        // catch(ArrayIndexOutOfBoundsException e){
        //     System.out.println("Kuch to gadbad hai !");
        //     System.out.println(e);
        // }
        // catch(Exception e){
        //     System.out.println("Kuch to gadbad hai !");
        //     System.out.println(e);
        // }
        
        System.out.println("End of the Program");
        sc.close();
    }
};