import java.util.Scanner;

class Stack {
    private int maxSize;
    private int top;
    private int[] stackArray;

    public Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    public void push(int value) {
        if (top == maxSize - 1) {
            System.out.println("Stack overflow!");
            return;
        }
        stackArray[++top] = value;
    }

    public int pop() {
        if (top == -1) {
            System.out.println("Stack underflow!");
            return -1;
        }
        return stackArray[top--];
    }

    public boolean isEmpty() {
        return (top == -1);
    }

    public boolean isFull() {
        return (top == maxSize - 1);
    }

    public void displayStack() {
        if (isEmpty()) {
            System.out.println("Stack is empty.");
            return;
        }
        System.out.println("Stack elements:");
        for (int i = top; i >= 0; i--) {
            System.out.println(stackArray[i]);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the size of the stack: ");
        int size = scanner.nextInt();
        Stack stack = new Stack(size);

        System.out.println("Enter elements to push onto the stack:");
        for (int i = 0; i < size; i++) {
            int element = scanner.nextInt();
            stack.push(element);
        }

        boolean continueOperations = true;

        while (continueOperations) {
            System.out.println("\nChoose operation:");
            System.out.println("1. Push");
            System.out.println("2. Pop");
            System.out.println("3. Exit");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    if (!stack.isFull()) {
                        System.out.print("Enter element to push onto the stack: ");
                        int element = scanner.nextInt();
                        stack.push(element);
                        stack.displayStack();
                    } else {
                        System.out.println("Stack is full. Cannot push more elements.");
                    }
                    break;
                case 2:
                    if (!stack.isEmpty()) {
                        int poppedElement = stack.pop();
                        System.out.println("Popped: " + poppedElement);
                        stack.displayStack();
                    } else {
                        System.out.println("Stack is empty. Cannot pop elements.");
                    }
                    break;
                case 3:
                    continueOperations = false;
                    break;
                default:
                    System.out.println("Invalid choice. Please enter again.");
            }
        }

        scanner.close();
    }
}
