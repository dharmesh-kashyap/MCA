#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node *next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

class Linked{
    Node *head;

    public: 
    Linked(){
        head = nullptr;
    }

    void insertSorted(int x){
         Node *newNode = new Node(x);

         if (head == nullptr || x <= head->data ){
            newNode->next = head;
            head = newNode;
         } else {
            Node *current = head;
            while(current != nullptr && current->next->data < x ){
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
          }

    }
    void display(){
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
    L.insertSorted(10);
    L.insertSorted(9);
    L.insertSorted(8);
    L.insertSorted(7);
    L.insertSorted(6);
    L.insertSorted(5);
    L.insertSorted(4);
    L.insertSorted(3);
    L.insertSorted(2);
    L.insertSorted(1);

    L.display();

    return 0;
}
