#include<iostream>
#include<string.h>
using namespace std;
class node
{
private:
int data;
node *nextNode;
public:
	node()
	{
	data=0;
	nextNode=NULL;	
	}
node(int data)
{
this->data=data;
nextNode=NULL;	
}
int getData()
const
{
	return data;
}
void setData(int data)
{
	this->data=data;
}
node* getNextNode()
{
return nextNode;
}
void setNextNode(node *newNode)
{
this->nextNode=newNode;	
}

};
class LinkedList
{
private:

public:
node *head;
LinkedList()
{
head=0;	
}	
void insertBeg(int data)
{
	if(head==0)
	{
		head=new node(data);
	}
	else{
	
node *temp=new node;
temp->setData(head->getData());
temp->setNextNode(head->getNextNode());
head->setData(data);
head->setNextNode(temp);}
}
void deleteHead()
{
	if(lengthOf()==1)
	{
	head->setData(0);	
	}
	else
	{
	head=head->getNextNode();	
	}
}
 void reverse() 
    { 
        node* current = head; 
        node *prev = NULL, *next = NULL; 
        while (current != NULL) 
        { 
            // Store next 
            next = current->getNextNode(); 
  
            // Reverse current node's pointer 
            current->setNextNode(prev); 
  
            // Move pointers one position ahead. 
            prev = current; 
            current = next; 
        } 
        head = prev; 
    } 
    int counter(int data)
	{   int count=0;
		 node *curr=head;
		
	    while(curr!=0)
		{
			if(curr->getData()==data)
			{
			count++;}
			curr=curr->getNextNode();
		}
	return count;	
	}
	int GetNth(int index)
	{   int count=0;
		 node *curr=head;
	    for(int i=0;i<index && curr!=0;i++)
		{
			curr=curr->getNextNode();
		}
		if(curr!=0)
		return curr->getData();
		return -1;
	}
void toString()
{
node *current=head;
cout<<current->getData()<<" ";
current=current->getNextNode();
while(current!=0)
{
	cout<<current->getData()<<" ";
	current=current->getNextNode();
}
	
}
int lengthOf()
{
int i=1;
node *curr=head;
while(curr->getNextNode() !=NULL)
{
i++;
curr=curr->getNextNode();	
}
return i;	
}
	
};
int main()
{
	
LinkedList L;
L.insertBeg(20);
L.insertBeg(30);
L.insertBeg(40);
L.insertBeg(40);
L.insertBeg(50);
cout<<L.counter(40)<<endl;
cout<<L.GetNth(3)<<endl;
L.toString();
}
