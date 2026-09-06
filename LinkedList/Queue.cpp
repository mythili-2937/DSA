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
class Queue
{
    Node* front;
    Node* rear;
    public:
    Queue()
    {
        front=NULL;
        rear=NULL;
    }
    void enqueue(int val)
    {
        Node* newNode=new Node(val);
        if(isEmpty())
        {
            front=newNode;
            rear=newNode;
            return;
        }
        rear->next=newNode;
        rear=newNode;
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue Underflow";
            return;
        }
        Node* del=front;
        front=front->next;
        delete del;
        if(front==NULL)
            rear=NULL;
    }
    bool isEmpty()
    {
        return front==NULL;
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty";
            return;
        }
        Node* temp=front;
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
            cout<<"Queue is empty";
            return -1;
        }
        return front->data; 
    }
};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout<<endl;
    q.dequeue();
    q.display();
    cout<<endl;
    cout<<"Front element: "<<q.peek()<<endl;
}
    