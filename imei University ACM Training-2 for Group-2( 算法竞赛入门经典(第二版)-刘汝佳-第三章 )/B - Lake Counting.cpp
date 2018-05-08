#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<vector<char> > v;
vector<vector<int> > flag;
queue<int> qi;
queue<int> qj;
void exist(int i,int j){
	if( i < 0 || i >= m || j < 0 || j >= n)
		return;
	if( v[i][j] == '.' || flag[i][j] == 1)
		return;
//	cout<<i<<"*"<<j<<endl;
	qi.push(i);
	qj.push(j);
	flag[i][j] = 1;
	return;
}
int main()
{
	int cnt = 0;
	int p,q;
	cin>>m>>n;
	v.resize(m);
	flag.resize(m);
	for( int i = 0; i < m; i++){
		v[i].resize(n);
		flag[i].resize(n,0);
		for( int j = 0; j < n; j++)
			cin>>v[i][j];
	}
	for( int i = 0; i < m; i++){
		for( int j = 0;  j < n; j++){
			if( !flag[i][j] && v[i][j] == 'W'){
				while( !qi.empty())
					qi.pop();
				while( !qj.empty())
					qj.pop();
//				cout<<"size:"<<qi.size()<<endl;
				qi.push(i);
				qj.push(j);
				cnt++;
				while( !qi.empty()){
					p = qi.front();
					qi.pop();
					q = qj.front();
					qj.pop();
					
					exist(p+1,q);
					exist(p+1,q+1);
					exist(p+1,q-1);
					exist(p-1,q);
					exist(p-1,q+1);
					exist(p-1,q-1);
					exist(p,q+1);
					exist(p,q-1);
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
