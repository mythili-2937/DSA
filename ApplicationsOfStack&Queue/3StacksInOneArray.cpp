#include <iostream>
using namespace std;

#define MAX 15

class ThreeStacks
{
    int arr[MAX];
    int top1, top2, top3;

public:

    ThreeStacks()
    {
        top1 = -1;
        top2 = 4;
        top3 = 9;
    }

    // Stack 1
    void push1(int val)
    {
        if (top1 == 4)
        {
            cout << "Stack 1 is full\n";
            return;
        }

        arr[++top1] = val;
    }

    void pop1()
    {
        if (top1 == -1)
        {
            cout << "Stack 1 is empty\n";
            return;
        }

        cout << "Deleted: " << arr[top1--] << endl;
    }

    void peek1()
    {
        if (top1 == -1)
        {
            cout << "Stack 1 is empty\n";
            return;
        }

        cout << "Top: " << arr[top1] << endl;
    }

    // Stack 2
    void push2(int val)
    {
        if (top2 == 9)
        {
            cout << "Stack 2 is full\n";
            return;
        }

        arr[++top2] = val;
    }

    void pop2()
    {
        if (top2 == 4)
        {
            cout << "Stack 2 is empty\n";
            return;
        }

        cout << "Deleted: " << arr[top2--] << endl;
    }

    void peek2()
    {
        if (top2 == 4)
        {
            cout << "Stack 2 is empty\n";
            return;
        }

        cout << "Top: " << arr[top2] << endl;
    }

    // Stack 3
    void push3(int val)
    {
        if (top3 == 14)
        {
            cout << "Stack 3 is full\n";
            return;
        }

        arr[++top3] = val;
    }

    void pop3()
    {
        if (top3 == 9)
        {
            cout << "Stack 3 is empty\n";
            return;
        }

        cout << "Deleted: " << arr[top3--] << endl;
    }

    void peek3()
    {
        if (top3 == 9)
        {
            cout << "Stack 3 is empty\n";
            return;
        }

        cout << "Top: " << arr[top3] << endl;
    }

    void display1()
    {
        cout << "Stack 1: ";

        for (int i = top1; i >= 0; i--)
            cout << arr[i] << " ";

        cout << endl;
    }

    void display2()
    {
        cout << "Stack 2: ";

        for (int i = top2; i >= 5; i--)
            cout << arr[i] << " ";

        cout << endl;
    }

    void display3()
    {
        cout << "Stack 3: ";

        for (int i = top3; i >= 10; i--)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main()
{
    ThreeStacks s;

    s.push1(10);
    s.push1(20);
    s.push1(30);

    s.push2(40);
    s.push2(50);
    s.push2(60);

    s.push3(70);
    s.push3(80);
    s.push3(90);

    s.display1();
    s.display2();
    s.display3();

    s.peek1();
    s.peek2();
    s.peek3();

    s.pop1();
    s.pop2();
    s.pop3();

    return 0;
}