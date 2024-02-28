import java.util.*;
interface Bycicle{
    void applyBrake();
    void speedUp();
};

class Avaon implements Bycicle{
    public void applyBrake(){
        System.out.println("OOGA");
    }
    public void speedUp(){
        System.out.println("OOGA");

    }

};


public class Interfaces {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.close();
    }
}
