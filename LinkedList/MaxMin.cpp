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

void findMaxMin(Node* head)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    int maximum = head->data;
    int minimum = head->data;

    Node* temp = head->next;

    while (temp != NULL)
    {
        if (temp->data > maximum)
            maximum = temp->data;

        if (temp->data < minimum)
            minimum = temp->data;

        temp = temp->next;
    }

    cout << "Maximum: " << maximum << endl;
    cout << "Minimum: " << minimum << endl;
}

int main()
{
    Node* head = NULL;

    insert(head, 40);
    insert(head, 10);
    insert(head, 50);
    insert(head, 20);
    insert(head, 30);

    findMaxMin(head);

    return 0;
}