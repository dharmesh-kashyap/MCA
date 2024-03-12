import java.util.*;
public class ArrayException {

    public static void Division(int Arr1[], int Arr2[], int ind1, int ind2){
       
               int div =  Arr1[ind1]/Arr2[ind2]; 
               System.out.println("The result is : " + div + "\n");           
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of Array: ");
        int n = sc.nextInt();
        int Array1[] = new int[n];
        int Array2[] = new int[n];
        System.out.println("Enter the Elements in both array: ");
        for (int i = 0; i < n; i++) {
            System.out.print("Enter the Element for Array 1 on " + i+1 + " : ");
            Array1[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            System.out.print("Enter the Element for Array 2 on " + i+1 + " : ");
            Array2[i] = sc.nextInt();
        }

        System.out.print("The Array 1 Elements are: ");
        for (int i = 0; i < n; i++) {
            System.out.print(Array1[i] + " ");
        }

        System.out.print("\nThe Array 2 Elements are: ");
        for (int i = 0; i < n; i++) {
            System.out.print(Array2[i] + " ");
        }
       

        try {
            System.out.println("\nEnter the index of Array 1: ");
            int id1 = sc.nextInt();
            System.out.println("Enter the index of Array 2: ");
            int id2 = sc.nextInt();

            Division(Array1, Array2, id1, id2);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println(e);
        } catch (ArithmeticException e) {
            System.out.println(e);
        } catch (Exception e){
            System.out.println(e);
        }

        System.out.println("End of the Programm");
        sc.close();
        
    }
    
}
