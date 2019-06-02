#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<limits>
using namespace std;
struct edgeNode
{
	int vertexNo=-1;
	int weight=0;
	bool isSource=false;
};
class myList
{
	private:
	struct edgeNode *ptr;
	public:
		list<edgeNode> obj;
		myList(){}
		void addEdge(int vNo,int weight,bool isSource)
		{
			ptr=new edgeNode;
			ptr->vertexNo=vNo;
			ptr->weight=weight;
			ptr->isSource=isSource;
			obj.push_back(*ptr);
			delete ptr;
		}
	
		~myList(){delete ptr;}
	
};
struct queueNode
{
int vA;
int vB;
};
class graph
{
	private:
	vector<myList*> obj;
	int n;
	int sVx;
	public:
		int costUV(int vA,int vB)
		{
		    
			list<edgeNode>::iterator it=obj[vA]->obj.begin();
			while(it!=obj[vA]->obj.end() && it->vertexNo!=vB)
			{
			it++;	
			}
			return it->weight;
		}
		void relax(int vB,int newWeight)
		{
		 auto tempIt=(obj[vB])->obj.begin();	
		 tempIt->weight=newWeight;
		}
	graph(int nVertices,int sVertex)
	{
		this->n=nVertices;
		this->sVx=sVertex;
		for(int i=0;i<n;i++)
		obj.insert(obj.begin()+i,new myList);
		//initialize first struct of each list as its vertex if source then 0 other wise inf
		(obj[sVx])->addEdge(sVx,0,true);
		int max=numeric_limits<int>::max();
		for(int i=0;i<n;i++)
		{   if(i!=sVx)
			(obj[i])->addEdge(i,max,false);
		}
	}
void connect(int vA,int vB,int weight)
	{   
		(obj[vA])->addEdge(vB,weight,false);
	}
	bool isConnnected(int vA,int vB)
	{
		auto it=(obj[vA])->obj.begin();
		while(it!=(obj[vA])->obj.end() && it->vertexNo!=vB)
		{
			it++;
		}
		if(it->vertexNo==vB)
		{
			return true;
		}
		return false;
	}
//	void bellmansFord()
//	{  int dU;
//	  int max=numeric_limits<int>::max();
//		for(int i=0;i<n;i++)
//		{   auto it=(obj[i])->obj.begin();	
//			int dU=it->weight;
//			auto tempIt=it;
//			tempIt++;//to get edge
//			for(;tempIt!=(obj[i])->obj.end();tempIt++)
//			{ 
//			int costUV=tempIt->weight;
//			auto ttt=((obj[tempIt->vertexNo])->obj.begin());
//			int dV=ttt->weight;
//			int total=dU+costUV;
//			if(dU==max)
//			{
//				total=-total;
//			}
//			if(total<dV)
//			{
//				this->relax(tempIt->vertexNo,dU+costUV);
//			}
//		
//			}
//		}
//	}
void displayDeQue(const deque<queueNode> &myobj)
{
for(int i=0;i<myobj.size();i++)	
{   cout<<myobj[i].vA<<',';
  cout<<myobj[i].vB<<endl;
  cout<<"--------"<<endl;
}
}
	void bellmansFord()
	{  int enArr[n];
	   for(int j=0;j<n;j++)
	   {
	   	enArr[j]=0;
	   }
	   int dU;
	  int max=numeric_limits<int>::max();
	  deque<queueNode> queueObj;
	  //-----------------BFS-----------------
	  //enqueue first all source edges
	  auto it=(this->obj[sVx])->obj.begin();
	  it++;//to get edge
	  queueNode *ptr;
	  while(it!=(this->obj[sVx])->obj.end())
	  {ptr=new queueNode;
	  ptr->vA=sVx; 
	  ptr->vB=it->vertexNo;
	  queueObj.push_back(*ptr);
	  	it++;
	  }
	  enArr[sVx]=1;
	  //enqueue all adjacent
	  auto iter=queueObj.begin();
	  while(iter!=queueObj.end())
	  {if(iter->vB>=0 &&iter->vB<obj.size()){
	  
	  	if(enArr[iter->vB]!=1)
		  {	  
		auto tempIt=(obj[iter->vB])->obj.begin();
		tempIt++;
		while(tempIt!=(obj[iter->vB])->obj.end())
		{   ptr=new queueNode;
		    ptr->vA=iter->vB;
		    ptr->vB=tempIt->vertexNo;
		    queueObj.push_back(*ptr);
			tempIt++;
		}
		enArr[iter->vB]=1;
		
		  }}
	  iter++;	
	  //Relax All edges n-1 times
	  int dU,dV,cost;
	  for(int k=0;k<=n-2;k++)
	  {
	  for(auto it=queueObj.begin();it!=queueObj.end();it++)
	  {
	  	dU=(obj[it->vA]->obj.begin())->weight;
	  	//test code
	  	  if(it->vA==4 && it->vB==6)
		  {
		  	int hfg=54;
		  	int ffd=45;
		  }
		if(it->vB<0 ||it->vB>n)  
		{
	    dV=numeric_limits<int>::max();
		}
	  	else
		  dV=(obj[it->vB]->obj.begin())->weight;
	  	cost=costUV(it->vA,it->vB);
	  	if(dU+cost<dV)
		  {
		  	relax(it->vB,dU+cost);
		  }
		  
		
	  }
	  }
	  }
	displayDeQue(queueObj);
	}
	void displayAllVertices()
	{
		for(int i=0;i<n;i++)
		{
		displayVertex(i);
		}
	}
	inline void displayVertex(int vA)
	{
		auto tempIt=(obj[vA])->obj.begin();	
		cout<<"Vertex No:"<<tempIt->vertexNo<<endl;
		cout<<"Weight:"<<tempIt->weight<<endl;
		cout<<"--------"<<endl;
	}
};
int main()
{
	graph gph(7,0);
	gph.connect(0,1,6);
    gph.connect(0,2,5);
    gph.connect(0,3,5);
    
	gph.connect(1,4,-1);
	
	gph.connect(2,1,-2);
	gph.connect(2,4,1);
	
	gph.connect(3,2,-2);
	gph.connect(3,5,-1);
	
	gph.connect(4,6,3);
	
	gph.connect(5,6,3);
	gph.bellmansFord();
    gph.displayAllVertices();
    
}
