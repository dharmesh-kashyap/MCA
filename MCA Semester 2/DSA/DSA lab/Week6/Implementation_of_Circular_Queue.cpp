#include <iostream>
using namespace std;

class Queue
{
    int *arr, front, rear, capacity;

public:
    Queue(int cap)
    {
        capacity = cap;
        front = -1;
        rear = -1;
        arr = new int[capacity];
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear +1) % capacity == front;
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "\nThe Queue is full\n";
            return;
        }
        else
        {
            if (isEmpty())
            {
                front = 0;
            }
            rear = (rear+1)%capacity;
            arr[rear] = x;
        }
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "\nThe queue is empty\n";
            return 0;
        }
        int temp = arr[front];
        front = (front + 1) % capacity;
        return temp;
    }

   void DisplayQ()
    {
        if (isEmpty())
        {
            cout << "\nThe Queue is empty\n";
            return;
        }
        cout << "\nThe Queue is :\n";
        int i = front;
        do
        {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        } while (i != (rear + 1) % capacity);
        cout << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\nThe Queue is empty\n";
            return;
        }
        cout << "\nThe value at front is: " << arr[front];
        cout << "\nThe value at rear is: " << arr[rear]<<endl;
    }
};

int main()
{
    system("cls");
    int m, choice;

    cout << "Enter the Capacity: ";
    cin >> m;

    Queue Q(m);

do
{
    cout<<"\n----------Menu----------\n1. Push elements\n2. Pop element\n3. Display the queue\n4. Display The front and Rear\n5. Exit\n";
    cout<<"Enter the choice: ";
    cin>>choice;

    switch(choice){
        case 1:
        int j;
        cout<<"Enter the element: ";
        cin>>j;
        Q.push(j);
        break;

        case 2: 
        cout<<"The Popped element is: "<<Q.pop()<<endl;
        break;

        case 3: 
        Q.DisplayQ();
        break;

        case 4:
        Q.display();
        break;

        case 5:
        cout<<"Exiting the Loop";
        break;

        default: 
        cout<<"Enter a valid choice\n";
        break;
    }
    
} while (choice!=5);
    return 0;
}