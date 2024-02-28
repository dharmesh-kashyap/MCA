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

int evaluatePrefix(const string& prefix) {
    stack operandStack(prefix.length());

    string reversedprefix;
    for (int i = prefix.length() - 1; i >= 0; --i) {
        reversedprefix += prefix[i];
    }

    for (int i = 0; i < reversedprefix.length(); ++i) {
        char token = reversedprefix[i];
        if (token >= '0' && token <= '9') {
            operandStack.push(token - '0'); // Convert char to int and push onto stack
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            int operand1 = operandStack.peek();
            operandStack.pop();
            int operand2 = operandStack.peek();
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
    system("cls");
    string prefix;
    cout << "Enter prefix expression: ";
    getline(cin, prefix);

    int result = evaluatePrefix(prefix);
    cout << "Result: " << result << endl;

    return 0;
}
