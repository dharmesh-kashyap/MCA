import java.util.Scanner;
public class newfile{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        float fc[] = new float[5];

        for(int i = 0; i < 5; i++){
            fc[i] = sc.nextFloat();
        }
        for(int i = 0; i < 5; i++){
            System.out.print(fc[i]+" ");
        }
        sc.close();
    }
}
