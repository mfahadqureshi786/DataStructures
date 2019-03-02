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
else if(head->getData()>=data)
{
Node *curr=head;
Node *temp=new Node(data);
temp->setNextNode(head);
head=temp;
}
else
{
Node *curr=head;
//Jab data is sorted and we find position to insert our node
while(curr->getNextNode()!=0 &&curr->getNextNode()->getData()<data)
{
curr=curr->getNextNode();
}
Node *newNode=new Node;
newNode->setNextNode(curr->getNextNode())	;
newNode->setData(data);
curr->setNextNode(newNode);
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
	LL.insert(6);
	LL.insert(5);
	LL.insert(8);
	LL.insert(9);
	LL.insert(7);
	LL.ToString();
}
