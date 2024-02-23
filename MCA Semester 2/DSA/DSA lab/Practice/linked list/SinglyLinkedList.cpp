#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }
};

class linkedList
{
public:
    Node *Head;
};

int main()
{

    Node n1, n2, n3;

    n1.data = 1;
    n2.data = 2;
    n3.data = 3;

    linkedList L;
    L.Head = &n1;
    n1.next = &n2;
    n2.next = &n3;

    cout << "The Value of Data node n1: " << L.Head->data << "\n";
    cout << "The Value of Data node n2: " << n1.next->data << "\n";
    cout << "The Value of Data node n3: " << n2.next->data << "\n";

    return 0;
}