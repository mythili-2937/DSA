#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		Node(int val)
		{
			data=val;
			next=NULL;
		}
};
Node *head=NULL;
class LinkedList
{
	public:
		void insertBeg(int val)
		{
			Node* newNode=new Node(val);
			if(head==NULL)
			{
				head=newNode;
				return;
			}
			newNode->next=head;
			head=newNode;
		}

		void display()
        {
            
            Node* temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }
            cout<<head->data<<" (circular)";
            
        }
		
};
int main()
{
	LinkedList s;
	s.insertBeg(10);
	s.display();
	//s.removeBeg();
	//s.removeEnd();
	//s.removeVal(40);
	cout<<endl;
	s.search(55);
	//s.display();
	return 0;
}
