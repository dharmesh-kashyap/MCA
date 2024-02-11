import java.util.Scanner;

public class test2 {

    public static String rearrangeWithCase(String input) {
        char[] chars = input.toCharArray();
        int n = chars.length;
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (chars[i] > chars[j]) {
                    char temp = chars[i];
                    chars[i] = chars[j];
                    chars[j] = temp;
                }
            }
        }

        return new String(chars);
    }

    public static String rearrangeWithoutCase(String input) {
        int[] positions = new int[input.length()];
        String lowerCaseInput = input.toLowerCase();
        for (int i = 0; i < input.length(); i++) {
            positions[i] = i;
        }
        char[] chars = lowerCaseInput.toCharArray();
        int n = chars.length;
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (chars[i] > chars[j]) {
                    char tempChar = chars[i];
                    chars[i] = chars[j];
                    chars[j] = tempChar;
                    int tempPos = positions[i];
                    positions[i] = positions[j];
                    positions[j] = tempPos;
                }
            }
        }
        char[] rearrangedChars = new char[input.length()];
        for (int i = 0; i < input.length(); i++) {
            rearrangedChars[positions[i]] = input.charAt(i);
        }

        return new String(rearrangedChars);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = scanner.nextLine();

        String rearrangedWithCase = rearrangeWithCase(input);
        String rearrangedWithoutCase = rearrangeWithoutCase(input);

        System.out.println("Rearranged with case: " + rearrangedWithCase);
        System.out.println("Rearranged without case: " + rearrangedWithoutCase);

        scanner.close();
    }
}
