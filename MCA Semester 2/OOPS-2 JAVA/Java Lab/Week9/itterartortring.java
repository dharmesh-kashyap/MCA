import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.ListIterator;
import java.util.Scanner;

public class itterartortring {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<String> stringList = new ArrayList<>();

        // Input five strings
        for (int i = 0; i < 5; i++) {
            System.out.print("Enter string " + (i + 1) + ": ");
            String input = scanner.nextLine();
            stringList.add(input);
        }

        // Sort the list in alphabetical order
        Collections.sort(stringList);

        // Display list using iterator (forward direction)
        System.out.println("\nDisplaying list using iterator (forward direction):");
        Iterator<String> iterator = stringList.iterator();
        while (iterator.hasNext()) {
            System.out.println(iterator.next());
        }

        // Display list using list iterator (forward direction)
        System.out.println("\nDisplaying list using list iterator (forward direction):");
        ListIterator<String> listIteratorForward = stringList.listIterator();
        while (listIteratorForward.hasNext()) {
            System.out.println(listIteratorForward.next());
        }

        // Display list using list iterator (backward direction)
        System.out.println("\nDisplaying list using list iterator (backward direction):");
        ListIterator<String> listIteratorBackward = stringList.listIterator(stringList.size());
        while (listIteratorBackward.hasPrevious()) {
            System.out.println(listIteratorBackward.previous());
        }

        scanner.close();
    }
}
