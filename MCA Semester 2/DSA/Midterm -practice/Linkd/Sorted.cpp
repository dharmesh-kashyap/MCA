#include<iostream>
using namespace std;
class Node{
    public: 
    int data;
    Node *next;
    Node(int x ){
        data = x;
        next = nullptr;
    }
};

class linked{
    Node* head;
    public: 
    linked(){
        head = nullptr;
    }

    void Insertion(int x){
        Node *newNode = new Node(x);

        if(head == nullptr){
            head = newNode;
        }else{
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
    linked L;

    L.Insertion(5);
    L.Insertion(45);
    L.Insertion(65);
    L.Insertion(85);
    L.Insertion(855);
    L.Insertion(65);

    L.Display();

    return 0;
}