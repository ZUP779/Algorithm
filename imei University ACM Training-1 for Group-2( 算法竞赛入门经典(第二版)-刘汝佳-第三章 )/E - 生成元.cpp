#include <iostream>
using namespace std;
int main()
{
	bool f = false;
	int n,m,q;
	int sum;
	cin>>n;
	while(n--){
		cin>>m;
		f = false;
		for( int i = m - 54; i < m; i++){
			q = i;
			sum = 0;
			while( q){
				sum += q % 10;
				q /= 10;
			}
			if( i + sum == m ){
				f = true;
				cout<<i<<endl;
				break;
			}
		}
		if(!f)
			cout<<0<<endl;
	}
}
