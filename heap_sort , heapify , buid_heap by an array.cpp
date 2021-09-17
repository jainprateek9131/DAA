#include <iostream>
using namespace std;

//******leaf node start with flour (n/2)+1 ....... n
// 7 / 2 + 1 = 4 ..... 7

void heapify(int a[],int n , int i){
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;
    if(l<=n and a[l] > a[largest]){
        largest = l;
    }
    if(r<=n and a[r] > a[largest]){
        largest = r;
    }
    if(i!=largest){
        swap(a[i],a[largest]);
        heapify(a,n,largest);
    }
}

// build  heap from last second level of tree
void build_heap(int a[],int n){
    for(int i=n/2 ; i>0 ; i--){
        heapify(a,n,i);
    }
}

void heap_sort(int a[], int n){
    for(int i=n ; i>1 ; i--){
        swap(a[1],a[i]);
        heapify(a,i-1,1);
    }
}
int main() {
	int a[50] ;
	a[1]=3;
	a[2]=2;
	a[3]=1;
	a[4]=15;
	a[5]=5;
	a[6]=4;
	a[7]=45;
	//{3,2,1,15,5,4,45};
	int n=7;
	int i = 1;    //current index where you want to heapify the arrray
	build_heap(a,n);
	heap_sort(a,n);
	for(int i =1 ; i<=n ; i++){
	    cout<<a[i]<<" ";
	}
	return 0;
}