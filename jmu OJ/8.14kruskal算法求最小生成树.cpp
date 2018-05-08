#include <iostream>
#define Max 100
#define INF 100
using namespace std;

typedef struct{
	int edges[Max][Max];
	int n;
	int e;
}MGraph;
typedef struct{
	int u;
	int v;
	int w;
}Edge;

void SortEdge(MGraph g,Edge E[]);
void Kruskal(Edge E[],int n,int e);

int main()
{
	MGraph g;
	Edge E[Max];
	
	int n,e;
	cin>>n>>e;
	g.e = e;
	g.n = n;
	for( int i = 0; i < n; i++)
		for( int j = 0; j < n; j++)
			cin>>g.edges[i][j];
	SortEdge(g,E);
	Kruskal(E,g.n,g.e);
	
	return 0;
}
void SortEdge(MGraph g,Edge E[])
{
	int i,j,k = 0;
	Edge temp;
	for( i = 0; i < g.n; i++)
		for( j = 0; j < g.n; j++)
			if(g.edges[i][j] < INF){
				E[k].u = i;
				E[k].v = j;
				E[k].w = g.edges[i][j];
				k++;
			}
	for( i = 1; i < k; i++){
		temp = E[i];
		j = i - 1;
		while( j >= 0 && temp.w < E[j].w){
			E[j+1] = E[j];
			j--;
		}
		E[j+1] = temp;
	}
}
void Kruskal(Edge E[],int n,int e)
{
	bool flag = false;
	int i,j,m1,m2,sn1,sn2,k;
	int vset[Max];
	for( i = 0; i < n; i++)	vset[i] = i;
	k = 1;
	j = 0;
	while( k < n){
		m1 = E[j].u;
		m2 = E[j].v;
		sn1 = vset[m1];
		sn2 = vset[m2];
		if( sn1 != sn2){
			if(!flag){
				cout<<m1+1<<" "<<m2+1;
				flag = true;
			}
			else
				cout<<" "<<m1+1<<" "<<m2+1;
			k++;
			for( i = 0; i < n; i++)
				if( vset[i] == sn2)
					vset[i] = sn1;
		}
		j++;	
	}
}
