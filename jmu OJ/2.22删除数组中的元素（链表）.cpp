#include <stdio.h>
#include <stdlib.h>
typedef struct list{
	int a;
	struct list* next;
}LinkList;
void CreateList(LinkList*& L,int n);
void PrintList(LinkList* L);
void DeleteList(LinkList*& L, int k);
void DestoryList(LinkList*& L);
int main()
{
	int n,i,k;
	LinkList *L;
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
	scanf("%d",&n);
	CreateList(L,n);
	scanf("%d",&k);
	DeleteList(L,k);
	PrintList(L);
	DestoryList(L);
}

void CreateList(LinkList*& L,int n)
{
	LinkList *s,*p;
	if( n < 1)
		return;
	p = (LinkList*)malloc(sizeof(LinkList));
	p->next = NULL;
	scanf("%d",&p->a);
	L->next = p;
	for( int i = 1; i < n; i++){
		s = (LinkList*)malloc(sizeof(LinkList));
		scanf("%d",&s->a);
		p->next = s;
		p = s;
	}
	p->next = NULL;
}
void PrintList(LinkList* L)
{
	LinkList *p;
	for( p = L->next; p->next; p = p->next)
		printf("%d ",p->a);
	if(p)
		printf("%d",p->a);	
}
void DeleteList(LinkList*& L, int k)
{
	LinkList *p,*q;
	q = L;
	p = L->next;
	while(p->next){
		if(p->a == k){
			 q->next = p->next;
			 free(p);
		}
		else q = q->next;
		p = q->next;
	}
	if(p->a == k)
		q->next = NULL;
}
void DestoryList(LinkList*& L)
{
	LinkList *p,*q;
	for( q = L, p = q->next; p; p = p->next){
		free(q);
		q = p;
	}
	free(q);
}
