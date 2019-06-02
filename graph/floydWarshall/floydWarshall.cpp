#include<iostream>
using namespace std;
//For infinity,just take the highest value
int **arr;
int n;
int min(int a,int b)
{
	if(a<=b)
		return a;
		return b;
	
}
void floydWarshall()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
			}
		}
	}
}
void display()
{   cout<<"Final matrix of all pairs shortest path:";
	for(int i=0;i<n;i++)
	{   
		for(int j=0;j<n;j++)
		cout<<arr[i][j]<<' ';
		cout<<endl;
	}
}
int main()
{
	cout<<"Enter size of matrix(N):";
	cin>>n;
	arr=new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[n];
		cout<<"Enter values of row "<<i+1<<':';
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	floydWarshall();
	display();
}
