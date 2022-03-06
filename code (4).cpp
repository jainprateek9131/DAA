// C++ program to find median of a matrix
// sorted row wise
#include<bits/stdc++.h>
using namespace std;



// function to find median in the matrix
int median(vector<vector<int>> &A, int M, int N)
{
	int k = ( M*N + 1 )/2 ;

int a = INT_MAX ;
int b = INT_MIN ;

for( int i = 0 ; i < M ; i++ )
{
a = min( a , A[i][0] ) ;
b = max( b , A[i][N-1] ) ;
}
cout<<a<<" "<<b<<endl;
while( a < b )
{
int m = ( a + b )/2 ;

int cnt = 0 ;

for( int i = 0 ; i < M ; i++ )
cnt = cnt + ( upper_bound( A[i].begin() , A[i].end() , m ) - A[i].begin() ) ;

if( cnt < k )a = m + 1 ;
else b = m ;
cout<<a<<" "<<b<<endl;
}

return a ;
}

// driver program to check above functions
int main()
{
    vector<vector<int>> v;
    v.push_back({1,3,5});
    v.push_back({2,6,9});
    v.push_back({3,6,9});
    
	int r = 3, c = 3;
	//int m[][MAX]= { {1,3,5}, {2,6,9}, {3,6,9} };
	cout << "Median is " << median(v, r, c) << endl;
	return 0;
}
