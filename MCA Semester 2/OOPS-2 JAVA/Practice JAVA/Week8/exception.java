public class exception {

    public static float Area(int r){
        return r*r;
    }

    public static int Divide(int a , int b) throws ArithmeticException {
        return a/b;
    }
    public static void main(String[] args) {
        try {
           System.out.println( Divide(52, 2) );
            
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    
}
