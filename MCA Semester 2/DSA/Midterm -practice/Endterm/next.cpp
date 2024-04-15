#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public: 
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class Linked1{
    public: 
    Node* head;

    Linked1(){
        head = nullptr;
    }

    void addfront(int x){
        Node* newNode = new Node(x);

        if(head == nullptr){
            head = newNode;
        }
        else{
        newNode->next = head;
        head = newNode;
        }
    }

    void display(){
        Node *current = head;
        while (current != nullptr)
        {
            cout<<current->data<<"->";
            current = current->next; 
        }
        cout<<"nullptr"<<endl;
    }

};

class Linked2{
    public: 
    Node* head;

    Linked2(){
        head = nullptr;
    }

    void addfront(int x){
        Node* newNode = new Node(x);

        if(head == nullptr){
            head = newNode;
        }
        else{
        newNode->next = head;
        head = newNode;
        }
    }

    void display(){
        Node *current = head;
        while (current != nullptr)
        {
            cout<<current->data<<"->";
            current = current->next; 
        }
        cout<<"nullptr"<<endl;
    }

};

class Linked3{
    public: 
    Node* head;

    Linked3(){
        head = nullptr;
    }

    void addSorted(int x){
        Node* newNode = new Node(x);

        if(head == nullptr || x < head->next->data){
            newNode->next = head; 
            head = newNode;
        }
        else{
        Node* currentNode = head;
        while (currentNode->next != nullptr && x > currentNode->next->data )
        {
            currentNode = currentNode->next;
        }

        newNode->next = currentNode->next;
        currentNode->next = newNode;
        
        }
    }

    void display(){
        Node *current = head;
        while (current != nullptr)
        {
            cout<<current->data<<"->";
            current = current->next; 
        }
        cout<<"nullptr"<<endl;
    }

};

int main(){
    Linked1 L1;
    Linked2 L2;
    Linked3 L3;

    cout<<"Enter the number of elements: \n";
    int n;
    cin>>n;

    cout<<"Enter the elements of Linked list 1: \n";
    for (int i = 0; i < n; i++)
    {
        int a ;
        cin>> a;
        L1.addfront(a);
    }

    cout<<"Enter the elements of Linked list 2: \n";
    for (int i = 0; i < n; i++)
    {
        int a ;
        cin>> a;
        L2.addfront(a);
    }

    L1.display();
    L2.display();

    Node* newNode = L1.head;
    while (newNode != nullptr)
    {
        L3.addSorted(newNode->data);
        newNode = newNode->next;
    }

    newNode = L2.head;
    while (newNode != nullptr)
    {
        L3.addSorted(newNode->data);
        newNode = newNode->next;
    }

    L3.display();
    
}