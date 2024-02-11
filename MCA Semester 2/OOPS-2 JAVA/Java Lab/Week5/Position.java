import java.util.Scanner;

public class Position {

    public static void index(String str1, String str2, int len, int pos) {
        System.out.print("S1 Uppercase: ");
        System.out.println(str1.toUpperCase());

        System.out.print("S2 Lowercase: ");
        System.out.println(str2.toLowerCase());

        System.out.print("Substring of " + str1 + " from position " + pos + " with length " + len + " = ");
        System.out.println(str1.substring(pos, pos + len));

        System.out.print("Inserting " + str2 + " into " + str1 + " at position " + pos + " = ");
        System.out.println(insertString(str1, str2, pos));

        System.out.print("Appending '" + str2 + "' into '" + str1 + "' = ");
        System.out.println(str1.concat(str2));
        System.out.println();
    }

    private static String insertString(String str1, String str2, int position) {
        if (position < 0 || position > str1.length()) {
            System.out.println("Invalid position.");
            return str1;
        }
        String part1 = str1.substring(0, position);
        String part2 = str1.substring(position);
        return part1 + str2 + part2;
    }
    

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int length, position;
        String str1, str2;

        System.out.print("Enter String1: ");
        str1 = sc.nextLine();

        System.out.print("Enter String2: ");
        str2 = sc.nextLine();

        System.out.print("Enter length: ");
        length = sc.nextInt();

        System.out.print("Enter Position: ");
        position = sc.nextInt();

        index(str1, str2, length, position);
        sc.close();
    }
}
