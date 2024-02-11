#include<iostream>
using namespace std;

class Queue{
    int *arr, front, rear, capacity;

public: 
    Queue(int cap){
        capacity = cap;
        front = -1;
        rear = -1;
        arr = new int[capacity];
    }

    ~Queue(){
        delete[] arr;
    }

    bool isFull(){
        return front == (rear+1)%capacity;
    }

    bool isEmpty(){
        return front == -1;
    }

    void push(int x){
        if (isFull())
        {
            cout<<"The queue is full\n";
            return;
        }
        else {
        if (isEmpty())
        {
            front = 0;
        }
        rear = (rear+1)%capacity;
        arr[rear]=x;
        }
    }

    int pop(){
        if (isEmpty())
        {
            cout<<"Queue is Empty";
            return 0;
        }
        int temp = arr[front];
        front = (front+1)%capacity;
        return temp;
    }

    void DisplayQ(){
        if (isEmpty())
        {
            cout<<"The Queue is Empty";
            return;
        }
        int i = front;
        do
        {
            cout<<arr[i]<<" ";
            i = (i+1)%capacity;
        } while (i!=(rear+1)%capacity); 
        cout<<endl; 
    }

    void display(){
        if (isEmpty())
        {
            cout<<"The Queue is empty";
            return;
        }
        cout<<"\nThe front is: "<<arr[front];
        cout<<"\nThe rear is: "<<arr[rear]<<endl;
    }
};

int main (){
    system("cls");
    int capacity, choice;
    cout<<"Enter the Capacity: ";
    cin>>capacity;

    Queue Q(capacity);

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
        cout<<"bakchod ho kya tum\n";
        break;
    }
    } while (choice!=5);
    



    return 0;
}