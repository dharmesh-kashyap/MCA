package com.Questions;
import java.util.Scanner;
public class ScoreCard {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Please enter the registration no: ");
        String Regno = sc.next();
        boolean condition = Regno.startsWith("23097");
        if(condition){
            System.out.print("Please enter student's name: ");
            String name = sc.next();
            System.out.print("Please enter semester no: ");
            int sem = sc.nextInt();
            boolean condition2 = (sem == 1 || sem ==2);
            if(condition2){
                System.out.print("Please enter the year: ");
                String year = sc.next();
                boolean condition3 = year.startsWith("20");
                if (condition3){
                    System.out.print("Enter the Marks for Object oriented Programming: ");
                    float m1 = sc.nextFloat();
                    System.out.print("Enter the Marks for DBMS: ");
                    float m2 = sc.nextFloat();
                    System.out.print("Enter the Marks for Research Methodology: ");
                    float m3 = sc.nextFloat();
                    System.out.print("Enter the Marks for Computational Technology: ");
                    float m4 = sc.nextFloat();
                    System.out.print("Enter the Marks for Web Technologies: ");
                    float m5 = sc.nextFloat();
                    float total = m1+m2+m3+m4+m5;
                    float average = total/5f;
                    boolean condition4 = (((m1 >= 35) && (m1 <= 100)) && ((m2 >= 35) && (m2 <= 100))  && ((m3 >= 35) && (m3 <= 100) ) && ( (m4 >= 35) && (m4 <= 100) ) && ((m5 >= 35) && ( m5 <= 100)) );
                    String Grade;
                    if(condition4){
                        if (average >= 85){
                            Grade = "A";}
                        else if (average >= 75){
                                Grade = "B";}
                        else if (average >= 65){
                                    Grade = "C";}
                        else if (average >= 55){
                            Grade = "D";}
                        else{
                            Grade = "E";
                        }
                    }else{
                        Grade = "Fail";
                    }
                    System.out.println("\t\tScore Card for Student: " + name + "\t\t");
                    System.out.println("Registration Number: "+Regno + "\tSemester: "+ sem + "\tyear: "+year);
                    System.out.println("Grade Assigned: ");
                    System.out.println("Serial no. \tSubject Name\tMarks Scored (out of 100)");
                    System.out.println("1 \tObject Oriented Programming\t" + m1);
                    System.out.println("2 \tDBMS\t" + m2);
                    System.out.println("3 \tResearch Methodology\t" + m3);
                    System.out.println("4 \tComputational Mathematics\t" + m4);
                    System.out.println("5 \tWeb Technologies\t" + m5);
                    System.out.println("Total: " + total);
                    System.out.println("Average: " + average);
                    System.out.println("Grade: " + Grade);


                }
                else {
                    System.out.println("Please enter the Valid Date");
                }
            }
            else{
                System.out.println("Please enter a valid semester");
            }
        }
        else {
            System.out.println("Please enter a valid roll no.");
        }


    }
}
