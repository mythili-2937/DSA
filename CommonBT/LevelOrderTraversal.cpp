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
}void levelOrder(Node* root)
{
    if(root == NULL)
        return;

    queue<Node*> q;

    q.push(root);

    while(!q.empty())
    {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if(current->left != NULL)
            q.push(current->left);

        if(current->right != NULL)
            q.push(current->right);
    }
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

    cout << "Level Order Traversal: ";
    levelOrder(root);

    return 0;
}