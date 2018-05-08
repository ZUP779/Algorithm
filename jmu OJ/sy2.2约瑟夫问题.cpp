#include <stdio.h>
#include <stdlib.h>
typedef struct list{
	int num;
	struct list* next;
}LinkList;
void InitList(LinkList*& L);
void CreateList(LinkList*& L,int n);
void PrintList(LinkList* L);
void DestoryList(LinkList*& L);
int main()
{
	LinkList *L,*R,*q,*t,*s,*r;

	int n,p,m,i,count;
	while(1){
		count = 0;
		i = 1;
		InitList(L);
		InitList(R);
		scanf("%d%d%d",&n,&p,&m);
		if( n == 0 && p == 0 && m == 0)
			break;
		CreateList(L,n);
		s = R;
		for( t = L, q = L->next; q; t = t->next, q = q->next)
				if( q->num == p)
					break;
		while(1){
			if( i == m){
				i = 1;
				r = (LinkList*)malloc(sizeof(LinkList));
				r->num = q->num;
				s->next = r;
				s = r;
				s->next = NULL;
				t->next = q->next;
				free(q);
				q = t->next;	
			}
			if(m != 1)
				i++;
			if(q && m != 1){
				t = q;
				q = q->next;
			}
			if( t == q ){
				r = (LinkList*)malloc(sizeof(LinkList));
				r->num = q->num;
				s->next = r;
				s = r;
				s->next = NULL;
				break;
			}
			count++;
			if( m == 1 && count == n)
				break;
		}
		PrintList(R);
	}
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
	int i=1;
	if( n < 1)
		return;
	p = (LinkList*)malloc(sizeof(LinkList));
	p->next = NULL;
	p->num = i;
	i++;
	L->next = p;
	for( int i = 1; i < n; i++){
		s = (LinkList*)malloc(sizeof(LinkList));
		s->num = i+1;
		p->next = s;
		p = s;
	}
	p->next = L->next;
}
void PrintList(LinkList* L)
{
	LinkList *p;
	if( !L->next)
		return;
	for( p = L->next; p->next; p = p->next)
		printf("%d,",p->num);
	if(p)
		printf("%d\n",p->num);	
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
