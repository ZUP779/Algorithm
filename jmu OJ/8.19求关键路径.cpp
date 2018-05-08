#include <iostream>
#define Max 100
#define INF 32767
using namespace std;
typedef struct{
	int ve;//最早完成时间 
	int vl;//最迟完成时间 
}Ver;
typedef struct{
	int n,e;
	int edges[Max][Max];
	Ver ver[Max];
}MGraph;
void SetVe(MGraph &g);
int main()
{
	MGraph g;
	int i,j,n,e;
	int a,b,w;

	cin>>n>>e;
	for( i = 0; i < n; i++){
		for( j = 0; j < n; j++)
			g.edges[i][j] =INF;
		g.edges[i][i] = 0;
	}
	for( i = 0; i < e; i++){
		cin>>a>>b>>w;
		g.edges[a-1][b-1] = w;
	}
	
	
}
void SetVe(MGraph &g)
{
	int i,j,max;
	g.ver[0].ve = 0;
	for( i = 1; i < g.n; i++)
		for( j = 0; j < g.n; j++)
			if( g.edges[j][i] != INF && g.edges[j][i] !=  0)
				g.ver[i].ve = g.ver[j].ve + g.edges[j][i];
			
	for(	)
}
