#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        cout << x << " pushed to the stack." << endl;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        Node *temp = top;
        top = top->next;
        int poppedValue = temp->data;
        delete temp;
        cout << poppedValue << " popped from the stack." << endl;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; 
        }

        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }

        Node *current = top;
        cout << "Stack: ";
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;
    int choice, value;

    do
    {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to push: ";
            cin >> value;
            stack.push(value);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            cout << "Top element: " << stack.peek() << endl;
            break;
        case 4:
            stack.display();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
