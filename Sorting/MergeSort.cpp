#include<iostream>
using namespace std;
void merge(int *left,int *right,int *arr,int n1,int n2,int n3)
{
	int i=0,j=0,k=0;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[i])
		{
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=left[i];
		i++;k++;
	}
	while(j<n2)
	{
		arr[k]=right[j];
		k++;
		j++;
	}
}
void mergeSort(int *arr,int length)
{
	int n=length;
	if(n<2)
	{
		return;
	}
	else{
		int mid=n/2;
		int *left=new int[mid],*right=new int[n-mid];
	  for(int i=0;i<mid;i++)	
	  {
	  	left[i]=arr[i];
	  }
	  for(int i=mid;i<n;i++)	
	  {
	  	right[i-mid]=arr[i];
	  }
	  mergeSort(left,mid);
	  mergeSort(right,n-mid);
	  merge(left,right,arr,mid,n-mid,n);
	  
	}
}
int main()
{
	int arr[5]={5,4,3,2,1};
	mergeSort(arr,5);
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<' ';
	}
}


