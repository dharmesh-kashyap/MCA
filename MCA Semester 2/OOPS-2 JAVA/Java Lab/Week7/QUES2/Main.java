import mypackage.*;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Select conversion type:");
            System.out.println("1. Celsius to Fahrenheit");
            System.out.println("2. Fahrenheit to Celsius");
            System.out.println("3. Exit");

            int choice = scanner.nextInt();

            if (choice == 3) {
                System.out.println("Exiting...");
                break;
            }

            System.out.println("Enter temperature:");

            double temp= scanner.nextDouble();
            double result;

            switch (choice) {
                case 1:
                    result = mypackage.CelsToFahr.ConvertCToF(temp);
                    System.out.println(temp + " Celsius is equal to " + result + " Fahrenheit");
                    break;

                case 2:
                    result = mypackage.FahrToCels.ConvertFToC(temp);
                    System.out.println(temp + " Fahrenheit is equal to " + result + " Celsius");
                    break;

                default:
                    System.out.println("Invalid choice. Please enter 1, 2, or 3.");
            }
        }

        scanner.close();
    }
}
