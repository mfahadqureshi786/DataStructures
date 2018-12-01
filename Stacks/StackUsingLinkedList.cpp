#include<iostream>
using namespace std;
struct Node
{
	int data=0;
	struct Node *next=0;
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
			void push(int data)
			{
				if(head==0)
				{
					head=new struct Node;
					head->data=data;
					head->next=0;
				}
				else
				{
					struct Node *newNode=new struct Node;
					newNode->data=data;
					newNode->next=head;
					head=newNode;
				}
			}
			int pop()
			{
				if(head!=0)
				{
					struct Node *temp=head;
					head=head->next;
					int tempData=temp->data;
					delete temp;
					return tempData;
				}
			}
			void toString()
			{   struct Node *curr=head;
				while(curr!=0)
				{
				cout<<curr->data<<'\n';
				curr=curr->next;	
				}
			}
};
int main()
{
	LinkedList A;
	//A.push(100);
	//A.push(200);
	//A.push(300);
	//A.toString();
	//cout<<A.pop();
}
