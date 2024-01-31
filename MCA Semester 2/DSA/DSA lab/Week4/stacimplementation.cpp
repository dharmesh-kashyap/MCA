#include<iostream>
using namespace std;
struct stack{
    int capacity;
    int *arr;
    int top;

    stack(int size){
        capacity = size;
        top = -1;
        arr = new int[capacity];
    }
    ~stack(){
        delete[] arr;
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
int main(){
    int capacity;
    cout<<"Enter the capacity of stack: ";
    cin>>capacity;
    stack s(capacity);

    int d;

    for (int i = 0; i < capacity ; i++){
        cout<<"\nEnter the values: ";
        cin>>d;
        s.push(d);
    }

    cout<<s.pop()<<" This value is popped\n";
    cout<<s.peek()<<" This is the top value\n";
    
    return 0;
}