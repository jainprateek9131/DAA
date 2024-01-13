#include <iostream>
using namespace std;
int partition(int a[],int l,int r){
    int pivot=r;
    int ipivot=l;
    for(int i=l;i<r;i++){
        if(a[i]<=pivot){
            swap(a[ipivot++],a[i]);
        }
    }
    swap(a[ipivot],a[r]);return ipivot;
}
void quickSort(int a[],int l,int r){
    if(l<r){
        int ipivot = partition(a,l,r);
        quickSort(a,l,ipivot-1);
        quickSort(a,ipivot+1,r);
    }
}
//merge sort
int main() {
    int a[]={4,2,5,6,4,9};
    int n = sizeof(a)/sizeof(a[0]);
    quickSort(a,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
	}
	return 0;
}
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

 // } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
{
    // code here
    if(low < high){
        int pIndex = partition(arr,low,high);
        quickSort(arr,low,pIndex-1);
        quickSort(arr,pIndex+1,high);
    }
}
    
int partition (int arr[], int low, int high)
{
   // Your code here
   int pivot = arr[high];
   int pIndex = 0;
   for(int i=0 ; i<high ; i++){
       if(arr[i]<=pivot){
           swap(arr[i],arr[pIndex]);
           pIndex++;
       }
   }
   swap(arr[pIndex],arr[high]);
   return pIndex;
}
};


// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends
