#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	int height;
	Node(int val)
	{
		data=val;
		left=right=NULL;
		height=0;
	}
};
Node *root=NULL;

//getHeight
int getHeight(Node* node)
{	
	if(node==NULL)
	{
		return 0;
	}
	return node->height;
}
//getBalancefactor
int getBalancefactor(Node* node)
{
	if(node==NULL)
	{
		return 0;
	}
	return getHeight(node->left)-getHeight(node->right);
}
//leftRotation
Node* leftRotation(Node* z)
{
	Node* y=z->right;
	Node* t3=y->left;
	
	y->left=z;
	z->right=t3;
	
	z->height=1+max(getHeight(z->left),getHeight(z->right));
	y->height=1+max(getHeight(y->left),getHeight(y->right));	
	
	return y;
}
//RightRotation
Node* rightRotation(Node* z)
{
	Node* y=z->left;
	Node* t3=y->right;
	
	y->right=z;
	z->left=t3;
	
	z->height=1+max(getHeight(z->left),getHeight(z->right));
	y->height=1+max(getHeight(y->left),getHeight(y->right));	
	
	return y;
}

//Node* insert
Node* insert(Node* node,int val)
{
	if(node==NULL)
	{
		return new Node(val);
	}
	else if(val<node->data)
	{
		node->left=insert(node->left,val);
	}
	else if(val>node->data)
	{
		node->right=insert(node->right,val);
	}
	else
	{
		return node;
	}
	node->height=1+max(getHeight(node->left),getHeight(node->right));
	
	int bf=getBalancefactor(node);
	
	//LL
	if(bf>1 && val<node->left->data)
	{
		return rightRotation(node);
	}
	//LR
	if(bf>1 && val>node->left->data)
	{
		node->left=rightRotation(node->left);
		return leftRotation(node);
	}
	//RR
	if(bf<-1 && val>node->right->data)
	{
		return leftRotation(node);
	}
	//RL
	if(bf<-1 && val<node->right->data)
	{
		node->right=leftRotation(node->right);
		return rightRotation(node);
	}
	return node;
}

void insert(int val)
{
	root=insert(root,val);
}
//inorder
void inorderTraversal(Node* node)
{
	if (node == NULL)
    {
        return;
    }
    inorderTraversal(node->left);
    cout << node->data << " "<< "Height of our node is: " << node->height << endl;
    inorderTraversal(node->right);
}
int main()
{
    insert(30);
    insert(20);
    insert(40);
    insert(10);
    insert(25);
    insert(35);
    insert(50);

    cout << "Inorder Traversal of the AVL Tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}