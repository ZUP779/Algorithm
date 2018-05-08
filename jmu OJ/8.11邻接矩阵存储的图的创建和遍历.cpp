#include <iostream>
#define Max 100
#define INF 32767
using namespace std;

int visited[Max];

typedef struct{
	int edges[Max][Max];
	int n;
	int e;
}MGraph;
void DFS(MGraph g,int v);
void BFS(MGraph g,int v);
int main()
{
	MGraph g;
	int n;
	int r,l,a,b;//rÐÐ,lÁÐ 
	cin>>n;
	while(n--){
		cin>>r>>l>>a>>b;
		g.n = r;
		for(int i = 0; i < r; i++){
			for( int j = 0; j < l; j++)
				cin>>g.edges[i][j];
			visited[i] = 0;	
		}
		DFS(g,0);
		cout<<endl;
		BFS(g,0);
		cout<<endl;
	}
}

void DFS(MGraph g,int v)
{
	visited[v] = 1;
	if( v == 0)
		cout<<"0";
	else	
		cout<<" "<<v;
	for( int i = 0; i < g.n; i++){
		if(g.edges[v][i] != 0 && g.edges[v][i] != INF && visited[i] == 0)
			DFS(g,i);
	}
}
void BFS(MGraph g,int v)
{
	int queue[Max],front = 0,rear = 0;
	int visited[Max];
	int w,i;
	for( i = 0; i < g.n; i++)
		visited[i] = 0;
	cout<<v;
	visited[v] = 1;
	rear = (rear + 1) % Max;
	queue[rear] = v;
	while( front != rear){
		front = (front + 1) % Max;
		w = queue[front];
		for( i = 0; i < g.n; i++)
			if(g.edges[w][i] != 0 && g.edges[w][i] != INF && visited[i] == 0){
				cout<<" "<<i;
				visited[i] = 1;
				rear = (rear + 1) % Max;
				queue[rear] = i;
			}
	}
	
}
