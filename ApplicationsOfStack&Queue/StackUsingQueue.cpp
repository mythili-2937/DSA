#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:

    void push(int val)
    {
        // Add new element to q2
        q2.push(val);

        // Move all elements from q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Deleted: " << q1.front() << endl;
        q1.pop();
    }

    void peek()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top: " << q1.front() << endl;
    }

    void display()
    {
        if (q1.empty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        queue<int> temp = q1;

        cout << "Stack: ";

        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    s.peek();

    s.pop();

    s.display();

    return 0;
}