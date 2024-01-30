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

string infixToPostfix(const string& infix) {
    string postfix;
    Stack operators(infix.length());

    for (int i = 0; i < infix.length(); ++i) {
        char ch = infix[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.isEmpty() && operators.peek() != '(') {
                postfix += operators.pop();
            }
            if (!operators.isEmpty()) {
                operators.pop(); 
            } else {
                cout << "Stack Underflow!" << endl;
            }
        } else  { 
            while (!operators.isEmpty() && precedence(ch) <= precedence(operators.peek())) {
                postfix += operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.isEmpty()) {
        postfix += operators.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter the infix expression: ";
    getline(cin, infixExpression);

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
