import java.util.*;
public class variableArgs {
    public static int sum(int x,int ...arr){
        int result = x;
        for(int a : arr){
            result += a;
        }
        return result;


    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println(sum(1,2,3,4,5,6,7,8,9));




        sc.close();
    }
    
}
