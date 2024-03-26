import java.util.*;
//import java.lang.*;
class thread1 implements Runnable{

    int array[]; 
    thread1(int[] arr){
        array =  arr;
    }
                                                                         
    @Override
    public void run(){
        System.out.println("The Even Values: ");
        for (int i = 0; i < array.length; i++) {
            if (array[i]%2 == 0 ) {
                System.out.println(array[i]);
            }
        }
    }
}

class thread2 implements Runnable{
    int array[]; 
    thread2(int[] arr){
        array =  arr;
    }

    @Override
    public void run(){
        System.out.println("The Odd Values: ");
        for (int i = 0; i < array.length; i++) {
            if (array[i]%2 != 0 ) {
                System.out.println(array[i]);
            }
        }
    }



}

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int Array[];

        System.out.println("Enter the Number of Elements: ");

        int x;
        x = sc.nextInt();

        Array = new int[x];

        System.out.println("Enter the Elements into Array: ");
        for (int i = 0; i < x; i++) {
            Array[i] = sc.nextInt();    
        }

        thread1 positive = new thread1(Array);
        Thread T2 = new Thread(positive);
        thread2 Negative = new thread2(Array);
        Thread T1 = new Thread(Negative);
        T2.start();
        try {
            T2.join();
        } catch (Exception e) {
            System.out.println(e);
        }

        T1.start();

        try {
            T1.join();
        } catch (Exception e) {
            System.out.println(e);
        }

    }
}