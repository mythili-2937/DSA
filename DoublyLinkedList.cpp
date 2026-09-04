#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		Node *prev;
		Node(int val)
		{
			data=val;
			next=NULL;
			prev=NULL;
		}
};
Node *head=NULL;
class DoublyLinkedList
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
			head->prev=newNode; 
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
			newNode->prev=temp;
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
			newNode->prev=temp;  //A= temp , B=temp->next
			newNode->next=temp->next;
			temp->next=newNode;
			temp->next->prev=newNode;
			/*
			newNode->prev = A;
			newNode->next = B;

			A->next = newNode;
			B->prev = newNode;
			*/
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
			head->prev=NULL;
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
			while(temp!=NULL && temp->data!=val)
			{
				temp=temp->next;
			}
			if(temp==NULL)
			{
				cout<<"Data not found";
				return;
			}
			if(temp->next == NULL)
   			{
        		removeEnd();
        		return;
    		}
			Node* del=temp;
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
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
	DoublyLinkedList s;
	s.insertBeg(10);
	s.insertEnd(30);
	s.insertPos(40,2);
	s.insertEnd(50);
	s.insertEnd(100);
	s.insertEnd(35);
	s.display();
	s.removeBeg();
	s.removeEnd();
	s.removeVal(40);
	cout<<endl;
	//s.search(55);
	s.display();
	return 0;
}
