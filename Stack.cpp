#include<iostream>
using namespace std;
class Stack
{
    int top;
    int arr[100];
    public:
    Stack()
    {
        top=-1;
    }   
    void push(int val)
    {
        if(top==99)
        {
            cout<<"Stack Overflow";
            return;
        }
        top++;
        arr[top]=val;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow";
            return;
        }
        top--;
    }
    bool isEmpty()
    {
        return top==-1;
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty";
            return;
        }
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<" ";
        }
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty";
            return -1;
        }
        return arr[top];
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout<<endl;
    cout<<"Top element is: "<<s.peek()<<endl;
    s.pop();
    s.display();
    cout<<endl;
    cout<<"Is stack empty? "<<(s.isEmpty() ? "Yes" : "No")<<endl;
    return 0;
}