#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* link;
    node(){}
    node(int val){
        this->data = val;
        this->link = NULL;
    }

};

class linkedlist{
    public:
    node *Head;
    node* tail;

    void insertAtTail(node* &tail, int val){

        node * temp = new node(val);
        tail -> link = temp;
        tail = temp;
    }
 
    void insertatHead(node* &head, int val){
        node* temp = new node(val);
        temp->link = head;
        head = temp;
    }

    void display(node* &head){
        node * temp1 = head;
        while( temp1 != NULL){
            cout<<temp1 -> data<<" ";
            temp1 = temp1->link; 
        }
        cout<<"\n";
    }

};

int main(){
    node* n1 = new node(22);
        
    //cout<<n1->data<<endl;
    //cout<<n1->link<<endl;
    node* tail = n1;
    linkedlist l;
    l.Head = n1;
    l.tail = n1;

    l.insertatHead(l.Head, 55);
    l.insertatHead(l.Head, 15);
    l.insertatHead(l.Head, 25);
    l.insertAtTail(l.tail, 4562);

    l.display(l.Head);



    return 0;
}