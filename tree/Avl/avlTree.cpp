#include<iostream>
using namespace std;
struct Node
{
	int data=0;
	Node *left=0;
	Node *right=0;
	int height=0;
};
int max(int a,int b)
{
	if(a<b)
	{ 
	return a;
	}
	return b;
}
class AVL
{
	public:
		struct Node *root;
		AVL()
		{
		root=0;		
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
	Node *leftRotate(struct Node *root)
	{
		struct Node* newRoot=root->right;
		root->right=newRoot->left;
        newRoot->left=root;
        newRoot->height=findHeight(newRoot);
        root->height=findHeight(root);
        return root;
	}
		Node *rightRotate(struct Node *root)
	{
		
		struct Node* newRoot=root->left;
		root->left=newRoot->right;
        newRoot->right=root;
        newRoot->height=findHeight(newRoot);
        root->height=findHeight(root);
        return root;
		
	}
		struct Node* insert(Node *root,int data)
	{
		if(root==0)
		{root=new struct Node;root->data=data;}
		else if(data<root->data)
			root->left=insert(root->left,data);
		else if(data>root->data)
			root->right=insert(root->right,data);
			int balanceF=balanceFact(root);
			//ll or lr case
			if(balanceF>1)
			{   //LL case
				if(root->left->left->height>=root->left->right->height)
				{
					root=rightRotate(root);
				}
				else
				{
					root->left=leftRotate(root);
					root=rightRotate(root);
				}
			}
			else if(balanceF<-1)
			{
				if(root->right->right->height >=root->right->left->height){
                root = leftRotate(root);
            }
			else{
                root->right = rightRotate(root->right);
                root = leftRotate(root);
                 }
			}
			else
			{
				root->height = findHeight(root);
			}
			
		return root;
		
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
};
int main()
{
AVL A;
A.root=A.insert(A.root,50);
A.root=A.insert(A.root,40);
A.root=A.insert(A.root,30);
A.root=A.insert(A.root,20);
A.inOrder(A.root);
}
