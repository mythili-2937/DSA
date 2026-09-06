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
    Node* current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
int kthSmallest(Node* root, int& k)
{
    if (root == NULL)
        return 0;

    int ans=kthSmallest(root->left, k);

    k--;

    if (k == 0)
    {
        ans = root->data;
        return ans;
    }

    ans=kthSmallest(root->right, k);
}
int kthLargest(Node* root, int& k)
{
    if (root == NULL)
        return 0;

    // Go to right subtree first
    int ans=kthLargest(root->right, k);

    // Visit current node
    k--;

    if (k == 0)
    {
        ans = root->data;
        return ans;
    }
    // Go to left subtree
  ans= kthLargest(root->left, k);

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

    int k = 3;
    cout << "Kth smallest element is: " << kthSmallest(root, k) << endl;

    k = 3;
    cout << "Kth largest element is: " << kthLargest(root, k) << endl;

    return 0;
}