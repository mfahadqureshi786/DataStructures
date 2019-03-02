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
	if(a>b)
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
		
		int findHeight(struct Node *root)
	{
	if(root==0)	
	{
		return -1;
	}
	else return 1+max(findHeight(root->left),findHeight(root->right));
	}
	
		int balanceFact(struct Node *root)
	{
		return findHeight(root->left)-findHeight(root->right);
	}
	
	Node *leftRotate(struct Node *root)
	{
		struct Node* newRoot=root->right;
		root->right=root->right->left;
        newRoot->left=root;
        newRoot->height=findHeight(newRoot);
        root->height=findHeight(root);
        return newRoot;
	}
		Node *rightRotate(struct Node *root)
	{
		
		struct Node* newRoot=root->left;
		root->left=root->left->right;
        newRoot->right=root;
        newRoot->height=findHeight(newRoot);
        root->height=findHeight(root);
        return newRoot;
		
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
				if(findHeight(root->left->left)>findHeight(root->left->right))
					root=rightRotate(root);
				else
				{
					root->left=leftRotate(root);
					root=rightRotate(root);
				}
			}
			else if(balanceF<-1)
			{
				if(findHeight(root->right->right)>findHeight(root->right->left)){
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
	int size(Node *root)
	{
		if(root==0)
		return 0;
		int left=size(root->left);
		int right=size(root->right);
		return left+right+1;
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
AVL A,B;
A.root=A.insert(A.root,2);
A.root=A.insert(A.root,3);
B.root=B.insert(B.root,2);
B.root=B.insert(B.root,2);

//A.root=A.insert(A.root,5);
sameTree(A.root,B.root);
}
