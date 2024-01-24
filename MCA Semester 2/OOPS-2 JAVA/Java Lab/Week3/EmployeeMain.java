import java.util.Scanner;

class Employee {
    private int code;
    private String name;
    private double basic;
    private double hra;
    private double it;
    private double pf;
    private double grossSalary;
    private double netSalary;

    public void getData() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Employee Code: ");
        code = sc.nextInt();

        System.out.print("Enter Employee Name: ");
        name = sc.next();

        System.out.print("Enter Basic Salary: ");
        basic = sc.nextDouble();

        sc.close();
    }

    public void Salary() {
        hra = 0.075 * basic;
        it = 200;
        pf = 0.12 * basic;
        grossSalary = basic + hra;
        netSalary = grossSalary - (it + pf);
    }

    public void display() {
        System.out.println("\nEmployee Information:");
        System.out.println("Employee Code: " + code);
        System.out.println("Employee Name: " + name);
        System.out.println("Basic Salary: " + basic);
        System.out.println("HRA: " + hra);
        System.out.println("IT: " + it);
        System.out.println("PF: " + pf);
        System.out.println("Gross Salary: " + grossSalary);
        System.out.println("Net Salary: " + netSalary);


    }
}

public class EmployeeMain {
    public static void main(String[] args) {
        Employee aa = new Employee();
        aa.getData();
        aa.Salary();
        aa.display();

    }
}
