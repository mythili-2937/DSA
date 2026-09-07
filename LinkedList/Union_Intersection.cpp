#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insert(Node*& head, int val)
{
    Node* newNode = new Node{val, NULL};

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

bool search(Node* head, int val)
{
    while (head != NULL)
    {
        if (head->data == val)
            return true;
        head = head->next;
    }
    return false;
}

Node* Union(Node* head1, Node* head2)
{
    Node* result = NULL;

    Node* temp = head1;
    while (temp != NULL)
    {
        if (!search(result, temp->data))
            insert(result, temp->data);

        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL)
    {
        if (!search(result, temp->data))
            insert(result, temp->data);

        temp = temp->next;
    }

    return result;
}

Node* Intersection(Node* head1, Node* head2)
{
    Node* result = NULL;

    Node* temp = head1;

    while (temp != NULL)
    {
        if (search(head2, temp->data) &&
            !search(result, temp->data))
        {
            insert(result, temp->data);
        }

        temp = temp->next;
    }

    return result;
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}