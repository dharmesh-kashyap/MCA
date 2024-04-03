//Linked list
#include<iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node *next;

    Node(int x){
        data = x;
        next = nullptr ;
    }
};

class Linked{
    public: 
    Node *head;
     
    Linked(){
        head = nullptr;
    }

    void insert(int x){
       Node  *newNode = new Node(x);

       if(head == nullptr){
            head = newNode;
       }else {
        newNode->next = head;
        head = newNode;
       }
    }

    void Display(){
        Node *current = head;
        while(current != nullptr){
            cout<<current->data<<"->";
            current = current->next;
        }
        cout<<"nullptr";
    }
};
int main(){
    Linked L;
    L.insert(45);
    L.insert(45);
    L.insert(45);
    L.insert(45);
    L.insert(45);
    L.insert(45);
    L.insert(45);
    L.insert(45);
    L.Display();
    return 0;

}