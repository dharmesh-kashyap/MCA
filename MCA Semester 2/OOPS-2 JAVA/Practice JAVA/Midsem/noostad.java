import java.util.*;
class outer{
    private Double x;
    outer(double x2){
        this.x = x2;
    }
    public void display(){
        inner inner = new inner();
        inner.Display();
    }
    class inner{
        public void Display(){
            System.out.println(x);
        }
    }
}
public class noostad{
    public static void main(String[] args){
        Scanner sc =  new Scanner(System.in);
        System.out.print("Enter th value: ");
        double x;
        x = Double.parseDouble(args[0]);
        outer Puter = new outer(x);
        Puter.display();
        outer.inner Pnner = Puter.new inner();
        Pnner.Display();
        sc.close();
    }
}