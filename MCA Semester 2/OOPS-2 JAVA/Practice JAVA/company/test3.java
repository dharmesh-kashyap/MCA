package com.company;
import java.util.Scanner;
public class test3{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the first variable : ");
        int a = sc.nextInt();
        System.out.print("Enter the second variable : ");
        int b = sc.nextInt();
        System.out.print("Enter the third variable : ");
        int c = sc.nextInt();
        int sum = a + b + c;
        System.out.println("Here's Your Result : "+sum);
    }
}