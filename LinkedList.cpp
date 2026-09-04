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
		void insertEnd(int val)
		{
			Node* newNode=new Node(val);
			if(head==NULL)
			{
				head=newNode;
				return;
			}
			Node* temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newNode;
		}
		void insertPos(int val,int pos)
		{
			if(pos<1)
			{
				cout<<"Invalid Position";
				return;				
			}
			if(pos==1)
			{
				insertBeg(val);
				return;
			}
			Node* newNode=new Node(val);
			Node *temp=head;
			for(int i=1;i<pos-1;i++)
			{
				temp=temp->next;
			}
			newNode->next=temp->next;
			temp->next=newNode;
		}
		void display()
		{
			
			Node* temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<" -> ";
				temp=temp->next;
			}
			cout<<"null";
			
		}
		void removeBeg()
		{
			if(head==NULL)
			{
				cout<<"Linked lIst is already empty";
				return;
			}
			if(head->next==NULL)
			{
				delete head;
				head=NULL;
				return;
			}
			Node* del=head;
			head=head->next;
			delete del;
		}
		void removeEnd()
		{
			if(head==NULL)
			{
				cout<<"Linked lIst is already empty";
				return;
			}
			if(head->next==NULL)
			{
				delete head;
				head=NULL;
				return;
			}
			Node* temp=head;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			Node* del=temp->next;
			temp->next=NULL;
			delete del;
			
		}
		void removeVal(int val)
		{
			if(head==NULL)
			{
				cout<<"Linked lIst is already empty";
				return;
			}
			if(head->data==val)
			{
				removeBeg();
				return;
			}
			Node* temp=head;
			while(temp->next!=NULL && temp->next->data!=val)
			{
				temp=temp->next;
			}
			if(temp->next==NULL)
			{
				cout<<"Data not found";
				return;
			}
			Node* del=temp->next;
			temp->next=temp->next->next;
			delete del;
			
		}
		void search(int val)
		{
			Node* temp=head;
			int pos=1;
			while(temp!=NULL)
			{
				if(temp->data==val)
				{
					cout<<val<<" is found at "<<pos<<endl;
					return;
				}
				temp=temp->next;
				pos++;
			}
			cout<<"\n"<<val<<" Data Not Found";
		}
		
};
int main()
{
	LinkedList s;
	s.insertBeg(10);
	s.insertEnd(30);
	s.insertPos(40,2);
	s.insertEnd(50);
	s.insertEnd(100);
	s.insertEnd(35);
	s.display();
	//s.removeBeg();
	//s.removeEnd();
	//s.removeVal(40);
	cout<<endl;
	s.search(55);
	//s.display();
	return 0;
}
