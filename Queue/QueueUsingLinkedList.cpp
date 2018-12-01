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
			void enqueue(int data)
			{
				if(head==0)
				{
					head=new struct Node;
					head->data=data;
					head->next=0;
				}
				else
				{
					struct Node *curr=head;
		            struct Node *prev=0;
					while(curr!=0)
					{   prev=curr;
						curr=curr->next;
					}
					prev->next=new struct Node;
					prev->next->data=data;
					
				}
			}
			int dequeue()
			{   
				if(head!=0)
				{
				struct Node *temp=head->next;	int tempData=0;
				tempData=head->data;
				delete head;
				head=temp;
				return tempData;
				}
			}
			void toString()
			{   struct Node *curr=head;
				while(curr!=0)
				{
				cout<<curr->data<<' ';
				curr=curr->next;	
				}
			}
};
int main()
{
	LinkedList A;
	A.enqueue(100);
	A.enqueue(200);
	A.enqueue(300);
	A.enqueue(400);
	A.dequeue();
	A.dequeue();
	A.toString();
}
