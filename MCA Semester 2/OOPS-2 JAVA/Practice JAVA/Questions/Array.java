package com.Questions;

public class Array {
    public static void main(String[] args) {
        int prod = 0;
        int[] intArray = new int[]{ 1,2,3,4,5,6,7,8,9,10 };
        for(int i = 0; i< 10; i++){
          prod += intArray[i];
        }
        System.out.println(prod);
    }
}
