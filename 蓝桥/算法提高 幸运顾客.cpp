#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,d;
	int cnt = 0;
	vector<int> v;
	cin>>n;
	while(n--){
		cin>>d;
		if(d == -1){
			cout<<v[cnt]<<endl;
			cnt++;
		}
		else{
			v.push_back(d);
			sort(v.begin(),v.end());
		}
	}
	return 0;
}
