package com.Questions;
import java.util.Scanner;
public class ReverseInteger {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        int reverse = 0;

//       do  {
//            int remainder = number % 10;
//            reverse = reverse * 10 + remainder;
//            number = number/10;
//        }while(number != 0);
//        for (int i = number; i>0; i=i/10){
//            int remainder = number % 10;
//            reverse = reverse * 10 + remainder;
//            number = number/10;
//        }
        while(number!=0){
            int remainder = number % 10;
            reverse = reverse * 10 + remainder;
            number = number/10;
        }
        System.out.println("The reverse of the given number is: " + reverse);
    }
}
