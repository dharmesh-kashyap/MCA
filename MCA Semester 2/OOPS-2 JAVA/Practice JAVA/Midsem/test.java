import java.util.*;
class Stack{
    private int top;
    private int capacity;
    private int[] arr;

    public Stack(int cap){
        capacity = cap;
        top = -1;
        arr = new int[capacity];
    }

    public boolean isEmpty(){
        return top == -1;
    }

    public boolean isFull(){
        return top == capacity -1;
    }

    public void push(int x){
        if(isFull()){
            System.out.println("The Stack is Full");
            return;
        }
        arr[++top] = x;
    }

    public int pop(){
        if(isEmpty()){
            System.out.println("The Stack is Empty");
            return 0;
        }
        return arr[top--];
    }

    public int peek(){
        if(isEmpty()){
            System.out.println("The Stack is Empty");
            return 0;
        }
        return arr[top];
    }

    public void display(){
        System.out.println("The Array is: ");
        for (int i = 0; i < capacity; i++) {
            System.out.print(arr[i] + " ");
        }
    }
};
public class test{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Capacity of Array: ");
        int capacity;
        capacity = sc.nextInt();
        Stack S = new Stack(capacity);

        for (int i = 0; i < capacity; i++) {
            System.out.println("Enter the Element of Array: ");
            int j;
            j = sc.nextInt();
            S.push(j);
        }

        S.display();

        System.out.println("\nThe popped value is : " + S.pop());
        System.out.println("The Top value is :" + S.peek());

        sc.close();

    } 
}