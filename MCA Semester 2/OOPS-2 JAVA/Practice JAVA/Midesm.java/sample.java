import java.util.*;
import java.lang.*;

class demo implements Runnable{
    public void run(){
        System.out.println("thread 1");
    }
}

class demo2 implements Runnable{
    public void run(){
        System.out.println("thread 2");
    }
}

public class sample {
    public static void main(String[] args) {
        demo aa = new demo();
        demo2 bb = new demo2();

        Thread t1 = new Thread(aa);
        Thread t2 = new Thread(bb);

        t1.start();
        try{
            t1.join();
        }catch(Exception e){
            System.out.println("Exception occured");
        }

        t2.start();
    }
}