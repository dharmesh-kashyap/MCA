import java.util.Scanner;

class stack {
    static int push, pop, top, n, arr[];
    static Scanner in = new Scanner(System.in);

    public stack(int num) {
        push = 0;
        pop = 0;
        top = -1;
        n = num;

        arr = new int[n];
    }

    static void push_el() {
        if (top == (n - 1)) {
            System.out.println("Over Flow");

        } else {
            System.out.print("\nEnter the Element to Insert : ");
            push = in.nextInt();
            top++;
            arr[top] = push;
        }
    }

    static void pop_el() {
        if (top == -1) {
            System.out.println("Under Flow");
        } else {
            System.out.print("Popped Element is : " + arr[top] + "\n");
            top--;
        }
    }

    public void showdata() {
        if (top == -1) {
            System.out.println("Stack is empty!!");
        } else {
            System.out.println("Stack Elements are :");
            for (int i = 0; i <= top; i++) {
                System.out.print(arr[i] + "\t");
            }
            System.out.println(" ");
        }
    }

}

class stackS {
    public static void main(String args[]) {
        int choice;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the size of the Stack : ");
        int n = in.nextInt();

        stack s1 = new stack(n);
        while (true) {
            System.out.println("1. Push into Stack ");
            System.out.println("2. POP an Element ");
            System.out.println("3. Display Elements in Stack ");
            System.out.println("4. Exit ");

            System.out.print("Please Enter your Choice : ");
            choice = in.nextInt();
            switch (choice) {
                case 1:
                    s1.push_el();
                    break;
                case 2:
                    s1.pop_el();
                    break;
                case 3:
                    s1.showdata();
                    break;
                case 4:
                    System.exit(0);
                default:
                    System.out.println("Invalid choice!\nPlease Enter a Valid Choice..");
            }
        }
    }
}