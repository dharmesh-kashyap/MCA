#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
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

    void insertSorted(int x)
    {
        Node *newNode = new Node(x);
        if (head == nullptr || x <= head->data)
        {
            newNode->next = head;
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr && current->next->data < x)
            {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr)
                current->next->prev = newNode;
            current->next = newNode;
        }
    }

    void deleteNode(int x)
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        if (head->data == x)
        {
            Node *temp = head;
            head = head->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete temp;
            cout << "Node with data " << x << " deleted." << endl;
            return;
        }

        Node *current = head;
        while (current->next != nullptr && current->next->data != x)
        {
            current = current->next;
        }

        if (current->next == nullptr)
        {
            cout << "Node not found." << endl;
            return;
        }

        Node *temp = current->next;
        current->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = current;
        delete temp;
        cout << "Node with data " << x << " deleted." << endl;
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
        cout << "\n 1. Insert a node in sorted order\n 2. Delete a node\n 3. Display nodes\n 4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data for the new node: ";
            int d;
            cin >> d;
            l.insertSorted(d);
            break;
        case 2:
            cout << "Enter the data of the node to delete: ";
            cin >> d;
            l.deleteNode(d);
            break;
        case 3:
            l.display();
            break;
        case 4:
            cond = false;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (cond);

    return 0;
}
