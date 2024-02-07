import java.util.*;

public class customer{
    private static Scanner sc = new Scanner(System.in);
    protected int customer_id;
    protected String name;
    protected long phone;
    protected int bill;
    protected int calls;
    protected double total = 0;


    public customer(int id, String customerName, long phon, int bil, int call) {
        customer_id = id;
        name = customerName;
        phone = phon;
        bill = bil;
        calls = call;
        total = 0;
    }

    public void getdata(){
        System.out.println("Product details: ");
        System.out.print("ID: ");
        customer_id = sc.nextInt();
        System.out.print("Customer Name: ");
        name = sc.next();
        System.out.print("Phone number: ");
        phone = sc.nextLong();
        System.out.print("Bill number: ");
        bill = sc.nextInt();
        System.out.print("Number of Calls: ");
        calls = sc.nextInt();
        System.out.println("\n");

    }

    // Function to calculate bill amount
    public void calculate_bill_amount() {
        if (calls <= 100) {
            total = 100;
        } else if (calls <= 150) {
            total = 100 + (calls - 100) * 0.60;
        } else if (calls <= 200) {
            total = 100.0 + 50.0 * 0.60 + (calls - 150) * 0.50;
        } else {
            total = 100.0 + 50.0 * 0.60 + 50.0 * 0.50 + (calls - 200) * 0.40;
        }
    }

    public void display(){
        System.out.println("Product details: ");
        System.out.println("Customer ID: " + customer_id);
        System.out.println("Name: " + name);
        System.out.println("Phone Number: " + phone);
        System.out.println("Bill Number: " + bill);
        System.out.println("Number of calls: " + calls);
        System.out.println("Total calling bill: "+ total);
        System.out.println("\n");
    }



    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of customers: ");
        int n = sc.nextInt();

        customer[] aa = new customer[n];
        System.out.print("Enter Product Details: \n");
        for (int i = 0; i < n; ++i) {
            aa[i] = new customer(0, "", 0, 0, 0);
            aa[i].getdata();
            aa[i].calculate_bill_amount();
        }

        for (int i = 0; i < n; ++i) {
            aa[i].display();
        }
        sc.close();
    }      
}

