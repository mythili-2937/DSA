#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
void reverse(Node** head)
{
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current;       // Move prev to current
        current = next;       // Move to the next node
    }

    *head = prev; // Update the head pointer to the new first node
}
void display(Node* head)
{
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}
int main()
{
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original Linked List: ";
    display(head);

    reverse(&head);

    cout << "\nReversed Linked List: ";
    display(head);

    return 0;
}