#include <iostream>
using namespace std;
int m,n;
int f(int k)
{
	if( k % m == 0 && k % n == 0)
		return k;
	return f(k+1);
}
int main()
{
	cin>>m>>n;
	cout<<f(1);
	return 0;
}
