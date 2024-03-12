import java.util.*;

class Mythread1 extends Thread {

    int n;
    Mythread1(int x){
        n = x;
    }

    @Override
    public void run(){
        for (int i = 1; i <= n; i++) {
            System.out.print((i*i)+" ");
        }
        System.out.println();
    }

}; 

class Mythread2 extends Thread {
    int n;
    Mythread2(int x){
        n = x;
    }

    @Override
    public void run(){
        for (int i = 1; i <= n; i++) {
            System.out.print((i*i*i)+" ");
        }
        System.out.println();
    }

};


public class MultiTread {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the Length : ");
        int n = sc.nextInt();

        Mythread1 Square = new Mythread1(n);
        Mythread2 Cube = new Mythread2(n);

        Square.start();
        Cube.start();

        sc.close();
        
    }
}
