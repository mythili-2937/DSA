#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Stack
{
    Node* top;
    public:
    Stack()
    {
        top=NULL;
    }
    void push(int val)
    {
        Node* newNode=new Node(val);
        if(isEmpty())
        {
            top=newNode;
            return;
        }
        newNode->next=top;
        top=newNode;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack Underflow";
            return;
        }
        Node* del=top;
        top=top->next;
        delete del;
    }
    bool isEmpty()
    {
        return top==NULL;
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty";
            return;
        }
        Node* temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty";
            return -1;
        }
        return top->data;
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