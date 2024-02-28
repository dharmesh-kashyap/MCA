#include <iostream>
using namespace std;
class Stack
{
public:
    int top;
    int capacity;
    char *arr;

public:
    Stack(int cap)
    {
        top = -1;
        capacity = cap;
        arr = new char[capacity];
    }
    ~Stack()
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
    void push(char x)
    {
        if (isFull())
        {
            cout << "The stack is full" << endl;
            return;
        }
        arr[++top] = x;
    }
    char pop()
    {
        if (isEmpty())
        {
            cout << "The stack is Empty" << endl;
            return 0;
        }
        return arr[top--];
    }

    char peek()
    {
        if (isEmpty())
        {
            cout << "The stack is Empty" << endl;
            return 0;
        }
        return arr[top];
    }

    void Display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    int counter1 = 0;
    int counter2 = 0;
    char arr[100];
    char arr2[100];
    cout << "Enter the Word: ";
    cin >> arr;
    cout << "Enter the reverse Word: ";
    cin >> arr2;
    for (char index : arr)
    {
        if (index == '\0')
        {
            break;
        }
        counter1++;
    }

    for (char index : arr2)
    {
        if (index == '\0')
        {
            break;
        }
        counter2++;
    }
    int temp = counter1 + counter2 +1;
    Stack S1(temp);

    for (int i = 0; i < counter1; i++)
    {
            S1.push(arr[i]);
    }

    S1.push('c');

    for (int i = 0; i < counter2; i++)
    {
        S1.push(arr2[i]);
    }
  
    S1.Display();
    
    

    return 0;
}