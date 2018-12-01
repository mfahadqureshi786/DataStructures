#include<iostream>
using namespace std;
struct Node
{
	int data=0;
	Node *left=0;
	Node *right=0;
};
class BST
{
	private:
	public:
		Node *root;
		Bst()
		{
			root=0;
		}
		Node* FindMin(Node *ptr)
		{   Node *prev=0;
			while(ptr!=0)
			{
				prev=ptr;
				ptr=ptr->left;
			}
			return prev;
		}
		void insert(int data)	
		{
			if(root==0)
			{
				root=new struct Node;
				root->data=data;
			}
			else{
			
			Node *curr=root,*prev=0;
			int setLeft=0;
			while(curr!=0)
			{
				prev=curr;
				if(data<curr->data)
				{
				setLeft=1;
				curr=curr->left;
				}
				else
				{
					setLeft=0;
					curr=curr->right;
				}
			}
			if(setLeft==1)
			{
				prev->left=new Node;
				prev->left->data=data;
			}
			else
			{
				prev->right=new Node;
				prev->right->data=data;
			}
		}
}
void inOrder(Node *curr)
{
	if(curr!=0)
	{
		inOrder(curr->left);
		cout<<curr->data<<',';
		inOrder(curr->right);
	}
}
void postOrder(Node *curr)
{
	if(curr!=0)
	{
		postOrder(curr->left);
		postOrder(curr->right);
		cout<<curr->data<<',';
	}
}
Node* delNode(struct Node* root,int data)
{    
if(root==0)
{
	return root;
}
else if(data<root->data)
root->left=delNode(root->left,data);
else if(data>root->data)
root->right=delNode(root->right,data);
else
{   //Leaf Node
	if(root->left==0 &&root->right==NULL)
	{
		delete root;
		root=0;
	}
	//One Child
	else if(root->left==0)
	{
		Node* temp=root;
		root=root->right;
		delete temp;
		
	}
	else if(root->right==0)
	{
		Node* temp=root;
		root=root->left;
		delete temp;
		
	}
	else
	{
		Node *suc=FindMin(root->right);
		root->data=suc->data;
		root->right=delNode(suc,suc->data);
	}
	return root;
}
}
};
int main()
{
	BST A;
	A.insert(50);
	A.insert(40);
	A.insert(60);
	A.insert(30);
    A.delNode(A.root,600);
	A.inOrder(A.root);
	A.postOrder(A.root);
}
