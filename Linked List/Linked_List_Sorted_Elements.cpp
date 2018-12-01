#include<iostream>
using namespace std;
class Node
{
private:
int data;
Node *nextNode;
public:
Node()
{
data=0;
nextNode=0;	
}
Node(int data)
{
this->data=data;
nextNode=0;	
}
int getData()
{
return data;	
}
void setData(int data)
{
this->data=data;	
}
Node* getNextNode()
{
return nextNode;	
}
void setNextNode(Node *ptr)	
{
nextNode=ptr;	
}
};
class LinkedList
{
private:
Node *head;

public:
LinkedList()
{
head=0;	
}
void insert(int data)
{
if(head==0)
{
head=new Node(data);
head->setNextNode(0);	
}

else
{
Node *curr=head;
//Jab head data >NewNode data
if(head->getData()>=data)
{
Node *temp=new Node(head->getData());
temp->setNextNode(head->getNextNode());

head->setData(data);
head->setNextNode(temp);
}
else
{


//Jab data is sorted and we find position to insert our node
while(curr!=0)
{
if(curr->getNextNode()!=0)
{

if(curr->getData()<=data && curr->getNextNode()->getData()>=data )
{
Node *NewNode=new Node(data);
NewNode->setNextNode(curr->getNextNode());
curr->setNextNode(NewNode);
break;
}
}
else if(curr->getData() <=data)
{
Node *NewNode=new Node(data);
curr->setNextNode(NewNode);
break;
}
curr=curr->getNextNode();
}
}
}	
}
void ToString()
{
Node *curr=head;
while(curr!=0)
{
cout<<curr->getData()<<" ";
curr=curr->getNextNode();	
}
	
}
	
};
int main()
{
	LinkedList LL;
	LL.insert(1);
	LL.insert(2);
	LL.insert(3);
	LL.insert(3);
	LL.insert(2);
	LL.insert(1);
	LL.ToString();
}
