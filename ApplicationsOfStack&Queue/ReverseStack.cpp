#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int>& s)
{
    stack<int> temp;
    while (!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }
    s = temp;
}
int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<"Original Stack: ";

    stack<int> t = s;

    while (!t.empty())
    {
        cout << t.top() << " ";
        t.pop();
    }

    reverseStack(s);

    cout << "\nReversed Stack: ";

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

