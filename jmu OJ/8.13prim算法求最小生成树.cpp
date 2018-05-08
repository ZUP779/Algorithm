#include <iostream>
#define Max 100
#define INF 100
using namespace std;

typedef struct{
	int edges[Max][Max];
	int n;
	int e;
}MGraph;

void Prim(MGraph g, int v);

int main()
{
	int n,e;
	MGraph g;
	cin>>n>>e;
	g.n = n;
	g.e = e;
	for(int i = 0; i < n; i++)
		for( int j = 0; j < n; j++)
			cin>>g.edges[i][j];
	Prim(g,0);
}

void Prim(MGraph g, int v)
{
	bool flag = false; 
	int lowcost[Max],min;
	int closest[Max],i,j,k;
	for( i = 0; i < g.n; i++){
		lowcost[i] = g.edges[v][i];
		closest[i] = v;
	}
	for( i = 1; i < g.n; i++){
		min = INF;//权值 
		for( j = 0; j < g.n; j++)
			if( lowcost[j] != 0 && lowcost[j] < min){
				min = lowcost[j];
				k = j;
			}//判断距离最近的顶点 
		if(!flag){
			cout<<min;
			flag = true;
		}
		else	cout<<" "<<min;
		lowcost[k] = 0;//收进树 
		for( j = 0; j < g.n; j++)
			if( g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j]){
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
	}
}
