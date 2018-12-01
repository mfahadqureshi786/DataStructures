#include<iostream>
using namespace std;
int main()
{   int arr[5]={5,4,3,2,1};
	int i,j,m,t;
	int max=5;
	m=5/2;
	while(m>0)
	{
		for(j=m;j<max;j++)
		{//j is temp gap m
			for(i=j-m;i>=0;i=i-m)
			{
				if(arr[i]>arr[i+m])
				{t=arr[i];
				arr[i]=arr[i+m];
				arr[i+m]=t;
				}
				else
				break;
			
			}
			
		}
			m/=2;
	}
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<' ';
	}
}
