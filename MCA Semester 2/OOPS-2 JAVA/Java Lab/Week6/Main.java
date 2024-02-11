import java.util.Scanner;

class Student {
    protected int registerNumber;
    protected String name;
    protected String course;
    protected int semester;

    // Method to get data for Student
    void get_data() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Register Number: ");
        registerNumber = sc.nextInt();
        System.out.print("Enter Name: ");
        name = sc.next();
        System.out.print("Enter Course: ");
        course = sc.next();
        System.out.print("Enter Semester: ");
        semester = sc.nextInt();
    }

    // Method to display data for Student
    void display() {
        System.out.println("Register Number: " + registerNumber);
        System.out.println("Name: " + name);
        System.out.println("Course: " + course);
        System.out.println("Semester: " + semester);
    }
}

class Exam extends Student {
    protected int sub1;
    protected int sub2;
    protected int sub3;

    // Method to get data for Exam (overrides the method in the superclass)
    @Override
    void get_data() {
        super.get_data();  // Call the get_data method of the superclass
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Marks for Subject 1: ");
        sub1 = sc.nextInt();
        System.out.print("Enter Marks for Subject 2: ");
        sub2 = sc.nextInt();
        System.out.print("Enter Marks for Subject 3: ");
        sub3 = sc.nextInt();
    }

    // Method to display data for Exam (overrides the method in the superclass)
    @Override
    void display() {
        super.display();  // Call the display method of the superclass
        System.out.println("Marks for Subject 1: " + sub1);
        System.out.println("Marks for Subject 2: " + sub2);
        System.out.println("Marks for Subject 3: " + sub3);
    }
}

class Result extends Exam {
    Scanner sc = new Scanner(System.in);
    protected int total;
    protected char grade;

    @Override
    void get_data() {
        super.get_data();  // Call the get_data method of the superclass
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Grade of the student:");
        grade = sc.next().charAt(0);
    }

    @Override
    void display() {
        super.display(); 
        total = sub1 + sub2 + sub3; 
        System.out.println("Total Marks: " + total);
        System.out.println("Grade: " + grade);
    }
}

public class Main {
    public static void main(String[] args) {
        Result cc = new Result();
        cc.get_data();
        cc.display();
    }
}
