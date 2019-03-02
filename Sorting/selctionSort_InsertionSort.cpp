#include<iostream>
using namespace std;
void selSort(int *ptr,int size)
{
	int i=0,j=0;
	int indexMin=0;
	int temp=0;
	for(i=0;i<size-2;i++)
	{  indexMin=i;
		for(j=i+1;j<size;j++)
		{
			if(ptr[j]<ptr[indexMin])
				indexMin=j;
		}
	    temp=ptr[i];
	    ptr[i]=ptr[indexMin];
	    ptr[indexMin]=temp;
	}
}

void inSort(int *ptr,int size)
{   int current=0,j=0;
	for(int i=1;i<size;i++)
	{   current=ptr[i];
	    j=i-1;
	    //below we overrite the extracted element with its previous and continue to do so to find correct position
		while(j>=0 &&ptr[j]>current)
		{   
		    ptr[j+1] = ptr[j];
			j--;
		}
		
		ptr[j+1]=current;
	}
}
int main()
{
	int arr[5]={5,4,3,2,1};
	inSort(&arr[0],5);
	for(int i=0;i<5;i++)
	{
		cout<<arr[i];
	}
}
