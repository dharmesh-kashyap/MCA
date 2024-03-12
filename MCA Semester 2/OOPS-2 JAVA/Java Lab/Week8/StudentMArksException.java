import java.util.*;

class MarkOutOFBoundException extends Exception{
    @Override
    public String toString() {
        return "Marks is Out of Bound";
    }
    @Override
    public String getMessage() {
        return "Marks is Out of Range";
    }
    
}

public class StudentMArksException {

    public static void gradeCal(double m1, double m2, double m3) throws MarkOutOFBoundException {
       if ((m1 > 100 || m1 < 0) || (m2 > 100 || m2 < 0) || (m3 > 100 || m3 < 0) ) {
        throw new MarkOutOFBoundException();
       }
        double percentage = ((m1+m2+m3)/100)*100;
        String grade;
        System.out.println("The percentage : " + percentage);
        if((percentage >= 90) && (percentage <= 100)){
            grade = "A";
        }
        else if ((percentage >= 80) && (percentage < 90)) {
            grade = "B";
        }
        else if((percentage >= 70) && (percentage < 80)){
            grade = "C";
        }
        else{
            grade = "D";
        }
        System.out.println("The Grade : " + grade);
        }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the student's details: ");
        System.out.print("Enter student's name: ");
        String name = sc.nextLine();
        System.out.print("Enter the roll number: ");
        int roll = sc.nextInt();
        System.out.print("Enter the Marks in Subject 1 : ");
        double Marks1 = sc.nextInt();
        System.out.print("Enter the Marks in Subject 2 : ");
        double Marks2 = sc.nextInt();
        System.out.print("Enter the Marks in Subject 3 : ");
        double Marks3 = sc.nextInt();

        try {

            System.out.println("Name of the student: " + name );
            System.out.println("Roll number of the Student: " + roll);
            System.out.println("The percentage and grade of the Student: \n" );
            gradeCal(Marks1, Marks2, Marks3);
            
        } catch (Exception e) {
            System.out.println(e.getMessage());
            System.out.println(e.toString());
            
        }


        sc.close();
    }    
    
}
