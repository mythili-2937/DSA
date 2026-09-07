#include<iostream>
#include<queue>
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
bool isSymmetric(Node* left, Node* right)
{
    if (left == NULL && right == NULL)
        return true;
    if (left == NULL || right == NULL)
        return false;
    return (left->data == right->data) &&
           isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
}
bool isSymmetric(Node* root)
{
    if (root == NULL)
        return true;
    return isSymmetric(root->left, root->right);
}
int main()
{
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 15);

    if (isSymmetric(root))
        cout << "The binary tree is symmetric." << endl;
    else
        cout << "The binary tree is not symmetric." << endl;

    return 0;
}