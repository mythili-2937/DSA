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

void sumAverage(Node* head)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }

    int sum = 0;
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        sum += temp->data;
        count++;
        temp = temp->next;
    }

    double average = (double)sum / count;

    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
}

int main()
{
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    sumAverage(head);

    return 0;
}