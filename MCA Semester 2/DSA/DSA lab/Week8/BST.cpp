#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST
{
private:
    Node *root;

    Node *insertRecursive(Node *rootNode, int value)
    {
        if (rootNode == nullptr)
        {
            return new Node(value);
        }

        if (value < rootNode->data)
        {
            rootNode->left = insertRecursive(rootNode->left, value);
        }
        else if (value >= rootNode->data)
        {
            rootNode->right = insertRecursive(rootNode->right, value);
        }

        return rootNode;
    }

    void preorderRecursive(Node *rootNode)
    {
        if (rootNode != nullptr)
        {
            cout << rootNode->data << " ";
            preorderRecursive(rootNode->left);
            preorderRecursive(rootNode->right);
        }
    }

    void inorderRecursive(Node *rootNode)
    {
        if (rootNode != nullptr)
        {
            inorderRecursive(rootNode->left);
            cout << rootNode->data << " ";
            inorderRecursive(rootNode->right);
        }
    }

    void postorderRecursive(Node *rootNode)
    {
        if (rootNode != nullptr)
        {
            postorderRecursive(rootNode->left);
            postorderRecursive(rootNode->right);
            cout << rootNode->data << " ";
        }
    }

public:
    BST()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        root = insertRecursive(root, value);
    }
    void preorderTraversal()
    {
        cout << "Preorder Traversal: ";
        preorderRecursive(root);
        cout << endl;
    }

    void inorderTraversal()
    {
        cout << "Inorder Traversal: ";
        inorderRecursive(root);
        cout << endl;
    }

    void postorderTraversal()
    {
        cout << "Postorder Traversal: ";
        postorderRecursive(root);
        cout << endl;
    }
};

int main()
{
    BST bst;
    bool cond = true;

    do
    {
        int choice;
        cout << "\nBinary Search Tree Operations:\n";
        cout << "1. Insert a node\n";
        cout << "2. Preorder Traversal\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter the value to insert: ";
            cin >> value;
            bst.insert(value);
            break;
        case 2:
            bst.preorderTraversal();
            break;
        case 3:
            bst.inorderTraversal();
            break;
        case 4:
            bst.postorderTraversal();
            break;
        case 5:
            cond = false;
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (cond);

    return 0;
}
