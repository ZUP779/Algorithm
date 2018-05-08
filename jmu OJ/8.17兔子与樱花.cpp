#include <string.h>
#include <iostream>
#define Max 100
#define INF 32767
using namespace std;

typedef struct{
	char name[Max][Max];
	int n,e;
	int edges[Max][Max];
}MGraph;

void Dijkstra(MGraph g,int v,int e);
void Path(MGraph g,int dist[],int path[],int s[],int n,int v,int e);
int main()
{
	MGraph g;
	char str1[Max],str2[Max];
	int p,q,r;
	int i,j,k,m,n;
	
	cin>>p;	g.n = p;
	for( i = 0; i < p; i++){
		for( j = 0; j < p ; j++)
			g.edges[i][j] = INF;
		cin>>g.name[i];
		g.edges[i][i] = 0;
	}
	cin>>q;	g.e = q;
	for( i = 0; i < q; i++){
		cin>>str1>>str2>>k;
		for( j = 0; j < p; j++)
			if(!strcmp(str1,g.name[j])){
				m = j;
				break;
			}
		for( j = 0; j < p; j++)
			if(!strcmp(str2,g.name[j])){
				n = j;
				break;
			}
		g.edges[m][n] = k;
		g.edges[n][m] = k;
	}
	
	cin>>r;
	for( i = 0; i < r; i++){
		cin>>str1>>str2;
		for( j = 0; j < p; j++)
			if(!strcmp(str1,g.name[j])){
				m = j;
				break;
			}
		for( j = 0; j < p; j++)
			if(!strcmp(str2,g.name[j])){
				n = j;
				break;
			}
		Dijkstra(g,m,n);
	}
}

void Dijkstra(MGraph g,int v,int e)
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
	s[v] = 1; 	path[v] = v;
	for( i = 0; i < g.n; i++){
		min = INF;
		u = -1;
		for( j = 0; j < g.n; j++)
			if( s[j] == 0 && dist[j] < min){
				u = j;
				min = dist[j];
			}
		s[u] = 1;
		for( j = 0; j < g.n; j++)
			if(s[j] == 0)
				if( g.edges[u][j] < INF && g.edges[u][j] + dist[u] < dist[j]){
					dist[j] = dist[u] + g.edges[u][j];
					path[j] = u;
				}
	}
	Path(g,dist,path,s,g.n,v,e);
}
void Path(MGraph g,int dist[],int path[],int s[],int n,int v,int e)
{
	if( v == e){
		cout<<g.name[v];
		return;
	}
	int top,stack[Max],p;
	top = -1;
	p = e;
	while(p != v){
		top++;
		stack[top] = p;
		p = path[p];
	}
	top++;
	stack[top] = v;
	while(top != -1){
		if(top != 0){
			cout<<g.name[stack[top]];
			cout<<"->("<<g.edges[stack[top]][stack[top-1]]<<")->";
		}
		else
			cout<<g.name[stack[top]];
		top--;
	}
	cout<<endl;
}
