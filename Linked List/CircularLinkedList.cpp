#include<iostream>
using namespace std;
struct Node
{
int data;
Node *next;
};
class CircularLinkedList
{
	private:
	struct Node *head;
	public:
	CircularLinkedList()
	{
		head=0;
	}
	void del()
	{  if(head!=0 && head!=head->next) {
	
	   struct Node* curr=head->next;
	    struct Node* prev=curr;
		do
		{   if(curr!=0)
			{
				prev=curr;
			curr=curr->next;}
		}
		while(curr!=head);
		struct Node* newHead=head->next;
		prev->next=newHead;
		delete head;
		head=newHead;
	}
	else if(head!=0)
	{
	delete head;
	head=0;	
	}
		
	}
	void insert(int data) 
	{
		if(head==0)
		{
		head=new struct Node;
		head->data=data;
		head->next=head;
		}
		else
		{
	    struct Node* temp=head->next;
	    struct Node* prev=head;
	    while(temp!=head)
		{   prev=temp;
			temp=temp->next;
		}
		struct Node* newNode=new struct Node;
		newNode->data=data;
		prev->next=newNode;
		newNode->next=head;
		}
	}
	
	int counter(int data)
	{   int count=0;
		struct Node *curr=head;
		do
		{   if(curr!=0)
			{
			if(curr->data==data)
			count++;
			curr=curr->next;}
		}
		while(curr!=head);
	return count;	
	}
int GetNth(int num)	
{   struct Node* temp=head;
   for(int i=0;i<num &&temp!=0;i++)
   temp=temp->next;
   if(temp!=0)
	return temp->data;
	return -1;
}
	void Display()
	{
		struct Node *curr=head;
		do
		{   if(curr!=0)
			{
			cout<<curr->data<<',';
			curr=curr->next;}
		}
		while(curr!=head);
	}
	
};

int main()
{   
	CircularLinkedList obj;
	obj.insert(10);
	obj.insert(20);
	obj.insert(30);
	obj.insert(40);
	obj.insert(50);
	obj.insert(40);
	obj.insert(60);
	cout<<obj.GetNth(1)<<endl;
	cout<<obj.counter(40)<<endl;
	obj.Display();
}
