#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void removeLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // No loop
    if (slow != fast)
        return;

    // Step 2: Find starting point of loop
    slow = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Remove loop
    fast->next = NULL;
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
    Node* head = new Node{10, NULL};
    Node* second = new Node{20, NULL};
    Node* third = new Node{30, NULL};
    Node* fourth = new Node{40, NULL};

    head->next = second;
    second->next = third;
    third->next = fourth;

    // Creating loop
    fourth->next = second;

    removeLoop(head);

    cout << "List after removing loop: ";
    display(head);

    return 0;
}