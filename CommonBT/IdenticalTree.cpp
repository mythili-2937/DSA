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

Node* root1 = NULL;
Node* root2 = NULL;

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
bool isIdent(Node* root1, Node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    return (root1->data == root2->data) &&
           isIdent(root1->left, root2->left) &&
           isIdent(root1->right, root2->right);
}
bool isIdentical(Node* root1, Node* root2)
{
    return isIdent(root1, root2);
}
int main()
{
    root1 = insert(root1, 10);
    root1 = insert(root1, 5);   
    root1 = insert(root1, 15);
    root1 = insert(root1, 3);
    root1 = insert(root1, 7);
    root1 = insert(root1, 12);
    root1 = insert(root1, 18);
    root2 = insert(root2, 10);
    root2 = insert(root2, 5);
    root2 = insert(root2, 15);
    root2 = insert(root2, 3);
    root2 = insert(root2, 7);
    root2 = insert(root2, 12);
    root2 = insert(root2, 18);

    if (isIdentical(root1, root2))
        cout << "The binary trees are identical." << endl;
    else
        cout << "The binary trees are not identical ." << endl;

    return 0;
}