#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s1, s2;

public:

    void enqueue(int val)
    {
        s1.push(val);
    }

    void dequeue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        // Move elements from s1 to s2
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Deleted: " << s2.top() << endl;
        s2.pop();
    }

    void peek()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Front: " << s2.top() << endl;
    }

    void display()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        // If s2 has elements, display them first
        stack<int> temp2 = s2;
        stack<int> temp1 = s1;

        cout << "Queue: ";

        // s2 top is the front
        while (!temp2.empty())
        {
            cout << temp2.top() << " ";
            temp2.pop();
        }

        // s1 needs to be displayed in reverse
        stack<int> reverse;

        while (!temp1.empty())
        {
            reverse.push(temp1.top());
            temp1.pop();
        }

        while (!reverse.empty())
        {
            cout << reverse.top() << " ";
            reverse.pop();
        }

        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    q.peek();

    q.dequeue();

    q.display();

    return 0;
}