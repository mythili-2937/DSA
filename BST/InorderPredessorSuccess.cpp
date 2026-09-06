#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* root = NULL;
//Successor --> after current node Eg: 50 --> 60
//Predecessor --> before current node Eg: 50 --> 40
Node* inorderSuccessor(Node* root, int value)
{
    Node* successor = NULL;

    while (root != NULL)
    {
        if (value < root->data)
        {
            successor = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    return successor;
}
Node* inorderPredecessor(Node* root, int value)
{
    Node* predecessor = NULL;

    while (root != NULL)
    {
        if (value > root->data)
        {
            predecessor = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return predecessor;
}
Node* insert(Node* node, int val)
{
    if (node == NULL)
    {
        return new Node(val);
    }
    if (val < node->data)
    {
        node->left = insert(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = insert(node->right, val);
    }
    return node;
}
Node* findmin(Node* node)
{
    Node* current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
int main()
{
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int value = 50;
    Node* successor = inorderSuccessor(root, value);
    if (successor != NULL)
        cout << "Inorder Successor of " << value << " is: " << successor->data << endl;
    else
        cout << "Inorder Successor of " << value << " does not exist." << endl;

    Node* predecessor = inorderPredecessor(root, value);
    if (predecessor != NULL)
        cout << "Inorder Predecessor of " << value << " is: " << predecessor->data << endl;
    else
        cout << "Inorder Predecessor of " << value << " does not exist." << endl;

    return 0;
}