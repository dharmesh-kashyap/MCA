package com.Questions;
import java.util.Scanner;
public class AreaOfTriangle {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("-----------Menu---------");
        System.out.println("Choose 1 for triangle");
        System.out.println("Choose 2 for Circle");
        System.out.print("Enter your Choice: ");
        int choice = sc.nextInt();
        switch(choice){
            case 1 :
                System.out.print("Enter the Height of the triangle: ");
                float Height = sc.nextFloat();
                System.out.print("Enter the Base of the triangle: ");
                float Base = sc.nextFloat();
                float Area = 0.5f*Base*Height;
                System.out.println("The Area of Triangle is: "+Area);
                break;
            case 2 :
                System.out.print("Enter the Radius of the Circle: ");
                float radius = sc.nextFloat();
                float AreaC = 3.14f * radius * radius;
                float diameter = radius+radius;
                System.out.println("The Area of Circle is: "+ AreaC);
                System.out.println("The diameter of Circle is: "+ diameter);
                break;


        }

    }
}
