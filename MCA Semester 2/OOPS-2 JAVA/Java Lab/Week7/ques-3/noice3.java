import java.util.Scanner;

class Employee implements Cloneable {
    String name;
    int id;
    String designation;
    double salary;
    public Employee(String name, int id, String designation, double salary) {
        this.name = name;
        this.id = id;
        this.designation = designation;
        this.salary = salary;
    }
    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}

public class noice3{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter employee details:");
        System.out.print("Name: ");
        String name = scanner.nextLine();

        System.out.print("ID: ");
        int id = scanner.nextInt();

        scanner.nextLine();

        System.out.print("Designation: ");
        String designation = scanner.nextLine();

        System.out.print("Salary: ");
        double salary = scanner.nextDouble();

        Employee emp1 = new Employee(name, id, designation, salary);

        try {
            Employee emp2 = (Employee) emp1.clone();

            System.out.println("Original Employee: " + emp1.name + ", " + emp1.id + ", " + emp1.designation + ", " + emp1.salary);
            System.out.println("Cloned Employee: " + emp2.name + ", " + emp2.id + ", " + emp2.designation + ", " + emp2.salary);

            scanner.close();
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
    }
}
