#include <iostream>
#define Max 26
#define INF 100
using namespace std;

typedef struct{
	int edges[Max][Max];
	int n;
	int num[Max];
}MGraph;

int Prim(MGraph g, int v);

int main()
{
	int n,num;
	int i,j,p,q;
	char ch;
	MGraph g;
	cin>>n;
	g.n = n;
	for( i = 0; i < 26; i++){
		for( j = 0; j < 26; j++)
			g.edges[i][j] = INF;
		g.edges[i][i] = 0;
	}
	for( i = 0; i < n - 1; i++){
		cin>>ch;
		p = ch - 'A';
		cin>>g.num[p];
		for( j = 0; j < g.num[p]; j++){
			cin>>ch>>num; 
			q = ch - 'A';
			g.edges[p][q] = num;
			g.edges[q][p] = num;
		}
	}
	cout<<Prim(g,p);
}

int Prim(MGraph g, int v)
{
	int sum = 0;
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
		sum += min;
		lowcost[k] = 0;//收进树 
		for( j = 0; j < g.n; j++)
			if( g.edges[k][j] != 0 && g.edges[k][j] < lowcost[j]){
				lowcost[j] = g.edges[k][j];
				closest[j] = k;
			}
	}
	return sum;
}
