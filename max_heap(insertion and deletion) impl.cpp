//properties of heap
/*1) It’s a complete tree (All levels are completely filled except possibly the last level
and the last level has all keys as left as possible). This property of Binary Heap makes 
them suitable to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at root must
be minimum among all keys present in Binary Heap. The same property must be recursively true 
for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

Examples of Min Heap:

            10                      10 (1)
         /      \               /       \  
       20        100          15  (2)       30  (3)
      /                      /  \        /  \
    30               40(4)    50(5)    100(6)   40(7)
*/

/*How is Binary Heap represented?
A Binary Heap is a Complete Binary Tree. A binary heap is typically represented as an 
array.

The root element will be at Arr[1].
Below table shows indexes of other nodes for the ith node, i.e., Arr[i]:
Arr[(i/2]	Returns the parent node
Arr[(2*i)]	Returns the left child node
Arr[(2*i)+1]	Returns the right child node
*/


// no of element in leaf node = flooe(n/2) + 1
#include <iostream>
#include <algorithm>
using namespace std;
int n=0;

/*
1.insert(): Inserting a new key takes O(Logn) time. We add a new key at the end of the tree.
IF new key is greater than its parent, then we don’t need to do anything. Otherwise, 
we need to traverse up to fix the violated heap property.
*/
void insert(int heap[],int data){
    n = n + 1;
    heap[n] = data;
    int i=n;
    int parent  = heap[i];
    while(i>1){
       int  parent = i/2;
       if(heap[parent] < heap[i]){
           swap(heap[parent],heap[i]);
           i = parent;
       }
       else{
           return;
       }
    }
}

/*
insert(): Inserting a new key takes O(Logn) time. We add a new key at the end of the tree.
IF new key is greater than its parent, then we don’t need to do anything. Otherwise, 
we need to traverse up to fix the violated heap property.
*/
void del(int heap[]){
    heap[1] = heap[n];
    n = n-1;
    int i = 1;
    while(i < n){
        int left = heap[2*i];
        int right = heap[(2*i)+1];
        int larger = left > right ? 2*i : 2*i+1;
        if(heap[i]<heap[larger]){
            swap(heap[i],heap[larger]);
            i = larger;
        }
        else{
            return;
        }
    }
}

int main() {
    int heap[50];
    insert(heap , 3);
    insert(heap , 2);
    insert(heap , 1);
    insert(heap , 15);
    insert(heap , 5);
    insert(heap , 4);
    del(heap);
    for(int i=1 ; i<=n ; i++){
        cout<< heap[i] << " ";
    }
	return 0;
}