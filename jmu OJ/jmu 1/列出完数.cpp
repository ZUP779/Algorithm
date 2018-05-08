#include <iostream>
using namespace std;
bool is(int n)
{
	int sum = 0;
	for(int i = 1; i < n; i++){
		if( n % i == 0)
			sum+=i;
	}
	if( sum == n)
		return true;
	return false;
}
int main()
{
	int n;
	cin>>n;
	while( n > 0){
		cout<<n<<":";
		for(int i = 1; i <= n; i++)
			if(is(i))
				cout<<" "<<i;
		cout<<endl;
		cin>>n;
	}
	return 0;
}
