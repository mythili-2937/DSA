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

void nthFromEnd(Node* head, int n)
{
    Node* first = head;
    Node* second = head;

    for (int i = 0; i < n; i++)
    {
        if (first == NULL)
        {
            cout << "Invalid n";
            return;
        }

        first = first->next;
    }

    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    cout << n << "th node from end: " << second->data;
}

int main()
{
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    nthFromEnd(head, 2);

    return 0;
}