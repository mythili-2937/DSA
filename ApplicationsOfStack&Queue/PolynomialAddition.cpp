//Polynomial Addition Using Linked List
#include <iostream>
using namespace std;

struct Node
{
    int coeff;      // coefficient
    int power;      // exponent
    Node* next;
};

// Create a new node
Node* createNode(int coeff, int power)
{
    Node* newNode = new Node;

    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;

    return newNode;
}

// Insert a term at the end
void insert(Node*& head, int coeff, int power)
{
    Node* newNode = createNode(coeff, power);

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

// Display polynomial
void display(Node* head)
{
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->coeff << "x^" << temp->power;

        if (temp->next != NULL)
            cout << " + ";

        temp = temp->next;
    }

    cout << endl;
}

// Add two polynomials
Node* addPolynomial(Node* p1, Node* p2)
{
    Node* result = NULL;

    while (p1 != NULL && p2 != NULL)
    {
        // Same powers ? add coefficients
        if (p1->power == p2->power)
        {
            insert(result,
                   p1->coeff + p2->coeff,
                   p1->power);

            p1 = p1->next;
            p2 = p2->next;
        }

        // p1 has greater power
        else if (p1->power > p2->power)
        {
            insert(result, p1->coeff, p1->power);
            p1 = p1->next;
        }

        // p2 has greater power
        else
        {
            insert(result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }

    // Copy remaining terms of p1
    while (p1 != NULL)
    {
        insert(result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    // Copy remaining terms of p2
    while (p2 != NULL)
    {
        insert(result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

int main()
{
    Node* p1 = NULL;
    Node* p2 = NULL;

    // P1 = 5x^3 + 4x^2 + 2
    insert(p1, 5, 3);
    insert(p1, 4, 2);
    insert(p1, 2, 0);

    // P2 = 3x^3 + 2x + 7
    insert(p2, 3, 3);
    insert(p2, 2, 1);
    insert(p2, 7, 0);

    cout << "Polynomial 1: ";
    display(p1);

    cout << "Polynomial 2: ";
    display(p2);

    Node* result = addPolynomial(p1, p2);

    cout << "Result: ";
    display(result);

    return 0;
}


/*
Polynomial 1: 5x^3 + 4x^2 + 2x^0
Polynomial 2: 3x^3 + 2x^1 + 7x^0
Result: 8x^3 + 4x^2 + 2x^1 + 9x^0
*/




