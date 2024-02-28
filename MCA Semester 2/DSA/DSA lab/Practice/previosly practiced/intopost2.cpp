#include<iostream>
using namespace std;

struct stack{
    int capacity;
    char *arr;
    int top;

    stack(int size){
        capacity = size;
        top = -1;
        arr = new char[capacity];
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

int prec(char c){
    if (c == '^') {
        return 3;
    }
    else if ( c == '/' || c == '*' ){
        return 2;
    }
    else if ( c == '+' || c == '-' ){
        return 1;
    }
    else {
        return -1;
    }
}

char assoc(char c){
    if (c == '^'){
        return 'R';
    }
    return 'L';
}

void infixtopostfix(string s){
    stack s()
}


int main(){
   
    return 0;
}