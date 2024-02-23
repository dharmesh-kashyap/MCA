import java.util.*;

class Student {
    public String Name;
    public int Regno;

    Student(String Name, int Regno) {
        this.Name = Name;
        this.Regno = Regno;
    }

    public String calculate() {
        return "";
    }
}

class Info extends Student {
    float m1, m2, m3;

    Info(String Name, int Regno, float m1, float m2, float m3) {
        super(Name, Regno);
        this.m1 = m1;
        this.m2 = m2;
        this.m3 = m3;
    }

    float avg = (m1 + m2 + m3) / 3;

    @Override
    public String calculate() {
        String grade;
        if (m1 < 35 || m2 < 35 || m3 < 35) {
            grade = "Fail";
        } else {
            if (avg >= 95) {
                grade = "A+";
            } else if (avg >= 85) {
                grade = "B";
            } else if (avg >= 70) {
                grade = "C";
            } else {
                grade = "D";
            }
        }
        return grade;
    }

    public void display() {
        System.out.println("Name: " + Name);
        System.out.println("Registration number: " + Regno);
        System.out.println("Marks of Subject 1: " + m1);
        System.out.println("Marks of Subject 2: " + m2);
        System.out.println("Marks of Subject 3: " + m3);
        System.out.println("Grade: " + calculate());
        System.out.println();
    }
}

public class StudentInformation2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int j;
        System.out.print("Enter the number of students: ");
        j = sc.nextInt();

        Info[] n = new Info[j];

        for (int i = 0; i < j; i++) {
            System.out.print("Enter the name of the student: ");
            String Name = sc.next();
            System.out.print("Enter the Registration number of the student: ");
            int Regno = sc.nextInt();
            System.out.print("Enter the Marks of Subject 1 : ");
            float m1 = sc.nextFloat();
            System.out.print("Enter the Marks of Subject 2 : ");
            float m2 = sc.nextFloat();
            System.out.print("Enter the Marks of Subject 3 : ");
            float m3 = sc.nextFloat();
            n[i] = new Info(Name, Regno, m1, m2, m3);
        }

        // Bubble Sort by registration number
        for (int i = 0; i < j - 1; i++) {
            for (int k = 0; k < j - i - 1; k++) {
                if (n[k].Regno > n[k + 1].Regno) {
                    Info temp = n[k];
                    n[k] = n[k + 1];
                    n[k + 1] = temp;
                }
            }
        }

        // Display students' information
        for (int i = 0; i < j; i++) {
            n[i].display();
        }

        sc.close();
    }
}

