
#include<iostream>
using namespace std;
#define RANGE 255 
void countSort(int arr[],int n) 
{ 
    // The output character array that will have sorted arr 
    int output[n]; 
  
    // Create a count array to store count of inidividul 
    // characters and initialize count array as 0 
    int count[RANGE + 1]={0}, i; 
  
    // Store count of each character 
    for(i = 0; i<n; ++i) 
        ++count[arr[i]]; 
  
    // Change count[i] so that count[i] now contains actual 
    // position of this character in output array 
    for (i = 1; i <= RANGE; ++i) 
        count[i] += count[i-1]; 
  
    // Build the output character array 
    for (i = 0; i<n; ++i) 
    { 
        output[count[arr[i]]-1] = arr[i]; 
        --count[arr[i]]; 
    } 
  
    // Copy the output array to arr, so that arr now 
    // contains sorted characters 
    for (i = 0; i<n; ++i) 
        arr[i] = output[i]; 
} 
  /* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
     cout<<arr[i]<<',';
} 
int getMax(int *arr,int n)
{    int max=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}
  void radixSort(int *arr,int n)
  {
  	int m=getMax(arr,n);
  	for(int exp=1;m/exp>0;exp*=10)
	  {
	  	countSort(arr,exp);
	  }
  }
// The main function that sort the given string arr[] in 
// alphabatical order 

// Driver program to test above function 
int main() 
{ 
    int arr[] = {5,45,3,2,1,0};//"applepp"; 
     //countSort(arr,6);
    radixSort(arr,6);
     printArray(arr,6);
    return 0; 
} 

