import java.util.*;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Serializable;

class Bank implements Serializable {
     String name;
     int age;
     int balance;
     int account;

    public Bank(String n,int ag,int bal,int acc) {
        name = n;
        age = ag;
        balance = bal;
        account = acc;
    }
}

public class BANK {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ArrayList<Bank> employeeList = new ArrayList<>();
        try {
            FileWriter inputFileWriter = new FileWriter("employee.txt");

                System.out.print("Enter a string (or 'exit' to finish): ");
                
                int choice;
                do {
                    System.out.println("\nMenu:");
                    System.out.println("1. Insert an employee");
                    System.out.println("2. Display employee details");
                    System.out.println("3. Exit");
                    System.out.print("Enter your choice: ");
                    choice = sc.nextInt();
                    switch (choice) {
                    case 1:        
                    System.out.print("Enter employee name: ");
                    String name = sc.next();
                    System.out.print("Enter employee age: ");
                    int age = sc.nextInt();
                    System.out.print("Enter employee Account: ");
                    int account = sc.nextInt();
                    System.out.print("Enter employee Balance: ");
                    int balance = sc.nextInt();

                    employeeList.add(new Bank(name, age, account, balance));
                    break;
                        
                    case 2:
                    System.out.println("Employee details:");
                    for (Bank emp : employeeList) {
                        System.out.println(
                                " Name: " + emp.name +
                                ", Age: " + emp.age +
                                ", Account: " + emp.account +
                                ", Balance: " + emp.balance);
                    }
                    break;
                    case 3:
                    for (Bank emp : employeeList) {
                        inputFileWriter.write(
                                " Name: " + emp.name +
                                        ", Age: " + emp.age +
                                        ", Account: " + emp.account +
                                        ", Balance: " + emp.balance + "\n");
                    }
                        System.out.println("Exiting the program. Goodbye!");
                        break;
                    default:
                        System.out.println("Invalid choice. Please select a valid option.");
                    }

                    }while(choice != 3);
    
                    inputFileWriter.close();

        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
            sc.close();
   }
}