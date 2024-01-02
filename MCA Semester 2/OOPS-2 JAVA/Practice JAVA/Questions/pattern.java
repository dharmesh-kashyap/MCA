package com.Questions;
import java.util.Scanner;
public class pattern {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Number of Rows: ");
        int rows = sc.nextInt();

        // Upside down right angled triangle
        for (int i = rows; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                System.out.print(" * ");
            }
            System.out.println();
        }


        // right angled triangle
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j <= i; j++) {
                System.out.print(" * ");
            }
            System.out.println();
        }
        int k = 1;
        for (int i = 0; i <= rows; i++) {
            for (int j = 1; j <= i; j++) {
                    System.out.print(k+ " ");
                    k++;
            }
            System.out.println();
        }
        int alpha = 64;
//        char d = 'A';
        for (int i = rows; i > 0; i--) {
            for (int j = 1; j <= i; j++) {
                   System.out.print( (char)(alpha+j));

            }
            System.out.println();
        }

    }
}
