import java.util.*;
public class VectorMenu {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Vector<Integer> oddIntegers = new Vector<>();

        for (int i = 1; i <= 10; i += 2) {
            oddIntegers.add(i);
        }

        int choice;
        do {
            System.out.println("\nMenu:");
            System.out.println("1. Insert an element at a specified position");
            System.out.println("2. Insert an element at the end");
            System.out.println("3. Delete an element");
            System.out.println("4. Display contents");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the element to insert: ");
                    int element = sc.nextInt();
                    System.out.print("Enter the position to insert: ");
                    int position = sc.nextInt();
                    oddIntegers.insertElementAt(element, position);
                    System.out.println("Element inserted successfully.");
                    break;
                case 2:
                    System.out.print("Enter the element to insert at the end: ");
                    int endElement = sc.nextInt();
                    oddIntegers.add(endElement);
                    System.out.println("Element inserted at the end successfully.");
                    break;
                case 3:
                    System.out.print("Enter the position of element to delete: ");
                    int deletePosition = sc.nextInt();
                    if (deletePosition >= 0 && deletePosition < oddIntegers.size()) {
                        oddIntegers.remove(deletePosition);
                        System.out.println("Element deleted successfully.");
                    } else {
                        System.out.println("Invalid position.");
                    }
                    break;
                case 4:
                    System.out.println("Contents of the vector:");
                    for (int num : oddIntegers) {
                        System.out.print(num + " ");
                    }
                    System.out.println();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a number between 1 and 5.");
            }
        } while (choice != 5);

        sc.close();
    }
}
