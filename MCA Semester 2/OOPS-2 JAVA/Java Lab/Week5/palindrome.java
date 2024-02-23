import java.util.*;
public class palindrome{

    public static void palindrome1(final String sh){
        String reversed = "";
        for (int i = 0; i < sh.length(); i++){
            reversed 
            = sh.charAt(i) + reversed;
        }

        System.out.println("Reversed String: " + reversed);
        if (sh.equals(reversed)) {
            System.out.println("The string is a Plaindrome!");  
        }
        else {
            System.out.println("String is not a Palindrome!");
        }
        return;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the String: ");
        String S = sc.next();
        palindrome1(S);
        sc.close();
    }
}