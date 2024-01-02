package com.Questions;

public class ArrayReverse {
    public static void main(String[] args) {
        int[] Array1 = new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9};
        int[] Array2 = new int[9];
        int j=9;
        for(int i=0; i<9;i++){
            j--;
            Array2[j] = Array1[i];
        }
        for(int k = 0; k<9; k++){
            System.out.print(Array2[k]+" ");
        }
        int answer = 0;
        for(int k = 0; k<=8; k++){

           if((k % 2) == 0){
               answer +=Array1[k];
           }
        }
        System.out.println(answer);

    }
}
