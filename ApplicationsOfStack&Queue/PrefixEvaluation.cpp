
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int evaluatePrefix(string exp)
{
    stack<int> s;

    // Scan from right to left
    for (int i = exp.length() - 1; i >= 0; i--)
    {
        char ch = exp[i];

        // If operand, push into stack
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }

        // If operator
        else
        {
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            switch (ch)
            {
                case '+':
                    s.push(a + b);
                    break;

                case '-':
                    s.push(a - b);
                    break;

                case '*':
                    s.push(a * b);
                    break;

                case '/':
                    s.push(a / b);
                    break;

                case '^':
                    s.push(pow(a, b));
                    break;
            }
        }
    }

    return s.top();
}

int main()
{
    string exp;

    cout << "Enter prefix expression: ";
    cin >> exp;

    cout << "Result = " << evaluatePrefix(exp);

    return 0;
}

