#include <iostream>
#include <stdlib.h>
#define Max 100
#define INF 32767
using namespace std;

int visited[Max];

typedef struct{
	int edges[Max][Max];
	int n;
	int e;
}MGraph;
typedef struct ANode{
	int adjvex;//指向点
	struct ANode* nextarc;
	int info;//权值 
}ArcNode;
typedef struct Vnode{
	int data;//顶点信息
	ArcNode *firstarc; 
}VNode;
typedef VNode AdjList[Max];
typedef struct{
	AdjList adjlist;
	int n,e;
}ALGraph;

void MatToList(MGraph g, ALGraph *&G);
void DFS(ALGraph *G,int v);
void BFS(ALGraph *G,int v);
int main()
{
	MGraph g;
	ALGraph *G;
	int n;
	int r,l,a,b;//r行,l列 
	cin>>n;
	while(n--){
		cin>>r>>l>>a>>b;
		g.n = r;
		for(int i = 0; i < r; i++){
			for( int j = 0; j < l; j++)
				cin>>g.edges[i][j];
			visited[i] = 0;	
		}
		MatToList(g,G);
		DFS(G,0);
		cout<<endl;
		BFS(G,0);
		cout<<endl;
	}
}

void MatToList(MGraph g, ALGraph *&G)
{
	int i,j;
	ArcNode *p;
	G = (ALGraph*)malloc(sizeof(ALGraph));
	for( i = 0; i < g.n; i++)
		G->adjlist[i].firstarc = NULL;
	for( i = 0; i < g.n; i++){
		for( j = g.n - 1; j >= 0; j--)
			if( g.edges[i][j] != 0 && g.edges[i][j] != INF){
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->info = g.edges[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
	}
	G->n = g.n;	G->e = g.e;
}
void DFS(ALGraph *G,int v)
{
	ArcNode *p;
	visited[v] = 1;
	if( v == 0)
		cout<<"0";
	else	
		cout<<" "<<v;
	p = G->adjlist[v].firstarc;
	while(p){
		if(visited[p->adjvex] == 0)
			DFS(G,p->adjvex);
		p = p->nextarc;
	}
}
void BFS(ALGraph *G,int v)
{
	ArcNode *p;
	int queue[Max],front = 0,rear = 0;
	int visited[Max];
	int w,i;
	for( i = 0; i < G->n; i++)
		visited[i] = 0;
	cout<<v;
	visited[v] = 1;
	rear = (rear + 1) % Max;
	queue[rear] = v;
	while( front != rear){
		front = (front + 1) % Max;
		w = queue[front];
		p = G->adjlist[w].firstarc;
		while(p){
			if(visited[p->adjvex] == 0){
				cout<<" "<<p->adjvex;
				visited[p->adjvex] = 1;
				rear = (rear + 1) % Max;
				queue[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
}
