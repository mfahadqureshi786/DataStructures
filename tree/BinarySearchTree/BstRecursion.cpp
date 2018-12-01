#include<iostream>
using namespace std;
struct Node
{
	int data=0;
	Node *left=0;
	Node *right=0;
};
class Bst
{
	
	public:
		Node *root;
	Bst()
	{
		root=0;
	}
	Node* FindMin(Node *root)
	{
		while(root->left!=0)
		{
			root=root->left;
		}
		return root;
	}
	struct Node* insert(Node *root,int data)
	{
		if(root==0)
		{   root=new struct Node;
		    root->data=data;
		}
		else if(data<root->data)
		{
			root->left=insert(root->left,data);
		}
		else if(data>root->data)
		{
			root->right=insert(root->right,data);
		}
		return root;
	}
	Node* delNode(Node *root,int data)
	{	if(root==0)
	{
		return root;
	}
		else if(data<root->data)
		{
			root=delNode(root->left,data);
		}
		else if(data>root->data)
		{
			root=delNode(root->right,data);
		}
		else
		{
			//if its leaf Node
			if(root->left==0 &&root->right==0)
			{
				delete root;
				root=0;
			}
			//single child
			else if(root->left==0)
			{
				Node *temp=root->right;
				delete root;
				root=temp;
			}
			else if(root->right==0)
			{
				Node *temp=root->left;
				delete root;
				root=temp;
			}
			//two child
			else
			{
				Node *temp=FindMin(root->right);
				root->data=temp->data;
				root->right=delNode(temp,temp->data);
			}
			return root;
		}
	}
	void inOrder(Node *root)
	{
		if(root!=0)
		{
		inOrder(root->left);
		cout<<root->data<<' ';
		inOrder(root->right);
		}
	}
	void postOrder(Node *root)
	{
		if(root!=0)
		{
		inOrder(root->left);
		inOrder(root->right);
		cout<<root->data<<' ';
		}
	}
	int balanceFact(struct Node *root)
	{
		return findHeight(root->left)-findHeight(root->right);
	}
	int findHeight(struct Node *root)
	{
	if(root==0)	
	{
		return -1;
	}
	else return 1+max(findHeight(root->left),findHeight(root->right));
	}
};
int main()
{
	Bst A;
	A.root=A.insert(A.root,50);
	A.root=A.insert(A.root,40);
	A.root=A.insert(A.root,60);
	A.root=A.insert(A.root,20);
	//cout<<A.root->data; 
    A.postOrder(A.root);
}
