#include <iostream>
#define Max 1000
using namespace std;
typedef struct{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HTNode;
void CreateHT(HTNode ht[],int n)
{
	int i,j,k,lnode,rnode;
	int min1,min2;
	for( i = 0; i < 2 * n - 1; i++)
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	for( i = n; i < 2 * n - 1; i++){
		min1 = min2 = 32767;
		lnode = rnode = -1;
		for( k = 0; k < i; k++)
			if( ht[k].parent == -1){
				if( ht[k].weight < min1){
					min2 = min1;
					rnode = lnode;
					min1 = ht[k].weight;
					lnode = k;
				}
				else if( ht[k].weight < min2){
					min2 = ht[k].weight;
					rnode = k;
				}
			}
			ht[i].weight = ht[lnode].weight + ht[rnode].weight;
			ht[i].lchild = lnode+1;	ht[i].rchild = rnode+1;
			ht[lnode].parent = i;	ht[rnode].parent = i;
	} 
}
int getResult(HTNode ht[],int n, int m)
{
	int sum = 0;

	if(ht[n-1].lchild!=-1)
		sum += getResult(ht,ht[n-1].lchild,m+1);

	if(ht[n-1].rchild!=-1)
		sum += getResult(ht,ht[n-1].rchild,m+1);

	if(ht[n-1].lchild == -1 && ht[n-1].rchild == -1)
		sum = ht[n-1].weight * m;
	return sum;
}
int main()
{
	HTNode ht[Max];
	int t,n,i,r;
	cin>>t;
	while(t--){
		cin>>n;
		for( i = 0; i < n; i++)
			cin>>ht[i].weight;
		CreateHT(ht,n);
		r = 0;
		for( i = 0; i < n * 2 - 1; i++)
			if( ht[i].parent == -1){
				r = getResult(ht,i+1,0);
				break;
			}
		cout<<r<<endl;
	}
	return 0;
}
