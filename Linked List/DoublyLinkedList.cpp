#include<iostream>
using namespace std;
struct Node
{
int data;
Node *next;
Node *prev;
};
class LinkedList
{
	private:
	struct Node *head;
	public:
	LinkedList()
	{
		head=0;
	}
	void insert(int data) 
	{
		if(head==0)
		{
		head=new struct Node;
		head->data=data;
		head->next=0;
		head->prev=0;
		}
		else
		{
	    struct Node *newNode=new struct Node;	
	    newNode->data=data;
	    newNode->next=head;
	    newNode->prev=0;
	    head->prev=newNode;
	    head=newNode;
		}
	}
	void deleteNode()
	{
		struct Node* ptr=head;
		head=head->next;
		head->prev=NULL;
		delete ptr;
	}
	int GetNth(int index)
	{   int count=0;
		struct Node *curr=head;
	    for(int i=0;i<index && curr!=0;i++)
		{
			curr=curr->next;
		}
		if(curr!=0)
		return curr->data;
		return -1;
	}
	void Display()
	{
		struct Node *curr=head;
		while(curr!=0)
		{
			cout<<curr->data<<endl;
			curr=curr->next;
		}
	}
	void printfromEnd()
	{
		struct Node *curr=head;
		struct Node *prev=0;
		while(curr!=0)
		{
			prev=curr;
			curr=curr->next;
		}
		while(prev!=0)
		{
			cout<<prev->data<<endl;
			prev=prev->prev;
		
		}
	}
	int counter(int data)
	{   int count=0;
		struct Node *curr=head;
		
	    while(curr!=0)
		{
			if(curr->data==data)
			{
			count++;}
			curr=curr->next;
		}
	return count;	
	}
};

int main()
{
	LinkedList obj;
	obj.insert(50);
	obj.insert(30);
	obj.insert(25);
	obj.insert(30);
	obj.insert(30);
	cout<<obj.GetNth(4)<<endl;
	//obj.Display();
	//obj.printfromEnd();
    cout<<obj.counter(30);
}
