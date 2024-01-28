#include<iostream>
using namespace std;

const int size = 100;

struct stack {
    int top;
    int *arr;
    int capacity;

    stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;
    }

    ~stack() {
        delete[] arr;
    }

    bool empty() {
        return top == -1;
    }

    bool full() {
        return top == capacity - 1;
    }

    void push(int x) {
        if (full()) {
            cout << "\nStack Overflow\n";
            return;
        }
        arr[++top] = x;
        cout << x << " Pushed into the Stack\n";
    }

    int pop() {
        if (empty()) {
            cout << "Stack is Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (empty()) {
            cout << "The stack is empty\n";
            return -1;
        }
        return arr[top];
    }
};

int main() {
    int capacity, a, b, c;
    cout << "Enter the Capacity of stack: ";
    cin >> capacity;
    stack s(capacity);

    cout << "Enter the value: ";
    cin >> a;
    cout << "Enter the value: ";
    cin >> b;
    cout << "Enter the value: ";
    cin >> c;

    s.push(a);
    s.push(b);
    s.push(c);

    cout << s.pop() << " popped from the stack\n";
    cout << "Top element is " << s.peek() << endl;
      
    return 0;
}
