#include<iostream>
using namespace std;
class node{
    public: 
    int data;
    node *next;

    node(){
        data  = 0;
        next = NULL;
    }
};

class Linkedlist{
    public: 
    node *head;
};

int main(){
    cout<<"Enter the Number of nodes: "<<endl;
    int n = 0;
    cin>>n;
    node nodes[n];

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the Data in node "<<i+1<<" : ";
        cin>>nodes[i].data;
    }

    Linkedlist l;
    cout<<"The data of all the nodes are: "<<endl;
    l.head = &nodes[0];
    cout<<l.head->data<<" ";
    for(int j = 0 ; j < n-1; j++){
        nodes[j].next = &nodes[j+1];
        cout<<nodes[j].next->data<<" ";
    }
    return 0;

}