import java.util.*;
public class sorting {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr;
        System.out.println("enter the length of the Array: ");
        int n = sc.nextInt();

        arr = new int[n];

        for (int i = 0; i < arr.length; i++) {
            System.out.print("Enter the value : ");
            arr[i] = sc.nextInt();            
        }

        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - 1; j++) {
                if( arr[j] > arr[j+1] ){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
                
            }
        }

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");
        }

        sc.close();
        
    }
    
}
