import java.util.*;

public class box{
    private static Scanner sc = new Scanner(System.in);
    protected int weight;
    protected int height;
    protected int depth;
    protected int volume;


    public box(int a,int b ,int c){
        weight = a;
        height = b;
        depth = c;
    }

    public void display(){

		volume = weight*height*depth;
        System.out.println("Product details: ");
        System.out.println("Weight: " + weight);
        System.out.println("Heigh: " + height);
        System.out.println("depth: " + depth);
        System.out.println("Volume: " + volume);

    }

    public static void main(String[] args){

        System.out.print("Enter Box Dimensions: \n");
        System.out.print("Weight: ");
        int weight = sc.nextInt();
        System.out.print("Height: ");
        int height = sc.nextInt();
        System.out.print("Depth: ");
        int depth = sc.nextInt();
        box aa = new box(weight,height,depth);
        aa.display();

        sc.close();
    }
}
