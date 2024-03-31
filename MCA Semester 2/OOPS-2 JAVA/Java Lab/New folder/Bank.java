import java.io.*;
import java.util.Scanner;

class Customer implements Serializable {
    private static final long serialVersionUID = 1L;
    public String name;
    public int age;
    public long accountNumber;
    public double balance;

    public Customer(String name, int age, long accountNumber, double balance) {
        this.name = name;
        this.age = age;
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    @Override
    public String toString() {
        return "Name: " + name + ", Age: " + age + ", Account Number: " + accountNumber + ", Balance: " + balance;
    }
}


public class Bank {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of customers: ");
        int numCustomers = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        Customer[] customers = new Customer[numCustomers];
        for (int i = 0; i < numCustomers; i++) {
            System.out.println("Enter details for customer " + (i + 1) + ":");
            System.out.print("Name: ");
            String name = scanner.nextLine();

            System.out.print("Age: ");
            int age = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            System.out.print("Account Number: ");
            long accountNumber = scanner.nextLong();
            scanner.nextLine(); // Consume newline

            System.out.print("Balance: ");
            double balance = scanner.nextDouble();
            scanner.nextLine(); // Consume newline

            customers[i] = new Customer(name, age, accountNumber, balance);
        }

        scanner.close();

        writeCustomersToSerializedFile(customers, "account_info.txt");

        Customer[] deserializedCustomers = readCustomersFromSerializedFile("account_info.txt");
        if (deserializedCustomers != null) {
            System.out.println("Customer Details:");
            for (Customer customer : deserializedCustomers) {
                System.out.println(customer);
            }
        }
    }

    private static void writeCustomersToSerializedFile(Customer[] customers, String fileName) {
        try (ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(fileName))) {
            outputStream.writeObject(customers); // Serialize and write customer objects
            System.out.println("Customer data serialized and written to file: " + fileName);
        } catch (IOException e) {
            System.err.println("Error occurred while writing customer data to serialized file: " + e.getMessage());
        }
    }

    private static Customer[] readCustomersFromSerializedFile(String fileName) {
        try (ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(fileName))) {
            Object object = inputStream.readObject(); // Deserialize customer objects
            if (object instanceof Customer[]) {
                return (Customer[]) object;
            } else {
                System.err.println("Invalid data format in serialized file.");
            }
        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Error occurred while reading customer data from serialized file: " + e.getMessage());
        }
        return null;
    }
}
