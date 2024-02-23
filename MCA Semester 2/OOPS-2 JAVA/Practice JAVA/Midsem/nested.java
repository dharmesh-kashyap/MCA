import java.util.*;

class Box{
    private float length, width, height;

    Box(float a, float b, float c){
        length = a;
        width = b;
        height = c;
    }

    public float volume(){
        float temp = length * width * height;
        return temp;
    }
};

class boxextra extends Box {

    
    boxextra(float a, float b, float c) {
        super(a, b, c);
        
    }
    private float weight;
    private String Color;



}

public class nested{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
          
        sc.close();
    }

}