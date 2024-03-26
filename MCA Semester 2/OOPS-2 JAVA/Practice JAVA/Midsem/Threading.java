import java.util.*;
public class Threading {
    public static void main(String[] args) {
        Thread  t1 = Thread.currentThread();
        t1.setName("Nalla");
        System.out.println(t1.getName());

        try {
            Thread.sleep(1000);
            System.out.println("m");
        } catch (InterruptedException e) {
            System.out.println(e);
        }

    }
}
