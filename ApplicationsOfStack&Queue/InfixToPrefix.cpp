#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;

    return 0;
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (char ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }

        else if (ch == '(')
        {
            s.push(ch);
        }

        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            s.pop();
        }

        else
        {
            while (!s.empty() &&
                   precedence(s.top()) > precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

string infixToPrefix(string infix)
{
    // Step 1: Reverse
    reverse(infix.begin(), infix.end());

    // Step 2: Swap '(' and ')'
    for (char &ch : infix)
    {
        if (ch == '(')
            ch = ')';
        else if (ch == ')')
            ch = '(';
    }

    // Step 3: Convert to postfix
    string prefix = infixToPostfix(infix);

    // Step 4: Reverse postfix
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main()
{
    string infix;

    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Prefix: " << infixToPrefix(infix);

    return 0;
}

