
#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int evaluatePostfix(string exp)
{
    stack<int> s;

    for (char ch : exp)
    {
        // If operand, push into stack
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }

        // If operator, perform operation
        else
        {
            int b = s.top();
            s.pop();

            int a = s.top();
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

    cout << "Enter postfix expression: ";
    cin >> exp;

    cout << "Result = " << evaluatePostfix(exp);

    return 0;
}

