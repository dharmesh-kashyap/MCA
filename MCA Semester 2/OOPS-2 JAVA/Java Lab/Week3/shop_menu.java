import java.util.*;

class shop{
    private static Scanner sc = new Scanner(System.in);
    protected int id;
    protected String name;
    protected int quantity;
    protected int price;
    protected double total;


    public void getdata(){
        System.out.println("Product details: ");
        System.out.print("ID: ");
        id = sc.nextInt();
        System.out.print("Name: ");
        name = sc.next();
        System.out.print("Quantity: ");
        quantity = sc.nextInt();
        System.out.print("Price: ");
        price = sc.nextInt();
        total = price * quantity;
    }

    public void display(){
        System.out.println("Product details: ");
        System.out.println("Item ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Quantity: " + quantity);
        System.out.println("Price: " + price);
        System.out.println("Total: " + total);

    }


    public void discount(){
        if(total <= 500)
            System.out.println("NO discount");
        else if(total > 500 && total <= 1000){
            System.out.println("10% Discount");
            total = total - (total * 0.10);
            System.out.println("Updated total: " + total);
        }
        else if(total > 1000 && total <= 2000){
            System.out.println("12% Discount");
            total = total - (total * 0.12);
            System.out.println("Updated total: " + total);
        }
        else if(total > 2000){
            System.out.println("15% Discount");
            total = total - (total * 0.15);
            System.out.println("Updated total: " + total);
        }
    }

}

public class shop_menu{
    public static void main(String[] args) {
		shop aa = new shop();
        Scanner sc = new Scanner(System.in);

        System.out.println("Menu:");
        System.out.println("1. Enter item details");
        System.out.println("2. Display invoice");
        System.out.println("3. Exit");

        int choice;

        do {
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                	aa.getdata();
                    break;

                case 2:
                	aa.display();
                    aa.discount();
                    break;

                case 3:
                    System.out.println("Exiting the program. Thank you!");
                    break;

                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }

        } while (choice != 3);
		sc.close();
   }

}