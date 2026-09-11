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
    Node* temp = node;
    while (temp && temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* deleteNode(Node* node, int val)
{
    if (node == NULL)
    {
        return node;
    }
    if (val < node->data)
    {
        node->left = deleteNode(node->left, val);
    }
    else if (val > node->data)
    {
        node->right = deleteNode(node->right, val);
    }
    else
    {
        if (node->left == NULL)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findmin(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}
Node* search(Node* node, int val)
{
    if (node == NULL || node->data == val)
    {
        return node;
    }
    else if (val < node->data)
    {
        return search(node->left, val);
    }
    else
    {
        return search(node->right, val);
    }
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

    int key = 40;
    root = deleteNode(root, key);

    key = 100;
    Node* result = search(root, key);
    if (result != NULL)
        cout << "Found " << key << endl;
    else
        cout << key << " not found" << endl;

    return 0;
}
