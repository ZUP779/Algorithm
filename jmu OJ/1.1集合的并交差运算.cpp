#include <stdio.h>
#include <stdlib.h>
typedef struct list{
	int data[100];
	int length;
}SqList;
void InitList(SqList *&L);
void DestroyList(SqList *&L);
int main()
{
	SqList *a,*b;
	InitList(a);
	InitList(b);
	bool q = true;
	int i,j,n1,n2,len;
	scanf("%d %d",&n1,&n2);
	int c[n1+n2];
	for( i = 0; i < n1; i++){
		scanf("%d",&a->data[i]);
		c[i] = a->data[i];
	}
	a->length = n1;
	len = n1;
	for( i = 0; i < n2; i++){
		scanf("%d",&b->data[i]);
		for( j = 0; j < a->length; j++)
			if(c[j] == b->data[i])
				q = false;
		if(q)	c[len++] = b->data[i];
		q = true;
	}
	b->length = n2;
	printf("%d ",len);
	for( i = 0; i < len; i++)
		printf("%d ",c[i]);
	printf("\n");

	len = 0;
	for( i = 0; i < a->length; i++)
		for( j = 0; j < b->length; j++)
			if( a->data[i] == b->data[j])
				c[len++] = a->data[i];
	printf("%d ",len);
	for( i = 0; i < len; i++)
		printf("%d ",c[i]);	
	printf("\n");
	
	len = 0;
	q = true;
	for( i = 0; i < a->length; i++){
		for( j = 0; j < b->length; j++)
			if( a->data[i] == b->data[j])
				q = false;
		if(q)	c[len++] = a->data[i];
		q = true;
	}
	printf("%d ",len);
	for( i = 0; i < len; i++)
		printf("%d ",c[i]);	
	printf("\n");
}

void InitList(SqList *&L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}
void DestroyList(SqList *&L)
{
	free(L);
}
