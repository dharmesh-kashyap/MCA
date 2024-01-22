import java.lang.reflect.Array;
import java.util.Scanner;
public class ArrayInverse{
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();  
        int[] Array1 = new int[n];
        int[] Array2 = new int[n];
        for(int i = 0 ; i < n ; i++){
            System.out.print("Enter the Element on "+i+" : ");
            Array1[i] = sc.nextInt();
        }

        System.out.print("\n\nThe Array of integer you entered is: ");
        for(int i = 0 ; i < n ; i++){
            System.out.print(Array1[i]+" ");   
        }
        int reverse = 0;
        int remainder, num;

        for(int i = 0 ; i < n; i++){
            num = Array1[i];

            while(num!=0){
            remainder = num % 10;
            reverse = reverse * 10 + remainder;
            num = num/10;
            }
            Array2[i]=reverse;
            reverse = 0;
        }
        System.out.print("\nThe Array of integer Reversed: ");
         for(int i = 0 ; i < n ; i++){
            System.out.print(Array2[i]+" ");   
        }
    }
}