#include<iostream>
using namespace std;
template<typename T>
class Queue
{
T *ptr;
int pos;
int size;
public:
Queue(int size)
{
size<1?size=5:this->size=size;
ptr=new T[size];
int i=0;
for(i=0;i<size;i++)
{
	ptr[i]=0;
}
}

inline int Check_Full()
{
int i=0;
if(ptr[0]!=0)
return 1;
return 0;	
}
inline int Check_Empty()
{
int i=0;
for(;i<size;i++)
{
if(ptr[i] !=0) 
{
return 0;	
}
}
return 1;
}
inline void Enqueue()
{
T a;
cout<<"Enter value to Enqueue:";
cin>>a;
if(Check_Full()==0)
{
int i=size-1;
for(;i>-1;i--)
{

if(ptr[i]==0)
{
ptr[i]=a;
break;	
}	

}

}	
else
{
cout<<"Overflow";	
}	
	
}

inline void Dequeue()
{
	if(Check_Empty()==0)
	{
    ptr[size-1]=0;
	int i=size-1;
	
	while(i>0)
	{
	ptr[i]=ptr[i-1];
	ptr[i-1]=0;
	i--;
	}	
	
	}
	else
	{
		cout<<"Underflow";
	}

}
inline void Display()
{
int i=0;
for(;i<size;i++)
{
cout<<ptr[i]<<' ';
}
cout<<'\n';
}
	
};
int main()
{
	Queue<int> abc(5);
	while(true)
	{
	cout<<"Enter 1-Enqueue,2-Dequeue,3-Display,4-Exit\nChoice:";
	int action;
	cin>>action;
	switch(action)
	{
	case 1:
	abc.Enqueue();
	break;
	case 2:
		abc.Dequeue();break;
		case 3:
			abc.Display();break;
			case 4:
				exit(0);break;
	}	
	}
}
