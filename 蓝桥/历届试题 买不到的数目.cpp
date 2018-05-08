#include <iostream>
#include <string.h>

using namespace std;

int dp[1000005];

int main() {
	int n, m;
	memset(dp,0,sizeof(dp));
	cin>>n>>m;
	dp[n] = 1, dp[m] = 1;
	int t = n > m ? n : m;
	for(int i = t + 1; i < 1000005; i++) {
		if(dp[i - n] || dp[i - m]) 
			dp[i] = 1;
	}	
	for(int i = 1000004; i >= 0; i--) {
		if(!dp[i]) {
			cout<<i;
			break;
		}
	}

	return 0;
}
