class thread extends Thread {
    int x ;
    thread(int x){
        this.x = x;
    }
    @Override 
    public void run(){
        System.out.println("Thread" + x);
    }
}
public class Sample2 {
    public static void main(String[] args) {

        thread obj1 = new thread(1);
        thread obj2 = new thread(2);

        obj1.start();

        try {
            obj1.join();
        } catch (Exception e) {
            System.out.println(e);
        }

        obj2.start();
    }
}
