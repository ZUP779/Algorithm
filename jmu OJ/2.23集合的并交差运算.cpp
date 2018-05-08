#include <stdio.h>
#include <stdlib.h>
typedef struct list{
	int a;
	struct list* next;
}LinkList;
void InitList(LinkList*& L);
void CreateList(LinkList*& L,int n);
void PrintList(LinkList* L);
void DestoryList(LinkList*& L);
int LenofList(LinkList* L);
void Union(LinkList* A,LinkList* B,LinkList*& C);
void Inter(LinkList* A,LinkList* B,LinkList*& C);
void Difference(LinkList* A,LinkList* B,LinkList*& C);
int main()
{
	LinkList *A,*B,*C;
	int na,nb;
	scanf("%d%d",&na,&nb);
	InitList(A);
	InitList(B);
	InitList(C);
	CreateList(A,na);
	CreateList(B,nb);
/*	ss = C->next;
	for( p = A->next; p; p = p->next)
		for( q = B->next; q; q = q->next)
			if( p->a == q->a){
				s = (LinkList*)malloc(sizeof(LinkList));
				s->a = p->a;
				ss->next = s;
				ss = s;
			}*/
	Union(A,B,C);
	printf("%d",LenofList(C));
	PrintList(C);
	DestoryList(C);
	
	InitList(C);	
	Inter(A,B,C);
	printf("%d",LenofList(C));
	PrintList(C);
	DestoryList(C);
	
	InitList(C);
	Difference(A,B,C);
	printf("%d",LenofList(C));
	PrintList(C);
	DestoryList(C);
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
	for( p = L->next; p; p = p->next)
		printf(" %d",p->a);
	printf("\n");
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
int LenofList(LinkList* L)
{
	int n = 0;
	for(LinkList *p = L; p->next; p = p->next)
		n++;
	return n;
}
void Union(LinkList* A,LinkList* B,LinkList*& C)
{
	bool exist;
	LinkList *p,*q,*s,*t;
	q = C;
	for( p = A->next; p; p = p->next){
		s = (LinkList*)malloc(sizeof(LinkList));
		s->a = p->a;
		q->next = s;
		q = s;
	}
	t = q;
	t->next = NULL;
	for( p = B->next; p; p = p->next){
		exist = false;
		for( q = A->next; q; q = q->next){
			if( p->a == q->a)
				exist = true;
		}
		if(!exist){
			s = (LinkList*)malloc(sizeof(LinkList));
			s->a = p->a;
			t->next = s;
			t = s;
		}
	}
	t->next =NULL;
}
void Inter(LinkList* A,LinkList* B,LinkList*& C)
{
	bool exist;
	LinkList *p,*q,*s,*t;
	t = C;
	for( p = A->next; p; p = p->next){
		for( q = B->next; q; q= q->next){
			if( p->a == q->a){
				s = (LinkList*)malloc(sizeof(LinkList));
				s->a = p->a;
				t->next = s;
				t = s;
				break;
			}
		}
	}
	t->next = NULL;
}
void Difference(LinkList* A,LinkList* B,LinkList*& C)
{
	bool exist;
	LinkList *q,*p,*s,*t;
	t = C;
	for( p = A->next; p; p = p->next){
		exist = false;
		for( q = B->next; q; q = q->next)
			if( p->a == q->a)
				exist = true;	
		
		if(!exist){
			s = (LinkList*)malloc(sizeof(LinkList));
			s->a = p->a;
			t->next = s;
			t = s;
		}
	}
	t->next = NULL;
}
