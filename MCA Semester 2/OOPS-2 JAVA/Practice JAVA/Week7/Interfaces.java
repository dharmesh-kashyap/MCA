import java.util.*;

interface Bicycle{
    void applyBreak(int decrement);
    void speedUP(int increment);
}

interface blowHorn{
    void BLWH();
    void BLW();
}

class AvonCycle implements Bicycle, blowHorn {

    public void applyBreak(int decrement){
        System.out.println("Applying Break");
    };
    public void speedUP(int increment){
        System.out.println("Speed Up");
    };

    public void BLWH(){
        System.out.println("HEE HEE");
    }

    public void BLW(){
        System.out.println("HOO haAA");
    }
};

public class Interfaces {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        AvonCycle mycycle = new AvonCycle();

        mycycle.applyBreak(0);
        mycycle.speedUP(0);
        mycycle.BLW();
        mycycle.BLWH();

        sc.close();
    }
    
}
