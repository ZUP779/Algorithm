#include <iostream>
#include <stdio.h>
#define INF 32767
#define Max 100
using namespace std;
typedef struct{
	int count[Max];
	int n,e;
	int edges[Max][Max];
}MGraph;
void TopSort(MGraph g);
int main()
{
	MGraph g;
	int n,e,a,b;
	cin>>n>>e;
	g.n = n;	g.e = e;
	for( int i = 0; i < n; i++){
		for( int j = 0; j < n; j++)
			g.edges[i][j] = INF;
		g.edges[i][i] = 0;
		g.count[i] = 0;	
	}
	for( int i = 0; i < e; i++){
		cin>>a>>b;
		g.edges[a-1][b-1] = 1;
	}
	
	TopSort(g);

	return 0;
}
void TopSort(MGraph g)
{
	bool flag = false;
	int i,j;
	int St[Max],top = -1;
	for( i = 0; i < g.n; i++)
		for( j = 0; j < g.n; j++)
			if( g.edges[j][i] == 1)
				g.count[i]++;
				
	for( i = g.n - 1; i >= 0; i--)
		if(g.count[i] == 0){
			top++;
			St[top] = i;
		}
	while( top > -1){
		i = St[top];	top--;
		if(!flag){
			flag = true;
			cout<<"v"<<i+1;
		}
		else
			cout<<" v"<<i+1;
		for( j = g.n - 1; j >= 0; j--)
			if( g.edges[i][j] == 1){
				g.count[j]--;
				if(g.count[j] == 0){
					top++;
					St[top] = j;
				}
			}
	}
}
