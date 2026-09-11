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

Node* merge(Node* head1, Node* head2)
{
    if (head1 == NULL)
        return head2;

    if (head2 == NULL)
        return head1;

    Node* result = NULL;

    if (head1->data < head2->data)
    {
        result = head1;
        result->next = merge(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = merge(head1, head2->next);
    }

    return result;
}

void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;

    insert(head1, 10);
    insert(head1, 30);
    insert(head1, 50);

    insert(head2, 20);
    insert(head2, 40);
    insert(head2, 60);

    Node* result = merge(head1, head2);

    cout << "Merged List: ";
    display(result);

    return 0;
}