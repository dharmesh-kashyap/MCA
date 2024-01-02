package com.company;
import java.util.Scanner;
public class conversion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Kilometers: ");
        float km = sc.nextFloat();
        double m = km / 1.609344d;
        System.out.println("Here's Km to miles conversion: " + m);
    }
}
