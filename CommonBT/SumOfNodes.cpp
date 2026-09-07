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
int Sum(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->data + Sum(node->left) + Sum(node->right);
}
int main()
{
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 18);

    int totalSum = Sum(root);
    cout << "Sum of all nodes in the binary tree: " << totalSum << endl;

    return 0;
}