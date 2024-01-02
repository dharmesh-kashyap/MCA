package com.Questions;
import java.util.Scanner;

public class fibonacci {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Add integer lenght");
        int il = sc.nextInt();
        int ans = 0;
        int n1 = 0, n2 = 1;
        System.out.println(n1);
        System.out.println(n2);

        for(int i = 2 ; i <il; i++){

            ans = n1 + n2 ;
            System.out.println(ans+" ");
            n1 = n2;
            n2 = ans;

        }

    }
}
