#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class Linked1
{
public:
    Node *head;

    Linked1()
    {
        head = nullptr;
    }

    void addfront(int x)
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

    void display()
    {
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->data << "->";
            currentNode = currentNode->next;
        }
        cout << "nullptr" << endl;
    }
};

class Linked2
{
public:
    Node *head;

    Linked2()
    {
        head = nullptr;
    }

    void addfront(int x)
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

    void display()
    {
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->data << "->";
            currentNode = currentNode->next;
        }
        cout << "nullptr" << endl;
    }
};

class Linked3
{
public:
    Node *head;

    Linked3()
    {
        head = nullptr;
    }

    void addsorted(int x)
    {
        Node *newNode = new Node(x);
        if (head == nullptr || x <= head->data)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *currentnode = head;
            while (currentnode->next != nullptr && x > currentnode->next->data)
            {
                currentnode = currentnode->next;
            }
            newNode->next = currentnode->next;
            currentnode->next = newNode;
        }
    }

    void display()
    {
        Node *currentNode = head;
        while (currentNode != nullptr)
        {
            cout << currentNode->data << "->";
            currentNode = currentNode->next;
        }
        cout << "nullptr" << endl;
    }

    void deleteNode(int y)
    {
        if (head == nullptr)
        {
            cout << "Cannot delete node";
            return;
        }

        if (y == head->data)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "The node deleted with " << y << " data\n";
            return;
        }
        Node *currentNode = head;
        while (currentNode->next != nullptr && currentNode->next->data < y)
        {
            currentNode = currentNode->next;
        }
        if (currentNode->next == nullptr)
        {

            cout << "cannot delete node\n";
            return;
        }

        Node *temp = currentNode->next;
        currentNode->next = temp->next;

        delete temp;

        cout << "Deleted node with " << y << " data\n";
    }
};

int main()
{

    Linked1 L1;
    Linked2 L2;
    Linked3 L3;
    // cout<<"Enter the number of elements: "<<endl;
    // int n;
    // cin>>n;
    // cout<<"Enter the elements into Linked list 1 \n";
    // for (int i = 0; i < n; i++)
    // {
    //     int a;
    //     cin>>a;
    //     L1.addfront(a);
    // }

    // cout<<"Enter the elements into Linked list 2 \n";
    // for (int i = 0; i < n; i++)
    // {
    //     int a;
    //     cin>>a;
    //     L2.addfront(a);
    // }

    // Node* current = L1.head;
    // while (current != nullptr)
    // {
    //     L3.addsorted(current->data);
    //     current = current->next;
    // }

    // Node* currentn = L2.head;
    // while (currentn != nullptr)
    // {
    //     L3.addsorted(currentn->data);
    //     currentn = currentn->next;
    // }

    // cout<<"Linked list 1 elements: \n";
    // L1.display();
    // cout<<"Linked list 2 elements: \n";
    // L2.display();
    // cout<<"Linked list 3 elements: \n";
    // L3.display();
    Node *current = L1.head;
    Node *currentn = L2.head;
    int a;
    int b;
    int d;
    bool cond = true;
    do
    {
        int choice;
        cout << "1. Enter the Elements in Linked list 1\n2. Enter the Element in Linked list 2\n3. Display all three Linked list\n4. Delete the Node from Linked list 3\n5. Exit  " << endl;
        cout << "Enter the Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element ";
            
            cin >> a;
            L1.addfront(a);
            break;
        case 2:
            cout << "Enter the element ";
           
            cin >> b;
            L2.addfront(b);
            break;
        case 3:
            
            while (current != nullptr)
            {
                L3.addsorted(current->data);
                current = current->next;
            }

           
            while (currentn != nullptr)
            {
                L3.addsorted(currentn->data);
                currentn = currentn->next;
            }

            cout << "Linked list 1 elements: \n";
            L1.display();
            cout << "Linked list 2 elements: \n";
            L2.display();
            cout << "Linked list 3 elements: \n";
            L3.display();

            break;
        case 4:
            cout<<"Enter the Element to delete: ";
            
            cin>>d;
            L3.deleteNode(d);
            break;
        case 5:
            cout<<"Exit.....";
            cond = false;
            break;
        default:
            cout << "Invalid choice";
            break;
        }
    } while (cond);
}