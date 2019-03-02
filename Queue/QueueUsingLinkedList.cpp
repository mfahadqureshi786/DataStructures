#include<iostream>
using namespace std;
struct Node
{
	bstNode *data=0;
	struct Node *next=0;
};
class LinkedList
{
	private:
		struct Node *head;
		int size;
		public:
			LinkedList()
			{
				head=0;
				size=0;
			}
			void enqueue(bstNode *ptr)
			{
				if(head==0)
				{
					head=new struct Node;
					head->data=ptr;
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
					prev->next->data=ptr;
					
				}
				size++;
			}
			bstNode* dequeue()
			{   
				if(head!=0)
				{
				struct Node *temp=head->next;	bstNode* tempData=0;
				tempData=head->data;
				delete head;
				head=temp;
				size--;
				return tempData;
				}
				
			}
			
			bool isEmpty()
			{
				if(this->size==0)
				{
					return true;
				}
				return false;
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
