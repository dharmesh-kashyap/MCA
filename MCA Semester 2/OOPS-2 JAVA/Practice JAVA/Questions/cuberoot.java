package com.Questions;
import java.util.Scanner;
public class cuberoot {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter the number");
        int  a = sc.nextInt();
        int answer = 0;
        if (a > 0){
            for(int i = 0; i <= a; i++ ){
                boolean condition1 = i * i * i == a;
                if (condition1){
                    answer = i;
                    System.out.println(answer);
                }
            }
        }
        for(int i = 0; i >= a; i-- ){
            boolean condition1 = i * i * i == a;
            if (condition1){
                answer = i;
                System.out.println(answer);
            }

        }
    }
}
