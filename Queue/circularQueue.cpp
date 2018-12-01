#include<iostream>
using namespace std;
class CircularQueue
{
	private:
		int front;
		int rear;
		int *arr;
		int len;
		public:
			CircularQueue(int size)
			{
				len=size;
				arr=new int[len];
				rear=front=-1;
			}
			int isEmpty()
			{
				if(rear=-1 &&front==-1)
				{
					return 1;
				}
				return 0;
			}
			void enqueue(int data)
			{
				if((rear+1)%len==front)
				{
					cout<<"Queue is Full";
				}
				else
				{
				if(front==-1)	
				front=0;
				rear=(rear+1)%len;
		        arr[rear]=data;
				}
			}
			int dequeue()
			{
				if(isEmpty())
				{
					cout<<"Queue is Empty";
				}
				else
				{
					if(front==rear)
					front=rear=-1;
					else
					front=(front+1)%len;
				}
			}
			void display()
			{
				for(int i=rear;i!=front-1;i=(i-1)%len)
				{
					cout<<arr[i]<<' ';
				}
			}
};
int main()
{
	CircularQueue A(3);
	A.enqueue(19);
	A.enqueue(19);
	A.enqueue(19);
	A.dequeue();
	A.dequeue();
	A.dequeue();
	A.dequeue();
    A.display();
}
