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

class linked{
    Node *head;
    public:
    linked(){
        head = nullptr;
    }

    void sortedInsertion(int x){
        Node *newNode = new Node(x);

        if( head == nullptr || x <= head->data){
            newNode->next = head;
            head = newNode;
        } else {
            Node *current = head;
            while (current != nullptr && current->next->data < x )
            {
                current = current -> next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

    }
    
};
int main(){
    return 0;
}