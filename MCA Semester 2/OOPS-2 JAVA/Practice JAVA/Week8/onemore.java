import java.util.*;

class radiuscant extends Exception{
    @Override
    public String toString() {
        return "Radius cant be negative";
    }
    @Override
    public String getMessage() {
        return "Radius Cant be negative";
    }
};

public class onemore {

    public static double Area(int r) throws radiuscant {
        if (r<0) {
            throw new radiuscant();
        }
        return Math.PI*r*r;
    }

    public static int Divide(int a , int b) throws ArithmeticException {
        return a/b;
    }
    public static void main(String[] args) {

        try {
            System.out.println( Area(-1) );
             
         } catch (Exception e) {
             System.out.println(e.toString());
         }

        // if(age > 100){
        //     try {
        //         throw new myExceptions();
        //     } catch (Exception e) {
        //        System.out.println(e.getMessage());
        //        System.out.println(e.toString());
        //        System.out.println(e);
        //        e.printStackTrace();
        //     }
        // }
        
    }
}
