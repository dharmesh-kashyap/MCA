import java.util.*;

public class box{
    private static Scanner sc = new Scanner(System.in);
    protected int width;
    protected int height;
    protected int depth;
    protected int volume;


    public box(int a,int b ,int c){
        width = a;
        height = b;
        depth = c;
    }

    public void display(){

		volume = width*height*depth;
        System.out.println("Product details: ");
        System.out.println("Width: " + width);
        System.out.println("Height: " + height);
        System.out.println("depth: " + depth);
        System.out.println("Volume: " + volume);

    }

    public static void main(String[] args){

        System.out.print("Enter Box Dimensions: \n");
        System.out.print("Width: ");
        int width = sc.nextInt();
        System.out.print("Height: ");
        int height = sc.nextInt();
        System.out.print("Depth: ");
        int depth = sc.nextInt();
        box aa = new box(width,height,depth);
        aa.display();

        sc.close();
    }
}
