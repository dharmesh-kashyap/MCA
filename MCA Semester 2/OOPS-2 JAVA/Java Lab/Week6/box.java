import java.util.*;

public class box {
    protected float length;
    protected float width;
    protected float height;

    box(float l,float w,float h){
        length = l;
        width = w;
        height = h;
    }


public class volume extends box{
    
    protected float weight;
    protected String color;

    volume(float l, float w, float h,float wei, String col){
        super(l,w,h);
        weight = wei;
        color = col;
    }

    void display(){
        double volume = length * width * height;
        System.out.println("length: " +length);
        System.out.println("width : " +width);
        System.out.println("height : " +height);
        System.out.println("weight : " +weight);
        System.out.println("color : " +color);
        System.out.println("Volume of the Box : " +volume);
    }

}


public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the dimensions of a box:");
    System.out.print("Enter the length of box: ");
    float len = sc.nextFloat();
    System.out.print("Enter the width of box: ");
    float wid = sc.nextFloat();
    System.out.print("Enter the height of box: ");     
    float hei = sc.nextFloat();
    System.out.print("Enter the weight of box: ");
    float wei = sc.nextFloat(); 
    System.out.print("Color of box: ");
    String col = sc.next();    

    box aa = new box(len,wid,hei);
    box.volume bb = aa.new volume(len,wid,hei,wei, col);
    bb.display();

}
}