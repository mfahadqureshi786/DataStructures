#include<iostream>
using namespace std;
void swap(int *ptr1,int *ptr2)
{
int temp=*ptr1;
*ptr1=*ptr2;
*ptr2=temp;	
}
int partition(int *arr,int start,int end)
{   int pivot=arr[end];
	int pindex=start;
	for(int i=start;i<=end-1;i++)
	{
		if(arr[i]<=pivot)
		{
			swap(&arr[pindex],&arr[i]);
			pindex++;
		}
	}
	swap(&arr[pindex],&arr[end]);
	return pindex;
}
void quickSort(int *arr,int start,int end)
{   if(start<end){

	int pindex=partition(arr,start,end);
	quickSort(arr,start,pindex-1);
	quickSort(arr,pindex+1,end);
	}
	else
	return;
}

int main()
{   int arr[]={5,4,32,1,7,4,2,5};
	quickSort(arr,0,7);
	for(int i=0;i<8;i++)
	{
		cout<<arr[i]<<' ';
	}
	
}
