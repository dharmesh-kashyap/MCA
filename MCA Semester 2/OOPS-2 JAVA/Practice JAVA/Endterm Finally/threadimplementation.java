import java.util.*;
import java.lang.*;
import java.io.*;
class thread1 implements Runnable {
    int n;
    thread1(int n){
        this.n = n;
    }
    @Override
    public void run(){
        System.out.println("We are in thread " + n);
    }
}
public class threadimplementation {
    public static void main(String[] args) {
        thread1 t1 = new thread1(1);
        thread1 t2 = new thread1(2);

        Thread f1 = new Thread(t1);
        Thread f2 = new Thread(t2);

        f1.start();

        try {
            f1.join();
        } catch (Exception e) {
            e.printStackTrace();
        }

        f2.start();

        try {
            f2.join();
        } catch (Exception e) {
            e.printStackTrace();
        }



        
    }
}
