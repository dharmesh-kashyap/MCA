import java.util.*;
import conversion.*;
public class tempconvert {
     public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int choice ;
        do {

            System.out.println("---Menu---");
            System.out.println("1. Convert Celcius To Fahrenheit");
            System.out.println("2. Convert Fahrenheit to Celcius");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            double temp;


            switch (choice) {
                case 1:
                    System.out.print("Enter the temperature in celius: ");
                    temp = sc.nextDouble();
                    CelToFahr temp1 = new CelToFahr(temp);
                    System.out.println(temp + " Celcius is converted to " + temp1.converted()+" Fahrenheit");
                    break;

                case 2:
                    System.out.print("Enter the temperature in Fahrenheit: ");
                    temp = sc.nextDouble();
                    FahrToCels temp2 = new FahrToCels(temp);
                    System.out.println(temp + " Fahrenheit is converted to " + temp2.converted()+" Celcius");
                    break;
                case 3: 
                    System.out.println("Exiting....");
                    break;
                default:
                    System.out.println("Invalid Choice");
                    break;
            }
            
        } while (choice!=3);
        sc.close();
     }
}
