public class Stack {
    private static int[] stck = new int[100];
    private static int top = -1;

    private Stack() {}

    public static void push(int item) {
        if (top == 9)
            System.out.println("Stack is full.");
        else
            stck[++top] = item;
    }

    public static int pop() {
        if (top < 0) {
            System.out.println("Stack underflow.");
            return 0; 
        } else
            return stck[top--];
    }

    public static void main(String[] args) {
        for (int i = 0; i < 10; i++)
            push(i);

        System.out.println("Stack in mystack1:");
        for (int i = 0; i < 10; i++)
            System.out.println(pop());
            
        top = -1;

        for (int i = 10; i < 20; i++)
            push(i);

        System.out.println("Stack in mystack2:");
        for (int i = 0; i < 10; i++)
            System.out.println(pop());
    }
}
