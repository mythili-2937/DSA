#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

bool detectLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
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

    // Creating a loop
    fourth->next = second;

    if (detectLoop(head))
        cout << "Loop detected";
    else
        cout << "No loop";

    return 0;
}