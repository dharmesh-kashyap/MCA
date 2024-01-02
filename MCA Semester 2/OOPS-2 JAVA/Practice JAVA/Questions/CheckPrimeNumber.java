package com.Questions;
import java.util.Scanner;
public class CheckPrimeNumber {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Number you want to check: ");
        int x  = sc.nextInt();
        int count = 0;
        if(x > 0){
            boolean flag = false ;
            for (int i = 2; i < x ; i++){
                boolean condition1 = x % i ==0;
                if (condition1){
                    flag = true;
                }
            }
            if (!flag) {
                System.out.println("prime number");
            }

            else{
                System.out.println("The Number is composite: " + x);
            }
        }
        else {
            System.out.println(" Please enter the valid statement");
        }
    }
}
