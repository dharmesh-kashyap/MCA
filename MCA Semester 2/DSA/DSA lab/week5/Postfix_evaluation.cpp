#include <iostream>
#include <string>
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
            cout << "\nStack is Full";
            return;
        }
        arr[++top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "\nThe stack is empty";
            return top = -1;
        }
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "\nThe stack is empty";
            return -1;
        }
        return arr[top];
    }
};

int evaluatePostfix(const string& postfixExpression) {
    stack operandStack(postfixExpression.length());

        for (int i = 0; i < postfixExpression.length(); i++)
        {
           char token = postfixExpression[i];
        if (token >= '0' && token <= '9')
        {
            operandStack.push(token - 48); // Convert char to int and push onto stack
        } 
        else if (token == '+' || token == '-' || token == '*' || token == '/') {
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
    cout << "\nResult: " << result << endl;

    return 0;
}
