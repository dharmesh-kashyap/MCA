package com.company;
import java.util.Scanner;
public class StudentPercentage {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Marks of first Subject: ");
        float m1 = sc.nextFloat();
        System.out.print("Enter the Marks of second Subject: ");
        float m2 = sc.nextFloat();
        System.out.print("Enter the Marks of third Subject: ");
        float m3 = sc.nextFloat();
        System.out.print("Enter the Marks of fourth Subject: ");
        float m4 = sc.nextFloat();
        System.out.print("Enter the Marks of fifth Subject: ");
        float m5 = sc.nextFloat();
        int total = 560 ;
        float expected = m1 + m2 + m3 + m4 + m5;
        float percentage = (expected/total) * 100;
        System.out.printf("Your percentage is: %5.2f",percentage);
    }
}
