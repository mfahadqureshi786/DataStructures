#include<iostream>
using namespace std;
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   int gap=n;
   for (i = gap; i>0; i/=1.3)       
       {// Last i elements are already in place    
       for (j = 0; j+i<n; j++)  
           {
		   if (arr[j] > arr[j+i]) 
              swap(&arr[j], &arr[j+i]); 
		   }
		   }
		   
		   
} 
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
     cout<<arr[i]<<',';
} 
  
// Driver program to test above functions 
int main() 
{ 
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bubbleSort(arr, n); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
} 
