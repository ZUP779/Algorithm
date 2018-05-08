#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v[305][305] = {0};
queue<int> x,y,t;

bool che( int i, int j)
{
	if( i >= 0 && i <= 300 && j >= 0 && j <= 300 && v[i][j] != -1)
		return true;
	return false;
}
//注意判断原点未被摧毁情况 
int main()
{
	int n;
	int tmin = 1005;
	int tmax = -1;
	vector<int> xi,yi,ti;
	cin>>n;
	xi.resize(n);
	yi.resize(n);
	ti.resize(n);
	for( int i = 0; i < n; i++){
		cin>>xi[i]>>yi[i]>>ti[i];
		tmax = tmax > ti[i] ? tmax : ti[i]; 
		if( ti[i] == 0){
			v[xi[i]][yi[i]] = -1;
			if( che(xi[i]+1,yi[i]))
				v[xi[i]+1][yi[i]] = -1;
			if( che(xi[i]-1,yi[i]))
				v[xi[i]-1][yi[i]] = -1;
			if( che(xi[i],yi[i]+1))
				v[xi[i]][yi[i]+1] = -1;
			if( che(xi[i],yi[i]-1))
				v[xi[i]][yi[i]-1] = -1;
		}
	
		x.push(0);
		y.push(0);
		t.push(0);
		for( int j = 1; j < tmax; j++){
			for( int i = 0; i < ti.size(); i++){
				if( ti[i] == j){
					v[xi[i]][yi[i]] = -1;
					if( che(xi[i]+1,yi[i]))
						v[xi[i]+1][yi[i]] = -1;
					if( che(xi[i]-1,yi[i]))
						v[xi[i]-1][yi[i]] = -1;
					if( che(xi[i],yi[i]+1))
						v[xi[i]][yi[i]+1] = -1;
					if( che(xi[i],yi[i]-1))
						v[xi[i]][yi[i]-1] = -1;
				}
			}
			int xn,yn,tn;
			while( (tn = t.front()) < j){
				t.pop();
				xn = x.front();
				x.pop();
				yn = y.front();
				y.pop();
				if( che(xn+1,yn)){
					x.push(xn+1);
					y.push(yn);
					t.push(i);
					if( v[xn+1][yn] == 0)
						v[xn+1][yn] = tn;
					else
						v[xn+1][yn] = v[xn+1][yn] < tn ? v[xn+1][yn] : tn;
				}
				if( che(xn-1,yn)){
					x.push(xn-1);
					y.push(yn);
					t.push(i);
					if( v[xn-1][yn] == 0)
						v[xn-1][yn] = tn;
					else
						v[xn-1][yn] = v[xn-1][yn] < tn ? v[xn-1][yn] : tn;
				}
				if( che(xn,yn+1)){
					x.push(xn);
					y.push(yn+1);
					t.push(i);
					if( v[xn][yn+1] == 0)
						v[xn][yn+1] = tn;
					else
						v[xn][yn+1] = v[xn][yn+1] < tn ? v[xn][yn+1] : tn;
				}
				if( che(xn,yn-1)){
					x.push(xn);
					y.push(yn-1);
					t.push(i);
					if( v[xn][yn-1] == 0)
						v[xn][yn-1] = tn;
					else
						v[xn][yn-1] = v[xn][yn-1] < tn ? v[xn][yn-1] : tn;
				}
			}
		}
	}	
	if( v[0][0] != -1){
		cout<<0;
		return 0;
	}
	for( int i = 0 ; i <= 300; i++){
		for( int j = 0; j <= 300; j++){
			if( v[i][j] > 0){
				tmin = tmin < v[i][j] ? tmin : v[i][j];
			}
		}
	}
	cout<<tmin;
	return 0;
}
