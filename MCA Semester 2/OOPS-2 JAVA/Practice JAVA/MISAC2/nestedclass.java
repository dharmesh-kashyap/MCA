import java.util.*;
//import java.lang.*;
class outer{
    public Double a ;
    public outer(Double a){
        this.a = a;
    }

    public void Display(){
        System.out.println(a);
    }

    class inner{
        public void display2(){
        System.out.println(a);
        }
    }
};
class nestedclass{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Double a = Double.parseDouble(args[0]);
        outer  o = new outer(a);
        outer.inner i = o.new inner();
        o.Display();
        i.display2();

        sc.close();
    }

}