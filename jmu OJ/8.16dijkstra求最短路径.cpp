#include <iostream>
#define INF 32767
#define Max 100
using namespace std;

typedef struct{
	int n,e;
	int edges[Max][Max];
}MGraph;

int v,e;

void Dijkstra(MGraph g);
void Path(int dist[],int path[],int s[],int n);

int main()
{
	MGraph g;
	int n,a;
	int i,j,k;
	cin>>n>>a;
	cin>>v>>e;
	g.n = n;
	g.e = a;
	for( i = 0; i < n; i++){
		for( j = 0; j < n; j++)
			g.edges[i][j] = INF;
		g.edges[i][i] = 0;
	}
	for( k = 0; k < a; k++){
		cin>>i>>j;
		cin>>g.edges[i][j];
	}
	Dijkstra(g);
}
void Dijkstra(MGraph g)
{
	int dist[Max],path[Max];
	int s[Max];
	int min,i,j,u;
	for( i = 0; i < g.n; i++){
		dist[i] = g.edges[v][i];
		s[i] = 0;
		if(g.edges[v][i] < INF)
			path[i] = v;
		else path[i] = -1;
	}
	s[v] = 1; 	path[v] = 0;
	for( i = 0; i < g.n; i++){
		min = INF;
		u = -1;
		for( j = 0; j < g.n; j++)
			if( s[j] == 0 && dist[j] < min){
				u = j;
				min = dist[j];
			}
		//?
		s[u] = 1;
		for( j = 0; j < g.n; j++)
			if(s[j] == 0)
				if( g.edges[u][j] < INF && g.edges[u][j] + dist[u] < dist[j]){
					dist[j] = dist[u] + g.edges[u][j];
					path[j] = u;
				}
	}
	Path(dist,path,s,g.n);
}
void Path(int dist[],int path[],int s[],int n)
{
	if( s[e] == 1 && v != e)
		cout<<dist[e]<<endl;
	else{
		cout<<"no answer";
		return;
	}
	int top,stack[Max],p;
	top = -1;	
	p = e;
	while(p != 0){
		top++;
		stack[top] = p;
		p = path[p];
	}
	top++;
	stack[top] = v;
	while(top != -1){
		if(top != 0)
			cout<<"v"<<stack[top]<<" ";
		else
			cout<<"v"<<stack[top];
		top--;
	}
}
