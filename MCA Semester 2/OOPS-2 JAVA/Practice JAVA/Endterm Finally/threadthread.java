class thread1 extends Thread {
    int n;
    thread1(int n){
        this.n = n;
    }
    @Override
    public void run(){
        System.out.println("we are in thread " + n);
    }
}
class thread2 extends Thread {
    int n;
    thread2(int n){
        this.n = n;
    }
    @Override
    public void run(){
        System.out.println("we are in thread " + n);
    }
}
public class threadthread {
    public static void main(String[] args) {
        thread1 t1 = new thread1(1);
        thread2 t2 = new thread2(2);

        t1.start();

        try {
            t1.join();
        } catch (Exception e) {
            e.printStackTrace();
        }
        t2.start();
        try {
            t2.join();
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }
}
