import java.util.*;

class customer{
    double cust_id, phone,  num_call; 
    private float bill_num = 0, total_bill = 0;
    private String name;

    Scanner sc = new Scanner(System.in);

    public void getData(){
        System.out.print("\nEnter the customer Id: ");
        cust_id = sc.nextInt();
        System.out.print("\nEnter the customer Name: ");
        name = sc.next();
        System.out.print("\nEnter the customer Phone number: ");
        phone = sc.nextInt();
        System.out.print("\nEnter the customer Bill number: ");
        bill_num = sc.nextInt();     
        System.out.print("\nEnter the customer Number of calls: ");
        num_call = sc.nextInt();
    }

    public float Calculate_bill_amt(){
        if (num_call <= 100){
            total_bill = 100;
        }
        else if ( num_call <= 150){
            total_bill = (float) (100 + (0.6f * (num_call - 100) ));
        }
        else if ( num_call <= 200){
            total_bill = (float) (100 + (0.6f * (num_call - 100)) + (0.5f * (num_call - 150)));
        }
        else if ( num_call > 200){
            total_bill = (float) (100 + (0.6f * (num_call - 100)) + (0.5f * (num_call - 150))+ 0.4f * (num_call - 200));
        }
        return total_bill;
    }

    public void display(){
        
        System.out.println("Customer id: "+cust_id);
        System.out.println("Customer name: "+name);
        System.out.println("Customer phone number: "+phone);
        System.out.println("Customer bill num: "+bill_num);
        System.out.println("Customer's number of call made: "+num_call);
        System.out.println("Total Bill amount: "+ Calculate_bill_amt());
    }
}

public class tele{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        

        System.out.print("Enter the customer count: ");
        int num = sc.nextInt();

        customer obj[] = new customer[num];
        
        for (int i = 0; i < num ; i++){
           obj[i] = new customer();
           obj[i].getData();
        }

        for (int i = 0; i < num ; i++){
            obj[i].display();
        }

        sc.close();

    }
}