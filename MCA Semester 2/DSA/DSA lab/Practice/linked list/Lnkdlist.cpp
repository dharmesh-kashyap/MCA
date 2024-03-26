#include<iostream>
using namespace std;
class Node{
public : 
    int data;
    Node *next;
    Node *prev;

    Node(){
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
};

class linked{
    public: 
    Node *head;
    linked(){
        head = nullptr;
    }
    void insertAtHead(int x){
        Node *newNode;
        newNode->data = x;
        if(head == nullptr){
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    };

    void display() {
        Node* current_node = head;
        while (current_node != nullptr) {
            cout << current_node->data << " -> ";
            current_node = current_node->next;
        }
        cout << "nullptr" <<endl;
    }
};
int main(){
    // cout<<"Enter the number of nodes you want to create"<<endl;
    // int n;
    // cin>>n;
    // Node l[n];
    // cout<<"Enter the data in nodes :"<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cin>>l[i].data;
    //     l[i].next = &l[i+1];
    // }
    // cout<<"The data in linked list are: "<<l[0].data<<endl;
    // for (int i = 0; i < n-1; i++)
    // {
    //     cout<<"The data in linked list are: "<<l[i].next->data<<endl;
    // }
    linked l ;
    bool cond = true;
    do
    {
        int choice;
        cout<<"\n 1. Create a node at front\n 2. Create a node at end\n 3. Create a node at the specific location\n 4. List all nodes\n 5. List a at  "<<endl;
        cout<<"Enter the choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the data in node: ";
            int d;
            cin>>d;
            l.insertAtHead(d);
            break;
        case 2 : 
            l.display();
        break;
        
        default:
            break;
        }
    } while (cond);
    
    


}