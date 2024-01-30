#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    char* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(const string& infix) {
    string postfix;
    Stack operators(infix.length());

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            while (!operators.isEmpty() && operators.peek() != '(') {
                postfix += operators.pop();
            }
            if (!operators.isEmpty()) {
                operators.pop(); // Discard '('
            } else {
                cout << "Stack Underflow!" << endl;
            }
        } else { // Operator
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
