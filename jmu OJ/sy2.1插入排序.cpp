#include <stdio.h>
#include <stdlib.h>
typedef struct list{
	int a;
	struct list* next;
}LinkList;
void InitList(LinkList*& L);
void CreateList(LinkList*& L,int n);
void PrintList(LinkList* L);
void Sort(LinkList*& L);
int main()
{
	LinkList *L;
	int n;
	scanf("%d",&n);
	InitList(L);
	CreateList(L,n);
	Sort(L);
	PrintList(L);
	return 0;
}

void InitList(LinkList*& L)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;	
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
	printf("%d",p->a);
}
void Sort(LinkList*& L)
{
	LinkList *head,*first,*p,*q,*s,*t;
	head = L->next;
	first = head->next;
	head->next = NULL;
	
	while(first){
		for( t = first, q = head; q &&(q->a < t->a); p = q, q = q->next);
		first = first->next;
		if( q == head)
			L->next = t;
		else 
			p->next = t;
		t->next = q;
	}
}
