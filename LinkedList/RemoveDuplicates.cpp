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

void removeDuplicates(Node* head)
{
    Node* current = head;

    while (current != NULL)
    {
        Node* prev = current;
        Node* temp = current->next;

        while (temp != NULL)
        {
            if (temp->data == current->data)
            {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }

        current = current->next;
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

    insert(head, 10);
    insert(head, 20);
    insert(head, 10);
    insert(head, 30);
    insert(head, 20);
    insert(head, 40);

    cout << "Before removing duplicates: ";
    display(head);

    removeDuplicates(head);

    cout << "\nAfter removing duplicates: ";
    display(head);

    return 0;
}