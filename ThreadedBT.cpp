#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    bool lthread, rthread;
};

//------------------------------------------------
// CREATE NODE
//------------------------------------------------

Node* createNode(int val)
{
    Node* newNode = new Node;

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    newNode->lthread = false;
    newNode->rthread = false;

    return newNode;
}

//------------------------------------------------
// NORMAL BST INSERTION
//------------------------------------------------

Node* insert(Node* root, int val)
{
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);

    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

//------------------------------------------------
// CREATE THREADS
//------------------------------------------------

void createThread(Node* root, Node*& prev)
{
    if (root == NULL)
        return;

    // Go to left subtree
    createThread(root->left, prev);

    // Create left thread
    if (root->left == NULL)
    {
        root->lthread = true;
        root->left = prev;
    }

    // Create right thread of previous node
    if (prev != NULL && prev->right == NULL)
    {
        prev->rthread = true;
        prev->right = root;
    }

    prev = root;

    // Go to right subtree
    createThread(root->right, prev);
}

//------------------------------------------------
// SEARCH
//------------------------------------------------

Node* search(Node* root, int key)
{
    Node* temp = root;

    while (temp != NULL)
    {
        if (temp->data == key)
            return temp;

        if (key < temp->data)
        {
            if (temp->lthread == false)
                temp = temp->left;
            else
                break;
        }
        else
        {
            if (temp->rthread == false)
                temp = temp->right;
            else
                break;
        }
    }

    return NULL;
}

//------------------------------------------------
// INORDER
//------------------------------------------------

void inorder(Node* root)
{
    Node* temp = root;

    // Go to leftmost node
    while (temp != NULL && temp->lthread == false)
        temp = temp->left;

    while (temp != NULL)
    {
        cout << temp->data << " ";

        // If right is thread
        if (temp->rthread == true)
            temp = temp->right;

        // Otherwise go to leftmost
        // node of right subtree
        else
        {
            temp = temp->right;

            while (temp != NULL && temp->lthread == false)
                temp = temp->left;
        }
    }
}

//------------------------------------------------
// DELETE
//------------------------------------------------

Node* deleteNode(Node* root, int key)
{
    Node* parent = NULL;
    Node* temp = root;

    // Find the node
    while (temp != NULL && temp->data != key)
    {
        parent = temp;

        if (key < temp->data)
        {
            if (temp->lthread == false)
                temp = temp->left;
            else
                return root;
        }
        else
        {
            if (temp->rthread == false)
                temp = temp->right;
            else
                return root;
        }
    }

    if (temp == NULL)
    {
        cout << "Element not found\n";
        return root;
    }

    //------------------------------------------------
    // TWO CHILDREN
    //------------------------------------------------

    if (temp->lthread == false && temp->rthread == false)
    {
        Node* p = temp;
        Node* succ = temp->right;

        // Find inorder successor
        while (succ->lthread == false)
        {
            p = succ;
            succ = succ->left;
        }

        // Copy successor data
        temp->data = succ->data;

        // Now delete successor
        temp = succ;
        parent = p;
    }

    //------------------------------------------------
    // no children (leaf node)
    //------------------------------------------------

    if (temp->lthread == true && temp->rthread == true)
    {
        if (parent == NULL)
        {
            delete temp;
            return NULL;
        }

        if (parent->left == temp)
        {
            parent->lthread = true;
            parent->left = temp->left;
        }
        else
        {
            parent->rthread = true;
            parent->right = temp->right;
        }

        delete temp;
    }

    //------------------------------------------------
    // ONLY RIGHT CHILD
    //------------------------------------------------

    else if (temp->lthread == true)
    {
        Node* child = temp->right;

        if (parent == NULL)
            root = child;

        else if (parent->left == temp)
            parent->left = child;

        else
            parent->right = child;

        delete temp;
    }

    //------------------------------------------------
    // ONLY LEFT CHILD
    //------------------------------------------------

    else
    {
        Node* child = temp->left;

        if (parent == NULL)
            root = child;

        else if (parent->left == temp)
            parent->left = child;

        else
            parent->right = child;

        delete temp;
    }

    return root;
}

//------------------------------------------------
// MAIN
//------------------------------------------------

int main()
{
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Create threads
    Node* prev = NULL;
    createThread(root, prev);

    // Inorder
    cout << "Inorder: ";
    inorder(root);

    // Search
    int key;

    cout << "\nEnter element to search: ";
    cin >> key;

    if (search(root, key) != NULL)
        cout << "Element found\n";
    else
        cout << "Element not found\n";

    // Delete
    cout << "Enter element to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "Inorder after deletion: ";
    inorder(root);

    return 0;
}

