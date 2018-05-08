#include <stdio.h>
#include <iostream>
using namespace std;
int Apple(int m,int n);
int main()
{
	int m,n,k,t;
	cin>>t;
	while( t--){
		cin>>m>>n;
		printf("%d\n",Apple(m,n));
	}
	return 0;
}
int Apple(int m,int n)
{
	if( m == 0 || n == 1) 
		return 1; 
	if( m < n) 
		return Apple(m,m);

	return Apple(m,n-1) + Apple(m-n,n);
}
