import java.util.Scanner;
public class CompareArrayPair {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter the length of Array: ");
        int n = sc.nextInt();
        int[] Array1 = new int[n];
        for(int i = 0; i< n ; i++){
            System.out.print("Enter the elements on "+i+" : ");
            Array1[i] = sc.nextInt();
        }
        System.out.print("The entered array is: ");
        for(int i = 0; i< n ; i++){
            System.out.print(Array1[i]+" ");

        }


        int num;
        System.out.print("\nThe pairs are: ");
        for(int i = 0; i < n; i++){
           num =  Array1[i];
           for(int j = 0; j < n; j ++){
            if( num > Array1[j]){
                System.out.print("("+num+","+Array1[j]+") ");
            }
           }
        }


    }
    
}
