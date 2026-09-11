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

void sortList(Node* head)
{
    if (head == NULL)
        return;

    for (Node* i = head; i != NULL; i = i->next)
    {
        for (Node* j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
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
    Node* head = NULL;

    insert(head, 40);
    insert(head, 10);
    insert(head, 30);
    insert(head, 20);
    insert(head, 50);

    cout << "Before sorting: ";
    display(head);

    sortList(head);

    cout << "\nAfter sorting: ";
    display(head);

    return 0;
}