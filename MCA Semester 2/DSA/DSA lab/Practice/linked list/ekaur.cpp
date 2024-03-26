#include<iostream>
using namespace std;
class node{
    public: 
    int data;
    node *next;
    node(){};
    node(int value){
        this->data = value;
        this->next = NULL;
    }
};

// void insertAtTail(node *&tail, int val){
//     node * temp2 = new node(val);
//     tail->next = temp2;
//     tail = temp2;
// }

void insertAtTail(node *&tail, int val){
    node *temp2 = new node(val);
    if (tail == nullptr) {
        tail = temp2;
        return;
    }

    node *current = tail;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = temp2;
    tail = temp2;
}



void insertAtHead(node *&head, int val ){
    
    node * temp = new node(val);
    temp->next = head;
    head = temp;
}

void display(node *&head){
    node *n = head;
    while (n!=NULL)
    {
        cout<<n->data<<" "; 
        n = n->next;
    }
    cout<<"\n";
    
}


int main(){
    node *head;
    node *tail;

    node *n; 
    n = new node();

    head = n;
    tail = n;

    cout<<"Enter the Number of nodes want to enter at head: ";
    int size;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cout<<"Enter the Value: ";
        int j;
        cin>>j;
        insertAtHead(head, j);
    }
    
    
    cout<<"Enter the Number of nodes want to enter at Tail: ";
    int size2;
    cin >> size2;

    for (int i = 0; i < size2; i++)
    {
        cout<<"Enter the Value: ";
        int j;
        cin>>j;
        insertAtTail(tail, j);
    }


    display(head);

    return 0;
}