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

bool isPalindrome(Node* head)
{
    int arr[100];
    int n = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        arr[n] = temp->data;
        n++;
        temp = temp->next;
    }

    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - i - 1])
            return false;
    }

    return true;
}

int main()
{
    Node* head = NULL;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);

    if (isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}