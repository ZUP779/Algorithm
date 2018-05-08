#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int w,h,sti,stj;
vector<vector<char> > v;
vector<vector<char> > f;
queue<int> qi;
queue<int> qj;
int cnt;
void exist(int i,int j){
	if( i < 0 || i >= w || j < 0 || j >= h)
		return;
	if( v[i][j] == '#' || f[i][j] == 1)
		return;
//	cout<<i<<"*"<<j<<endl;
	qi.push(i);
	qj.push(j);
	f[i][j] = 1;
	return;
}
int main()
{

	while(1){
		cnt = 0;
		cin>>h>>w;
		if( w == 0 || h == 0)
			break;
		v.clear();
		f.clear();
		f.resize(w);
		v.resize(w);
		for( int i = 0; i < w; i++){
			v[i].resize(h);
			f[i].resize(h,0);
			for( int j = 0; j < h; j++){
				cin>>v[i][j];
				if( v[i][j] == '@'){
					sti = i;
					stj = j;
				}
			}
		}
		int i,j;
		while( !qi.empty())
			qi.pop();
		while( !qj.empty())
			qj.pop();
		qi.push(sti);
		qj.push(stj);
		f[sti][stj] = 1;
		while( !qi.empty()){
			cnt++;
			
			i = qi.front();
			qi.pop();
			j = qj.front();
			qj.pop();
			//cout<<"i:"<<i<<" j:"<<j<<" cnt:"<<cnt<<endl;
			exist(i+1,j);
			exist(i-1,j);
			exist(i,j+1);
			exist(i,j-1);
		}
		cout<<cnt<<endl;
	}
}
