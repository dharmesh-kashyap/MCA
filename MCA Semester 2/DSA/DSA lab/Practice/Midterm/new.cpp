#include <iostream>
using namespace std;

class Stack {
public:
    int top;
    int capacity;
    char *arr;

    Stack(int cap) {
        top = -1;
        capacity = cap;
        arr = new char[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(char x) {
        if (isFull()) {
            cout << "The stack is full" << endl;
            return;
        }
        arr[++top] = x;
    }

    char pop() {
        if (isEmpty()) {
            cout << "The stack is Empty" << endl;
            return 0;
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) {
            cout << "The stack is Empty" << endl;
            return 0;
        }
        return arr[top];
    }

    void Display() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i];
        }
        cout << endl;
    }
};

int main() {
    int counter1 = 0;
    int counter2 = 0;
    char arr[100];
    char arr2[100];
    cout << "Enter the Word: ";
    cin >> arr;
    cout << "Enter the reverse Word: ";
    cin >> arr2;

    // Count characters in the input words
    for (char index : arr) {
        if (index == '\0') {
            break;
        }
        counter1++;
    }

    for (char index : arr2) {
        if (index == '\0') {
            break;
        }
        counter2++;
    }

    // Calculate the total length required for the stack
    int temp = counter1 + counter2 + 1;
    Stack S1(temp);

    // Push characters of the first word onto the stack
    for (int i = 0; i < counter1; i++) {
        S1.push(arr[i]);
    }

    // Push 'c' onto the stack
    S1.push('c');

    // Push characters of the reverse word onto the stack
    for (int i = counter2 - 1; i >= 0; i--) {
        S1.push(arr2[i]);
    }

    // Check if 'c' is in the middle
    bool isValid = true;
    int midIndex = (temp - 1) / 2;
    if (S1.peek() != 'c') {
        cout << "Invalid: 'c' is not in the middle" << endl;
        isValid = false;
    }

    // Display the concatenated string
    if (isValid) {
        cout << "The string is ";
        S1.Display();
    }

    // Check if the input is valid or not
    if (isValid && counter1 == counter2) {
        cout << "It is a valid string: w = " << arr << " and wr = " << arr2 << endl;
    } else {
        cout << "It is an invalid string: w = " << arr << " and wr = " << arr2 << endl;
    }
    S1.Display();
    return 0;
}
