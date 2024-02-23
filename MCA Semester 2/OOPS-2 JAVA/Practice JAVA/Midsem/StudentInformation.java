/*
Make a base class student regno name, derived class marks result method 3 sub marks grade calculate 
sort by reg no; array of object method overriding;
*/
import java.util.*;

class Student{
    public String Name;
    public int Regno;

    Student(String Name, int Regno){
        this.Name = Name;
        this.Regno = Regno;
    }


    public String calculate(){ 
        String temp = "";
        return temp;
    }

} 
class info extends Student{
    float m1 , m2, m3;

    info(String Name, int Regno, float m1, float m2, float  m3){
        super(Name, Regno);
        this.m1 = m1;
        this.m2 = m2;
        this.m3 = m3; 
    }

    float avg = (m1+m2+m3)/3;

    
    @Override
    public String calculate(){
        String grade;
        if( (m1 <=35) || (m2 <= 35) || (m3 <= 35 ) ){
            grade = "Youre failed die";
        }
        else{
            if( avg >= 95){
                grade = "A+";
            }
            else if(avg >=85 && avg < 95){
                grade = "B";
            }
            else if( avg >=70 && avg < 85){
                grade = "C";
            }
            else {
                grade = "D";
            }
        }
        return grade;
    }

    public void display(){
        System.out.println("\nThe Name of the Student is: " + Name);
        System.out.println("Registration number of the student: " + Regno);
        System.out.println("Marks of Subject 1: " + m1);
        System.out.println("Marks of Subject 2: " + m2);
        System.out.println("Marks of Subject 3: " + m3);
        System.out.println("The Grade of student is: " + calculate());
    }



}

public class StudentInformation{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int j;
        System.out.print("Enter the number of students: ");
        j = sc.nextInt();



        info[] n = new info[j];

        for (int i = 0; i < j ; i++) {
            System.out.println("\nEnter the Student details of Student: " + (i+1));
            System.out.print("Enter the name of the student: ");
            String Name = sc.next();
            System.out.print("Enter the Registration number of the student: ");
            int Regno = sc.nextInt();
            System.out.print("Enter the MArks of Subject 1 : ");
            float m1 = sc.nextFloat();
            System.out.print("Enter the MArks of Subject 2 : ");
            float m2 = sc.nextFloat();
            System.out.print("Enter the MArks of Subject 3 : ");
            float m3 = sc.nextFloat();
            n[i] = new info(Name, Regno, m1, m2, m3);
        }

        for (int i = 0; i < j-1; i++) {
            for (int k = 0; k < j-1; k++) {
                if(n[k].Regno > n[k+1].Regno){
                    info temp = n[k];
                    n[k] = n[k+1];
                    n[k+1] = temp;
                }
                
            }
            
        }
       
        for (int i = 0; i < n.length; i++) {
                n[i].display();            
        }


        sc.close();
    }

}