import java.util.ArrayList;
import java.util.Scanner;

class Employee {
    int empNo;
    String name;
    String designation;
    int age;
    double salary;

    public Employee(int empNo, String name, String designation, int age, double salary) {
        this.empNo = empNo;
        this.name = name;
        this.designation = designation;
        this.age = age;
        this.salary = salary;
    }
}

public class ListMenu {
    public static void main(String[] args) {
        ArrayList<Employee> employees = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\nMenu:");
            System.out.println("1. Insert an employee");
            System.out.println("2. Delete an employee");
            System.out.println("3. Display employees");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter employee details:");
                    System.out.print("Employee Number: ");
                    int empNo = scanner.nextInt();
                    System.out.print("Name: ");
                    String name = scanner.next(); // Assuming name is a single word
                    System.out.print("Designation: ");
                    String designation = scanner.next(); // Assuming designation is a single word
                    System.out.print("Age: ");
                    int age = scanner.nextInt();
                    System.out.print("Salary: ");
                    double salary = scanner.nextDouble();
                    employees.add(new Employee(empNo, name, designation, age, salary));
                    System.out.println("Employee added successfully.");
                    break;
                case 2:
                    System.out.print("Enter employee number to delete: ");
                    int empNoToDelete = scanner.nextInt();
                    boolean found = false;
                    for (Employee emp : employees) {
                        if (emp.empNo == empNoToDelete) {
                            employees.remove(emp);
                            found = true;
                            System.out.println("Employee deleted successfully.");
                            break;
                        }
                    }
                    if (!found) {
                        System.out.println("Employee not found.");
                    }
                    break;
                case 3:
                    System.out.println("List of employees:");
                    for (Employee emp : employees) {
                        System.out.println("Employee Number: " + emp.empNo);
                        System.out.println("Name: " + emp.name);
                        System.out.println("Designation: " + emp.designation);
                        System.out.println("Age: " + emp.age);
                        System.out.println("Salary: " + emp.salary);
                        System.out.println();
                    }
                    break;
                case 4:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a number between 1 and 4.");
            }
        } while (choice != 4);

        scanner.close();
    }
}
