#include<iostream>
using namespace std;
class Node{
    public: 
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};
class linked{
    public:
    Node *head;
    public: 
    linked(){
        head = nullptr;
    }
    
    void addfront(int x){
        Node* newNode = new Node(x);
        if(head == nullptr){
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }
    void display(){
        Node* currentnode = head;
        while (currentnode != nullptr)
        {
            cout<<currentnode->data<<"->";
            currentnode = currentnode->next;
        }
        cout<<"nullptr"<<endl;
    }

};

class linked2{
    public:
    Node *head;
    public: 
    linked2(){
        head = nullptr;
    }
    
    void addfront(int x){
        Node* newNode = new Node(x);
        if(head == nullptr){
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }
    void display(){
        Node* currentnode = head;
        while (currentnode != nullptr)
        {
            cout<<currentnode->data<<"->";
            currentnode = currentnode->next;
        }
        cout<<"nullptr"<<endl;
    }

};

class linked3{
    public:
    Node *head;
    public: 
    linked3(){
        head = nullptr;
    }
    
    void addSorted(int x){
    Node* newNode = new Node(x);
    if(head == nullptr){
         head = newNode;
    }
    else if (x <= head->data){
         newNode->next = head;
         head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < x)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


    void display(){
        Node* currentnode = head;
        while (currentnode != nullptr)
        {
            cout<<currentnode->data<<"->";
            currentnode = currentnode->next;
        }
        cout<<"nullptr"<<endl;
    }

};
int main() {

    linked L1;
    linked2 L2;
    linked3 L3;

    cout<<"Enter the number of elements: for linked 1 and linked 2 "<<endl;
    int n ;
    cin>>n;

    cout<<"Enter the Linked 1 elements: "<<endl;
    for(int i = 0 ; i < n ; i++){
        int a;
        cin>>a;
        L1.addfront(a);
    }

    cout<<"Enter the Linked 2 elements: "<<endl;
    for(int i = 0 ; i < n ; i++){
        int a;
        cin>>a;
        L2.addfront(a);
    }

    cout<<"Linked 1 elements: "<<endl;
    L1.display();

    cout<<"Linked 2 elements: "<<endl;
    L2.display();

   Node* current = L1.head;
while (current != nullptr)
{
    L3.addSorted(current->data);
    current = current->next;
}

Node* newCurrent = L2.head;
while (newCurrent != nullptr)
{
    L3.addSorted(newCurrent->data);
    newCurrent = newCurrent->next;
}

   cout<<"The Linked list 3 : \n";
   L3.display();

}