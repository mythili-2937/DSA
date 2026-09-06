#include<iostream>
using namespace std;
class Queue
{
    int front;
    int rear;
    int arr[100];
    public:
    Queue()
    {
        front=-1;
        rear=-1;
    }   
    void enqueue(int val)
    {
        if(rear==99)
        {
            cout<<"Queue Overflow";
            return;
        }
        if(front==-1)
            front=0;
        rear++;
        arr[rear]=val;
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue Underflow";
            return;
        }
        front++;
        if(front>rear)
            front=rear=-1;
    }
    bool isEmpty()
    {
        return front==-1 || front>rear;
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty";
            return;
        }
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    int peek()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty";
            return -1;
        }
        return arr[front];
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
    cout<<"Front element: "<<q.peek()<<endl;
    q.dequeue();
    q.display();
    cout<<endl;
    cout<<"Front element: "<<q.peek()<<endl;
    return 0;
}
