import java.util.Arrays;
import java.util.Scanner;

public class sorting {

    public static String SortWithCase(String input) {
        char[] chars = input.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }

    public static String SortWithoutCase(String input) {
        input = input.toLowerCase(); 
        char[] chars = input.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        System.out.println("Sorted with case: " + SortWithCase(input));
        System.out.println("Sorted without case: " + SortWithoutCase(input));

        sc.close();
    }
}
