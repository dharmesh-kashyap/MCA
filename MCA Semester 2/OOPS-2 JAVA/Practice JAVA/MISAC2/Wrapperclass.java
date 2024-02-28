import java.util.*;

class Wrapperclass{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
       
        int i = 20;
        @SuppressWarnings("removal")
        Integer D = new Integer(i);
        int j = D.intValue();

        System.out.println(j);
        @SuppressWarnings("removal")
        Double k = new Double(45); 
        double S = k.doubleValue();
        String st = Integer.toString(20);

        System.out.println((i + 20) + (20+20) + 20 + st);

        System.out.println(S);
        sc.close();
    }
}