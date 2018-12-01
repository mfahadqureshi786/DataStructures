#include<iostream>
using namespace std;
class HashTable
{
private:
char *arr;
int len;
public:
	int hF1(int key)
{   int endReached=0;
	int index=key%len;
	if(arr[index]=='\0')
		{
		return index;
		}
		else
	{	
	for(int i=index;i<len;i++)
	{
    if(arr[i]=='\0')
    return i;
    if(i+1==len &&endReached==0)
    {endReached=1;
     i=-1;
	}
	}
	return -1;
	}
}
HashTable(int size)	
{
len=size;
arr=new char[size];
for(int i=0;i<len;i++)
{
	arr[i]='\0';
}
}
float loadFactor()
{   int n=0;
	for(int i=0;i<len;i++)
	{
		if(arr[i]!='\0')
		{
		n++;	
		}
	}
	return n/len;
}
void insert(int key,int value)
{
	int index=hF1(key);
	if(index!=-1)
	{
		arr[index]=value;
	}
}
};
int main()
{
HashTable A(5);
A.insert(89,89);
A.insert(18,18);
A.insert(17,17);
}

