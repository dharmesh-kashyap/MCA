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

class Linked1{
    public:
    Node *head;

    Linked1(){
        head = nullptr;
    }

    void addfront(int x){
        Node* newNode = new Node(x);
        if(head == nullptr){
            head = newNode;
        }else {
            newNode->next = head;
            head = newNode;
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
};

class Linked2{
    public:
    Node *head;

    Linked2(){
        head = nullptr;
    }

    void addfront(int x){
        Node* newNode = new Node(x);
        if(head == nullptr){
            head = newNode;
        }else {
            newNode->next = head;
            head = newNode;
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
};

class Linked3{
    public:
    Node *head;

    Linked3(){
        head = nullptr;
    }

    void addsorted(int x){
        Node* newNode = new Node(x);
        if (head == nullptr || x <= head->data)
        {
            newNode->next = head;
            head = newNode;
        }else{
            Node* currentnode = head;
            while (currentnode->next != nullptr && x > currentnode->next->data)
            {
                currentnode = currentnode->next;
            }
            newNode->next = currentnode->next;
            currentnode->next = newNode;
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
};

int main(){

    Linked1 L1;
    Linked2 L2;
    Linked3 L3;
    cout<<"Enter the number of elements: "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the elements into Linked list 1 \n";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        L1.addfront(a);
    }

    cout<<"Enter the elements into Linked list 2 \n";
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        L2.addfront(a);
    }

    Node* current = L1.head;
    while (current != nullptr)
    {
        L3.addsorted(current->data);
        current = current->next;
    }

    Node* currentn = L2.head;
    while (currentn != nullptr)
    {
        L3.addsorted(currentn->data);
        currentn = currentn->next;
    }
    cout<<"Linked list 1 elements: \n";
    L1.display();
    cout<<"Linked list 2 elements: \n";
    L2.display();
    cout<<"Linked list 3 elements: \n";
    L3.display();
    


    
}