package com.company;
import java.util.Scanner;

public class Check {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Number: ");
        boolean num = sc.hasNextInt();
        System.out.println(num);
    }
}
