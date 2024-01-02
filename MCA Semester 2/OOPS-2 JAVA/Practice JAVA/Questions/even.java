package com.Questions;
import java.util.Scanner;
public class even {
    public static void main(String[] args) {
        System.out.print("Enter the number: ");
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();

        boolean condition1 = (a % 2) == 0;
        if (condition1){
            System.out.println("The number is even: " + a);
        }
        else {
            System.out.println("The number is odd: " + a);
        };
    }
}
