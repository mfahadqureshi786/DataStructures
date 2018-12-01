#include<iostream>
using namespace std;
template<typename T>
class Stack
{
private:
T *ptr;
int pos;
int size;
public:
Stack(int s)
{
s>0?this->size=s:size=5;
ptr=new T[size];
int i=0;
for(i=0;i<size;i++)
{
	ptr[i]=0;
}	
pos=0;
}	
inline int Check_Empty()
{
int i=0;
for(i=0;i<size;i++)
{
if(ptr[i]!=0)
return 0;
}
return 1;	
}
inline int Check_Full()
{
if(pos>size-1)	
{
return 1;	
}
return 0;
}
void Push()
{
	T a;
cout<<"Enter value to Push:";
cin>>a;
if(Check_Full()==0)
{
ptr[pos++]=a;	
}
else
cout<<"Cannot Perform Push Operation,Stack is full\n";	
}
void Pop()
{
if(Check_Empty()==0)
{
ptr[--pos]=0;	
}
else
{
cout<<"Stack is empty.\n";	
}
	
}
	void Display()
	{
	int i=0;
	for(;i<size;i++)
	{
	cout<<ptr[i]<<' ';	
	}
	cout<<endl;	
	}
};
int main()
{
	Stack<float> abc(5);
	while(true)
	{
	cout<<"Enter 1-Push,2-Pop,3-Display,4-Exit\nChoice:";
	int action;
	cin>>action;
	switch(action)
	{
	case 1:
	abc.Push();
	break;
	case 2:
		abc.Pop();break;
		case 3:
			abc.Display();break;
			case 4:
				exit(0);break;
	}	
	}
}
