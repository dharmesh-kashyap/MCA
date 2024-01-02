package com.Questions;
import java.util.Scanner;
public class LargestOfThree {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the first number: ");
        int a = sc.nextInt();
        System.out.print("Enter the second number: ");
        int b = sc.nextInt();
        System.out.print("Enter the third number: ");
        int c = sc.nextInt();

        if( a > b) {
            if (a > c) {
                System.out.println("First number is the Greatest: " + a);

            } else {
                System.out.println("Third number is the Greatest: " + c);
            }
        }
        else{
            if(b>c){
                System.out.println("Second number is the Greatest: "+ b);

            }
            else {
                System.out.println("Third number is the Greatest: "+ c);
        }
        }
    }
}
