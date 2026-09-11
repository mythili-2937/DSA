#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool isPalindrome(string str)
{
    stack<char> s;
    queue<char> q;

    for (char ch : str)
    {
        s.push(ch);
        q.push(ch);
    }

    while (!s.empty())
    {
        if (s.top() != q.front())
            return false;

        s.pop();
        q.pop();
    }

    return true;
}

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str))
        cout << "Palindrome";
    else
        cout << "Not a Palindrome";

    return 0;
}