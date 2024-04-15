#include<iostream>
using namespace std;
class Node{
    public: 
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }

};

class linked{
    Node *head;
    linked(){
        head = nullptr;
    }

    void addSorted(int x){
        Node* newNode = new Node(x);

        if(head == nullptr || x <= head->data ){
            newNode->next = head;
            head = newNode;
        }else{
            Node* current = head;
            while (current->next != nullptr && x >= current->next->data)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

    }

    void display(){
        Node* currentNode = head;
        while (currentNode != nullptr)
        {
            cout<<currentNode->data<<"->";
            currentNode = currentNode->next;
        }
        cout<<"nullptr"<<endl;
        
    }

    void addfront(int x){
        Node* newNode = new Node(x);
        if(head == nullptr){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }

    void addtail(int x){
        Node *NewNode = new Node(x);
        if (head == nullptr)
        {
            head = NewNode;
        }else{
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = NewNode;
        }
    }

    void insertatpos(int x, int pos){
        if(pos == 0){
            cout<<"Cannot enter a node";
            return;
        }
        if (pos == 1)
        {
            addfront(x);
            cout<<"Node entered\n";
            return;
        }
        Node* newnode = new Node(x);
        Node* current = head;
        int count = 1;
        while (current !=nullptr && count < pos-1)
        {
            current = current->next;
            count++;
        }
        if (current == nullptr)
        {
            cout<<"Position out of range"<<endl;
            return;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
    void deletenode(int x){
        if (head  == nullptr)
        {
            cout<<"Connot delete node";
            return;
        }
        if (x == head->data)
        {
            Node* temp = head; 
            head = head->next;
            delete temp;
            cout<<"Node deleted";
            return;
        }
        Node *current = head;
        while (current->next != nullptr && x != current->next->data )
        {
            current = current->next;
        }
        if (current->next == nullptr )
        {
            cout<<"Node not found";
            return;
        }
        Node* temp = current->next;
        current->next = temp->next;
        cout<<"Node delted";
        delete temp;

    }
};
int main(){
    return 0;
}