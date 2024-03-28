import java.io.*;
import java.util.Scanner;

class Customer {
    private String name;
    private int age;
    private long accountNumber;
    private double balance;

    public Customer(String name, int age, long accountNumber, double balance) {
        this.name = name;
        this.age = age;
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public long getAccountNumber() {
        return accountNumber;
    }

    public double getBalance() {
        return balance;
    }

    // Override toString method to format customer data as CSV
    @Override
    public String toString() {
        return name + "," + age + "," + accountNumber + "," + balance;
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

        // Write customer data to CSV file
        writeCustomersToCSV(customers, "account_info.csv");

        // Read and display customer data from CSV file
        readAndDisplayCustomersFromCSV("account_info.csv");
    }

    private static void writeCustomersToCSV(Customer[] customers, String fileName) {
        try (PrintWriter writer = new PrintWriter(fileName)) {
            for (Customer customer : customers) {
                writer.println(customer.toString()); // Write customer data as CSV
            }
            System.out.println("Customer data written to CSV file: " + fileName);
        } catch (IOException e) {
            System.err.println("Error occurred while writing customer data to CSV: " + e.getMessage());
        }
    }

    private static void readAndDisplayCustomersFromCSV(String fileName) {
        try (Scanner scanner = new Scanner(new File(fileName))) {
            System.out.println("Reading customer data from CSV file: " + fileName);
            while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                String[] parts = line.split(",");
                if (parts.length == 4) {
                    String name = parts[0];
                    int age = Integer.parseInt(parts[1]);
                    long accountNumber = Long.parseLong(parts[2]);
                    double balance = Double.parseDouble(parts[3]);
                    System.out.println("Name: " + name);
                    System.out.println("Age: " + age);
                    System.out.println("Account Number: " + accountNumber);
                    System.out.println("Balance: " + balance);
                    System.out.println();
                }
            }
        } catch (FileNotFoundException e) {
            System.err.println("CSV file not found: " + e.getMessage());
        }
    }
}
