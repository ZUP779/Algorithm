#include <stdio.h>
#define M 10
#define Max 100
typedef struct{
	int r;
	int c;
	int d;
}TupNode;
typedef struct{
	int rows;
	int cols;
	int nums;
	TupNode data[Max];
}TSMatrix;
void CreatMat(TSMatrix &t,int A[M][M],int n);
void DispMat(TSMatrix t);
void TranTat(TSMatrix t,TSMatrix &tb);
bool MatAdd(TSMatrix a,TSMatrix b,TSMatrix &c);
bool MatMul(TSMatrix a,TSMatrix b,TSMatrix &c);
int main()
{
	TSMatrix a,b,c;
	int A[M][M],B[M][M],C[M][M];
	int i,j,n;
	scanf("%d ",&n);
	for( i = 0; i < n; i++)
		for( j = 0; j < n; j++)
			scanf("%d",&A[i][j]);
	for( i = 0; i < n; i++)
		for( j = 0; j < n; j++)
			scanf("%d",&B[i][j]);
	CreatMat(a,A,n);
	CreatMat(b,B,n);
	DispMat(a);
	printf("\n");
	DispMat(b);
	printf("\n");
	TranTat(a,c);
	DispMat(c);
	printf("\n");
	MatAdd(a,b,c);
	DispMat(c);
	printf("\n");
	MatMul(a,b,c);
	DispMat(c);
	printf("\n");
	
	return 0;
}
void CreatMat(TSMatrix &t,int A[M][M],int n)
{
	int i,j;
	t.rows = n;	t.cols = n;	t.nums = 0;
	for( i = 0; i < n; i++)
		for( j = 0; j < n; j++)
			if(A[i][j]){
				t.data[t.nums].r = i;
				t.data[t.nums].c = j;
				t.data[t.nums].d = A[i][j];
				t.nums++;
			}
}
void DispMat(TSMatrix t)
{
	int i;
	if(t.nums <= 0)
		return;
	printf("%d\t%d\t%d\n",t.rows,t.cols,t.nums);
	printf("-----------------\n");
	for( i = 0; i < t.nums; i++)
		printf("%d\t%d\t%d\n",t.data[i].r,t.data[i].c,t.data[i].d);		
}
void TranTat(TSMatrix t,TSMatrix &tb)
{
	int v,p,q = 0;
	tb.rows = t.cols;	tb.cols = t.rows;	tb.nums = t.nums;
	if(t.nums){
		for( v = 0; v < t.cols; v++)
			for( p = 0; p < t.nums; p++)
				if(t.data[p].c == v){
					tb.data[q].r = t.data[p].c;
					tb.data[q].c = t.data[p].r;
					tb.data[q].d = t.data[p].d;
					q++;
				}
	}
}
bool MatAdd(TSMatrix a,TSMatrix b,TSMatrix &c)
{
	int i = 0, j = 0, k = 0;
	int v;
	if(a.rows != b.rows || a.cols != b.cols)
		return false;
	c.rows = a.rows; c.cols = a.cols;
	while( i < a.nums && j < b.nums){
		if( a.data[i].r == b.data[j].r){
			if(a.data[i].c < b.data[j].c){
				c.data[k].r = a.data[i].r;
				c.data[k].c = a.data[i].c;
				c.data[k].d = a.data[i].d;
				k++;	i++;
			}
			else if(a.data[i].c > b.data[j].c){
				c.data[k].r = a.data[i].r;
				c.data[k].c = a.data[i].c;
				c.data[k].d = a.data[i].d;
				k++;	j++;
			}
			else{
				v = a.data[i].d + b.data[j].d;
				if( v){
					c.data[k].r = a.data[i].r;
					c.data[k].c = a.data[i].c;
					c.data[k].d = v;
					k++;
				}
				i++;	j++;
			}
		}
		else if( a.data[i].r < b.data[j].r){
				c.data[k].r = a.data[i].r;
				c.data[k].c = a.data[i].c;
				c.data[k].d = a.data[i].d;
				k++;	i++;
		}
		else{
				c.data[k].r = b.data[j].r;
				c.data[k].c = b.data[j].c;
				c.data[k].d = b.data[j].d;
				k++;	j++;
		}
		c.nums = k;
	}
	return true;
}
int getvalue(TSMatrix c,int i,int j)
{
	int k = 0;
	while( k < c.nums && ( c.data[k].r != i || c.data[k].c != j))
		k++;
	if( k < c.nums)
		return c.data[k].d;
	return 0;
}
bool MatMul(TSMatrix a,TSMatrix b,TSMatrix &c)
{
	int i,j,k,p = 0;
	int s;
	if(a.cols != b.rows)
		return false;
	for( i = 0; i < a.rows; i++)
		for( j = 0; j < b.cols; j++){
			s = 0;
			for( k = 0; k < a.cols; k++)
				s = s + getvalue(a,i,k) * getvalue(b,k,j);
			if( s){
				c.data[p].r = i;
				c.data[p].c = j;
				c.data[p].d = s;
				p++;
			}
		}
	c.rows = a.rows;
	c.cols = b.cols;
	c.nums = p;
	return true;
}
