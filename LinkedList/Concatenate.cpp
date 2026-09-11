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

void concatenate(Node* head1, Node* head2)
{
    if (head1 == NULL)
    {
        head1 = head2;
        return;
    }

    Node* temp = head1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
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
    insert(head1, 20);
    insert(head1, 30);

    insert(head2, 40);
    insert(head2, 50);
    insert(head2, 60);

    concatenate(head1, head2);

    cout << "Concatenated List: ";
    display(head1);

    return 0;
}