#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
};

class linked
{
public:
    Node *head;

    linked()
    {
        head = nullptr;
    }

    void insertAtHead(int x)
    {
        Node *newNode = new Node(); // Allocate memory for the new node
        newNode->data = x;
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void display()
    {
        Node *current_node = head;
        while (current_node != nullptr)
        {
            cout << current_node->data << " -> ";
            current_node = current_node->next;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    linked l;
    bool cond = true;
    do
    {
        int choice;
        cout << "\n 1. Create a node at front\n 2. Display nodes\n 3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data for the new node: ";
            int d;
            cin >> d;
            l.insertAtHead(d);
            break;
        case 2:
            l.display();
            break;
        case 3:
            cond = false;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (cond);

    return 0;
}
