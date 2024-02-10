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

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return rear == capacity -1;
    }

    void push(int x){
        if (isFull()){
            cout<<"The Queue is full\n";
            return;
        }
        else{
            if (isEmpty()){
                front = 0;
            }
            arr[++rear] = x;
        }
    }

    int pop(){
        if (isEmpty()){
            cout<<"The queue is empty\n";
            return 0;
        }
        int temp = arr[front++];
        if (front > rear){
            front = -1;
            rear = -1;
        }
        return temp;
    }

    void DisplayQ(){
        if (isEmpty()){
            cout<<"The Queue is empty\n";
            return;
        }
        cout<<"The Queue is :\n";
        for(int i = 0; i <= rear; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void display(){
        if (isEmpty()){
            cout<<"The Queue is empty\n";
            return;
        }
        cout<<"\nThe value at front is: "<<arr[front];
        cout<<"\nThe value at rear is: "<<arr[rear];
    }

};


int main(){
    int m;
    
    cout<<"Enter the Capacty: ";
    cin>>m;

    Queue Q(m);
    cout<<"\n";
    for (int i = 0; i < m; i++)
    {
        cout<<"Enter the element: ";
        int j;
        cin>>j;
        Q.push(j);
    }
    cout<<"\n";


    Q.DisplayQ();
    Q.display();
    cout<<"\n";

    cout<<"\n";
    while(!Q.isEmpty()){
        cout<<"The popped element is: "<<Q.pop()<<endl;
    }

    cout<<"\n";

    Q.DisplayQ();
    Q.display();

    return 0;
}