package com.Questions;
import java.util.Scanner;
public class Week_1_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the first integer: ");
        int a = sc.nextInt();
        System.out.print("Enter the second variable: ");
        int b = sc.nextInt();
        a = a+b;
        b = a - b;
        a = a - b;
        System.out.println("Swapped First : "+a);
        System.out.println("Swapped Second : "+b);
    }
}
