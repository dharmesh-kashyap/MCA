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

   void sortedInsertion(int x){
    Node *newNode = new Node(x);

    if ( head==nullptr || x <= head->data ){
        newNode->next = head;
        head = newNode;
    }else{
        Node *current = head;
        while(current->next != nullptr && current->next->data < x ){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

   }

   void Delete(int x){
   if (head == nullptr){
        cout<<"Node can't be deleted \n";
   }

   if (head->data == x){
    Node *temp = head;
    head = head->next;
    delete temp;
    cout<<"Node with data "<<x<<" is deleted \n";
    return; 
   }

    Node *current = head;
    while(current != nullptr && current->next->data !=x ){
        current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    return ; 
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

    L.sortedInsertion(10);
    L.sortedInsertion(6);
    L.sortedInsertion(5);
    L.sortedInsertion(4);
    L.sortedInsertion(3);
    L.sortedInsertion(2);
    L.sortedInsertion(1);
    L.Display();
    return 0;
}