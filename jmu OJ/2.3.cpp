#include <stdio.h>
typedef struct list{
	int a[300];
	int length;
}sqList;
void Delete(sqList &a,int x,int y);
int main()
{
	sqList a;
	int n,i,x,y;
	scanf("%d",&n);
	a.length = n;
	for( i = 0; i < n; i++)
		scanf("%d",&a.a[i]);
	scanf("%d %d",&x,&y);
	Delete(a,x,y);
	if(a.length > 0)
		printf("%d",a.a[0]);
	for( i = 1; i < a.length; i++)
		printf(" %d",a.a[i]);	
}
void Delete(sqList &a,int x,int y)
{
	int i,k = 0;
	for( i = 0; i < a.length; i++)
		if( a.a[i] > y || a.a[i] < x)
			a.a[k++] = a.a[i]; 
	a.length = k;
}
