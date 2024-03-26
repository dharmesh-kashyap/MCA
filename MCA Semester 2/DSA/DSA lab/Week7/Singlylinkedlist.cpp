#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
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
        Node *newNode = new Node(x);
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

    void insertAtTail(int x)
    {
        Node *newNode = new Node(x);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertAtPosition(int pos, int x)
    {
        if (pos <= 0)
        {
            cout << "Invalid position." << endl;
            return;
        }

        if (pos == 1)
        {
            insertAtHead(x);
            return;
        }

        Node *newNode = new Node(x);
        Node *current = head;
        int count = 1;

        while (current != nullptr && count < pos - 1)
        {
            current = current->next;
            count++;
        }

        if (current == nullptr)
        {
            cout << "Position out of range." << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
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
        cout << "\n 1. Create a node at front\n 2. Create a node at tail\n 3. Insert at specific position\n 4. Display nodes\n 5. Exit\n";
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
            cout << "Enter the data for the new node: ";
            cin >> d;
            l.insertAtTail(d);
            break;
        case 3:
            int pos;
            cout << "Enter the position to insert: ";
            cin >> pos;
            cout << "Enter the data for the new node: ";
            cin >> d;
            l.insertAtPosition(pos, d);
            break;
        case 4:
            l.display();
            break;
        case 5:
            cond = false;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (cond);

    return 0;
}
