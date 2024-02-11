#include <iostream>
#include <string>
using namespace std;

#include <iostream>
using namespace std;
class stack
{
    int capacity;
    int *arr;
    int top;
public:
    stack(int size)
    {
        capacity = size;
        top = -1;
        arr = new int[capacity];
    }
    ~stack()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack is Full";
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "The stack is empty";
            return top = -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "The stack is empty";
            return -1;
        }
        return arr[top];
    }
};

int evaluatePostfix(const string& postfixExpression) {
    stack operandStack(postfixExpression.length());

    for (char token : postfixExpression) {
        if (isdigit(token)) {
            operandStack.push(token - '0'); // Convert char to int and push onto stack
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            int operand2 = operandStack.peek();
            operandStack.pop();
            int operand1 = operandStack.peek();
            operandStack.pop();

            int result;
            switch (token) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            operandStack.push(result);
        }
    }

    return operandStack.peek();
}

int main() {
    string postfixExpression;
    cout << "Enter postfix expression: ";
    getline(cin, postfixExpression);

    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
