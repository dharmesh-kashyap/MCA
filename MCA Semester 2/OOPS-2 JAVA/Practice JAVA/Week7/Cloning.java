import java.util.*;

class Employee implements Cloneable{
    String name;
    int id;
    String Designation;
    double Salary;
    Employee(String name, int id, String Designation, double Salary){
        this.name = name;
        this.id = id;
        this.Designation = Designation;
        this.Salary = Salary;
    }
    @Override
    protected Object clone() throws CloneNotSupportedException{
        return super.clone();
    }
};

public class Cloning {
    public static void main(String[] args) throws CloneNotSupportedException {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the name of the employee: ");
        String name = sc.nextLine();
        System.out.print("Enter the id of the employee: ");
        int id = sc.nextInt();
        sc.nextLine(); // Consume newline
        System.out.print("Enter the Designation of the employee: ");
        String Designation = sc.nextLine();
        System.out.print("Enter the Salary of the employee: ");
        double Salary = sc.nextDouble();

        Employee A = new Employee(name, id, Designation, Salary);
        Employee B = (Employee)A.clone();

        System.out.println("The Original employee data is: " + A.name + " " + A.id + " " + A.Designation + " " + A.Salary);
        System.out.println("The Cloned employee data is: " + B.name + " " + B.id + " " + B.Designation + " " + B.Salary);


        sc.close();
    }
}
