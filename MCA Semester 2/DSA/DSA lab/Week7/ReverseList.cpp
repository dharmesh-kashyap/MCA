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

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    void insert(int x)
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

    void reverseRecursive(Node *current, Node *prev)
    {
        if (current == nullptr)
        {
            head = prev;
            return;
        }

        Node *nextNode = current->next;
        current->next = prev;

        reverseRecursive(nextNode, current);
    }

    void reverse()
    {
        reverseRecursive(head, nullptr);
    }
};

int main()
{
    LinkedList l;
    int size, value;

    cout << "Enter the number of elements in the list: ";
    cin >> size;

    cout << "Enter " << size << " elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> value;
        l.insert(value);
    }

    cout << "Original list:" << endl;
    l.display();

    l.reverse();

    cout << "Reversed list:" << endl;
    l.display();

    return 0;
}
