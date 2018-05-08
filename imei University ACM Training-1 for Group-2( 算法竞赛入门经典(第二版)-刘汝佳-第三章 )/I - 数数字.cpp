#include <iostream>
using namespace std;
int main()
{
	int num[10];
	int n,m;
	cin>>n;
	while(n--){
		cin>>m;
		for( int i = 0; i < 10; i++)
			num[i] = 0;
		for( int i = 1; i <= m; i++){
			int j = i;
			while( j){
				num[j%10]++;
				j /= 10;
			}
		}
		for( int i = 0; i < 9; i++)
			cout<<num[i]<<" ";
		cout<<num[9]<<endl;
	}
	return 0;
}
