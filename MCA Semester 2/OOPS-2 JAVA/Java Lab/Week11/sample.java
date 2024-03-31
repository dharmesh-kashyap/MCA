import java.util.*;
import java.io.*;

class Bank implements Serializable {
    private String C_name;
    private int age;
    private int Acc_no;
    private int balance;

    void input() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Cust_name: ");
        C_name = sc.nextLine();
        System.out.println("Enter Customer Age: ");
        age = sc.nextInt();
        sc.nextLine(); // Consume the newline character
        System.out.println("Enter Customer Account No. : ");
        Acc_no = sc.nextInt();
        System.out.println("Enter Customer Balance: ");
        balance = sc.nextInt();
        sc.close();
    }

    @Override
    public String toString() {
        return "Bank{" + C_name + "," + age + "," + Acc_no + "," + balance + "}";
    }

    void display() {
        System.out.println("Customer Name: " + C_name);
        System.out.println("Customer Age: " + age);
        System.out.println("Customer Acc_no" + Acc_no);
        System.out.println("Balance: " + balance);
    }

    String getName() {
        return C_name;
    }

    int getAcc_no() {
        return Acc_no;
    }
    
}

public class sample {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter No. of Customers: ");
        int n = sc.nextInt();
        sc.nextLine(); 
        
        Bank b[] = new Bank[n];
        try {
            FileOutputStream fw = new FileOutputStream("account_info.txt");
            ObjectOutputStream ob = new ObjectOutputStream(fw);
            for (int i = 0; i < n; i++) {
                b[i] = new Bank();
                b[i].input();
                ob.writeObject(b[i]);
            }
            ob.close();
            fw.close();
         
        } 
        catch (IOException e) {
            e.printStackTrace();
        }


      try{
        FileInputStream fis = new FileInputStream("account_info.txt");
        ObjectInputStream ois = new ObjectInputStream(fis);
        for (int i = 0; i < n; i++)
        {
            Bank bank=(Bank)ois.readObject();
            System.out.println(bank);
        }
        ois.close();
        fis.close();
      }
      catch(IOException e){
        e.printStackTrace();
      }
      catch(ClassNotFoundException e){
        e.getMessage();
      }

    sc.close();
    }
}