#include <iostream>
using namespace std;

#define SIZE 10

class TwoStacks
{
    int arr[SIZE];
    int top1, top2;

public:

    TwoStacks()
    {
        top1 = -1;
        top2 = SIZE;
    }

    // Stack 1 - Push
    void push1(int val)
    {
        if (top1 + 1 == top2)
        {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top1] = val;
    }

    // Stack 2 - Push
    void push2(int val)
    {
        if (top1 + 1 == top2)
        {
            cout << "Stack Overflow\n";
            return;
        }

        arr[--top2] = val;
    }

    // Stack 1 - Pop
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack 1 Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[top1--] << endl;
    }

    // Stack 2 - Pop
    void pop2()
    {
        if (top2 == SIZE)
        {
            cout << "Stack 2 Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[top2++] << endl;
    }

    // Display Stack 1
    void display1()
    {
        cout << "Stack 1: ";

        for (int i = 0; i <= top1; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Display Stack 2
    void display2()
    {
        cout << "Stack 2: ";

        for (int i = SIZE - 1; i >= top2; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
    //peek stack 1
    void peek1()
    {
        if (top1 == -1)
        {
            cout << "Stack 1 is empty\n";
            return;
        }

        cout << "Top of Stack 1: " << arr[top1] << endl;
    }
    //peek stack 2
    void peek2()
    {
        if (top2 == SIZE)
        {
            cout << "Stack 2 is empty\n";
            return;
        }

        cout << "Top of Stack 2: " << arr[top2] << endl;
    }
};

int main()
{
    TwoStacks s;

    s.push1(10);
    s.push1(20);
    s.push1(30);

    s.push2(90);
    s.push2(80);
    s.push2(70);

    s.peek1();
    s.peek2();
    
    s.display1();
    s.display2();

    s.pop1();
    s.pop2();

    s.display1();
    s.display2();

    return 0;
}