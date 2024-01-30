#include <iostream>
#include <string>

using namespace std;

struct Stack{
    int capacity;
    int *arr;
    int top;

    Stack(int size){
        capacity = size;
        top = -1;
        arr = new int[capacity];
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == capacity - 1;
    }

    void push(int x){
        if (isFull()) {
            cout<<"Stack is Full";
            return; 
        }
        arr[++top] = x;
    } 

    int pop(){
        if (isEmpty()) {
            cout<<"The stack is empty";
            return top = -1;
        }
        return arr[top--];
    }

    int peek(){
        if (isEmpty()) {
            cout<<"The stack is empty";
            return -1;
        }
        return arr[top];
    }
};

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

string infixToPrefix(const string& infix) {
    string prefix;
    Stack operators(infix.length());

    string reversedInfix;
    for (int i = infix.length() - 1; i >= 0; --i) {
        reversedInfix += infix[i];
    }

    for (int i = 0; i < reversedInfix.length(); ++i) {
        char ch = reversedInfix[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            prefix += ch;
        } else if (ch == ')') {
            operators.push(ch);
        } else if (ch == '(') {
            while (!operators.isEmpty() && operators.peek() != ')') {
                prefix += operators.pop();
            }
            if (!operators.isEmpty()) {
                operators.pop(); 
            } else {
                cout << "Stack Underflow!" << endl;
            }
        } else  { 
            while (!operators.isEmpty() && precedence(ch) < precedence(operators.peek())) {
                prefix += operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.isEmpty()) {
        prefix += operators.pop();
    }

    string reversedPrefix;
    for (int i = prefix.length() - 1; i >= 0; --i) {
        reversedPrefix += prefix[i];
    }
    return reversedPrefix;

}

int main() {
    string infixExpression;
    cout << "Enter the infix expression: ";
    getline(cin, infixExpression);

    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Postfix expression: " << prefixExpression << endl;

    return 0;
}
