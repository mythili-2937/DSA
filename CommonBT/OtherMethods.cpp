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
void inorder(Node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" -> ";
    inorder(root->right);
}
int findMin(Node* root)
{
    if (root == NULL)
        return -1;

    while (root->left != NULL)
        root = root->left;

    return root->data;
}


int findMax(Node* root)
{
    if (root == NULL)
        return -1;

    while (root->right != NULL)
        root = root->right;

    return root->data;
}


int height(Node* root)
{
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}


int depth(Node* root)
{
    if (root == NULL)
        return -1;

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    return 1 + max(leftDepth, rightDepth);
}


int countNodes(Node* root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}


int CountLeafNodes(Node* root)
{
    if (root == NULL)
        return 0;

    // Node has no children
    if (root->left == NULL && root->right == NULL)
        return 1;

    return CountLeafNodes(root->left)
         + CountLeafNodes(root->right);
}


int countNonLeafNodes(Node* root)
{
    if (root == NULL)
        return 0;

    // Leaf node → not a non-leaf node
    if (root->left == NULL && root->right == NULL)
        return 0;

    return 1 + countNonLeafNodes(root->left)
             + countNonLeafNodes(root->right);
}


int countLeftSubtree(Node* root)
{
    if (root == NULL || root->left == NULL)
        return 0;

    return countNodes(root->left);
}


int countRightSubtree(Node* root)
{
    if (root == NULL || root->right == NULL)
        return 0;

    return countNodes(root->right);
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

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "Minimum value in the BST: " << findMin(root) << endl;
    cout << "Maximum value in the BST: " << findMax(root) << endl;
    cout << "Height of the BST: " << height(root) << endl;
    cout << "Depth of the BST: " << depth(root) << endl;
    cout << "Total number of nodes in the BST: " << countNodes(root) << endl;
    cout << "Total number of leaf nodes in the BST: " << CountLeafNodes(root) << endl;
    cout << "Total number of non-leaf nodes in the BST: " << countNonLeafNodes(root) << endl;
    cout << "Total number of nodes in the left subtree: " << countLeftSubtree(root) << endl;
    cout << "Total number of nodes in the right subtree: " << countRightSubtree(root) << endl;  

    return 0;
}