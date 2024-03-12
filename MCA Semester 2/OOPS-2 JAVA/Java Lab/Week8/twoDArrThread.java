import java.util.*;

class Row1 extends Thread{
    int arr1[] = new int[3];
    Row1(int arr[][]){
        for (int i = 0; i < 3; i++) {
            arr1[i] = arr[0][i];
        }
    }
    @Override
    public void run(){
        int sum = 0; 
        for (int i = 0; i < 3; i++) {
            sum+=arr1[i];
        }

        System.out.println("The Sum of Row 1 is : "+sum );
    }
};

class Row2 extends Thread{
    int arr1[] = new int[3];
    Row2(int arr[][]){
        for (int i = 0; i < 3; i++) {
            arr1[i] = arr[1][i];
        }
    }
    @Override
    public void run(){
        int sum = 0; 
        for (int i = 0; i < 3; i++) {
            sum+=arr1[i];
        }

        System.out.println("The Sum of Row 2 is : "+sum );
    }
};

class Row3 extends Thread{
    int arr1[] = new int[3];
    Row3(int arr[][]){
        for (int i = 0; i < 3; i++) {
            arr1[i] = arr[2][i];
        }
    }
    @Override
    public void run(){
        int sum = 0; 
        for (int i = 0; i < 3; i++) {
            sum+=arr1[i];
        }

        System.out.println("The Sum of Row 3 is : "+sum );
    }
};


public class twoDArrThread {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int arr[][] = new int[3][3];
        System.out.println("Enter the elements in the matrix: ");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        System.out.println("The elements in the matrix are: ");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(arr[i][j]+ " ");
            }
            System.out.println();
        }

        Row1 r1 = new Row1(arr);
        Row2 r2 = new Row2(arr);
        Row3 r3 = new Row3(arr);

        r1.start();
        r2.start();
        r3.start();

        sc.close();

    }
}
