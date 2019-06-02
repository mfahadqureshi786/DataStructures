#pragma once
#include<iostream>
using namespace std;
struct queueVertexNode
{
int vNo;
int distance;
int previous=-1;
bool isSource=false;	
bool isDequeued=false;
};
class Queue
{
private:
struct queueVertexNode *ptr;
int len;
int front;
int rear;
public:
Queue(int size)
{
	ptr=new queueVertexNode[size];
	front=rear=-1;
	len=size;
}
queueVertexNode* operator[](int idx)
{
	return &ptr[idx];
}
bool isEmpty()
{
	for(int i=0;i<len;i++)
	{
		if(ptr[i].isDequeued==false)
		return false;
	}
	return true;
}
bool isFull()
{
	if((rear+1)==len)
	return true;
	return false;
}
void enqueue(int vNo,int dist,int previous,bool isSource)
{
	if(isEmpty())
	{
		front=0;
	}
	if(!isFull())
	{
		rear++;
	    ptr[rear].vNo=vNo;
	    ptr[rear].distance=dist;
	    ptr[rear].previous=previous;
	    ptr[rear].isSource-isSource;
	}
}

queueVertexNode* deQueue()
{   
 int min=-1;
 int index=0;
	for(int i=0;i<len;i++)
	{
		if(ptr[i].isDequeued==false)
		{
			if(min==-1)
			{
		min=ptr[i].distance;
		index=i;
			}
			else if(ptr[i].distance<min)
			{
		min=ptr[i].distance;
		index=i;
			}
		
		}

	}
	ptr[index].isDequeued=true;
	return &ptr[index];
}
};
