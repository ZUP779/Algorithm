#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	int sum;
	vector<int> dp;
	string str;
	cin>>n;
	while( n--){
		cin>>str;
		sum = 0;
		dp.clear();
		dp.resize(str.size(),0);
		dp[0] = (str[0] == 'O' ? 1 : 0);
		sum += dp[0];
		for( int i = 1; i < str.size(); i++){
			if( str[i] == 'O')
				dp[i] = dp[i-1] + 1;
			sum += dp[i];
		}
		cout<<sum<<endl;
	}
}
