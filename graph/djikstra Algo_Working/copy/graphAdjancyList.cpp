#include<iostream>
#include<limits>
#include<cmath>
#include "priorityQueueList.h"
using namespace std;
struct vertexNode
{
int vNo;
int distance;
int previous=-1;
bool isSource=false;	
struct vertexNode *next=0;
};
class vertexList
{
	struct vertexNode *head;
	int len;
	public:
		vertexList()
		{head=0;}
	
	vertexNode* operator[](int index)
	{
		if(index>=0 &&index<len)
		{int count=0;
		 struct vertexNode *curr=head;
		 while(count!=index && curr!=0)
		 {
		 	curr=curr->next;
		 	count++;
		 }
		 if(count==index)
		   return curr; 
		}
		return 0;
	}
	void addVertex(int vNo,bool isSource)
	{
	 	struct vertexNode *curr=this->head;
	 	if(this->head==0)
		 {
		 	head=new struct vertexNode;
		 	head->isSource=isSource;
		 	head->vNo=vNo;
		 	head->distance=0;
		 }
		 else{
	 	while(curr->next!=0)
		 {
		 	curr=curr->next;
		 }
		 curr->next=new struct vertexNode;
		 curr->next->isSource=isSource;
		 curr->next->vNo=vNo;
		 curr->next->distance=std::numeric_limits<int>::max();
	        }
	len++;
	}
	void addVertex(int vNo)
	{
	 	struct vertexNode *curr=this->head;
	 	if(this->head==0)
		 {
		 	head=new struct vertexNode;
		 	head->isSource=false;
		 	head->vNo=vNo;
		 	head->distance=0;
		 }
		 else{
	 	while(curr->next!=0)
		 {
		 	curr=curr->next;
		 }
		 curr->next=new struct vertexNode;
		 curr->next->isSource=false;
		 curr->next->vNo=vNo;
		 curr->next->distance=std::numeric_limits<int>::max();
	}
	len++;
	}
};
struct Node
{
int vertexNo=-1;
int weight=0;
struct Node *next=0;
	
};
class Graph
{  
	public:
	struct Node *Arr;
	int len;
	Graph(int rows)
	:Arr(0)
	{
	Arr=new struct Node[rows];
	len=rows;
	}
	Node* operator[](int index)
	{
		if(index>-1 &&index<len)
		{
			return &Arr[index];
		}
		return 0;
	}
	void connect(int rowNo,int vNo,int wt)
	{
		struct Node *curr=Arr+rowNo;
		if(curr->vertexNo==-1)
		{
		curr->vertexNo=vNo;
		curr->weight=wt;
		}
		else
		{
		
		while(curr->next!=0)
		{
			curr=curr->next;
		}
		curr->next=new struct Node;
		curr->next->vertexNo=vNo;
		curr->next->weight=wt;
		}
		
	}
	//O(N)
	void printNeighbours(int rowNo)
	{
		Node *curr=Arr+rowNo;
		cout<<curr->vertexNo<<' ';
		while(curr->next!=0)
		{
		curr=curr->next;
		cout<<curr->vertexNo<<' ';
		}
	}
	//returns true if both are connected O(N)
	inline int isAdjacent(int vA,int vB)
	{
		Node *curr=Arr+vA;	
		while(curr!=0)
		{
			if(curr->vertexNo==vB)
			{
				return 1;
			}
			curr=curr->next;
		}
		return 0;
	}
	inline int edgeWeight(int U,int V)
	{
		Node *curr=Arr+U;	
		while(curr!=0)
		{
			if(curr->vertexNo==V)
			{
				return curr->weight;
			}
			curr=curr->next;
		}
		return -1;
	}
};
int main()
{   Graph gph(6);
    
    gph.connect(0,1,50);
    gph.connect(0,2,45);
    gph.connect(0,3,10);
    
    gph.connect(1,3,15);
    gph.connect(1,2,10);
    
    gph.connect(2,4,30);
    
    gph.connect(3,0,10);
    gph.connect(3,4,15);
    
    gph.connect(4,1,20);
    gph.connect(4,2,35);
    
    gph.connect(5,4,3);
    
	vertexList A;
	A.addVertex(0,true);
	A.addVertex(1);
	A.addVertex(2);
	A.addVertex(3);
	A.addVertex(4);
	A.addVertex(5);
	Queue q(6);
	int max=numeric_limits<int>::max();
	q.enqueue(0,0,0,true);
	q.enqueue(1,max,0,false);
	q.enqueue(2,max,0,false);
	q.enqueue(3,max,0,false);
	q.enqueue(4,max,0,false);
	q.enqueue(5,max,0,false);
	while(!q.isEmpty())
	{
		queueVertexNode *ptr=q.deQueue();
		
		int index=ptr->vNo;
		cout<<"Selected index:"<<index<<endl;
		Node *unvisited_V=gph[index];
		while(unvisited_V!=0)
		{   
		   
		    int vertDist=(A[index])->distance;
		    int UVedge=gph.edgeWeight(index,unvisited_V->vertexNo);
		    int tempDist=vertDist+UVedge;
		   
		    if(vertDist==max)
			{
				tempDist=tempDist+UVedge;
				tempDist=-tempDist;
			}
			int distA=(A[unvisited_V->vertexNo])->distance;
			if(tempDist<=distA){
				(A[unvisited_V->vertexNo])->distance=tempDist;
               (A[unvisited_V->vertexNo])->previous=ptr->vNo;
               (q[(unvisited_V->vertexNo)])->distance=tempDist;
               
			}
			unvisited_V=unvisited_V->next;
		}
	}
	for(int i=0;i<=5;i++)
	{
		
		if((A[i])->isSource==true)
		{
			cout<<"Source:0"<<endl;
		}
		if((A[i])->distance==max)
		{
			cout<<"infinity"<<endl;
		}
		else if((A[i])->isSource==false){
		
	cout<<(A[i])->distance<<'\n';	
}
	}
	
}
