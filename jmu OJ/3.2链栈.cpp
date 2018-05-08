#include <stdio.h>
#include <stdlib.h>
typedef struct linkstack
{
	char data;
	linkstack* next;
}LinkStack;
void InitStack(LinkStack*& s);
void DestroyStack(LinkStack*& s);
bool StackEmpty(LinkStack* s);
void Push(LinkStack*& s,char e);
bool Pop(LinkStack*& s,char &e);
int StackLength(LinkStack* s);
void PrintStack(LinkStack* s);
int main()
{
	bool exist = false;
	int i,n;
	char e,ee[100];
	LinkStack *s;

	scanf("%d",&n);
	for( i = 0; i < n; i++){
		scanf(" %c",&ee[i]);
	}

	InitStack(s);
	printf(StackEmpty(s)?"yes\n":"no\n");
	for( i = 0; i < n; i++){
		Push(s,ee[i]);
	}
	printf(StackEmpty(s)?"yes\n":"no\n");
		
	printf("%d\n",StackLength(s));
	
	PrintStack(s);
	printf("\n");
	while( Pop(s,e) && s->next){
		printf("%c ",e);
		exist = true;
	}
	if(exist)
		 printf("%c\n",e);
	printf(StackEmpty(s)?"yes\n":"no\n");
	DestroyStack(s);
	return 0;
}	
void InitStack(LinkStack*& s)
{
	s = (LinkStack*)malloc(sizeof(LinkStack));
	s->next = NULL;
}
void DestroyStack(LinkStack*& s)
{
	LinkStack *p = s,*q = s->next;
	while(q){
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}
bool StackEmpty(LinkStack* s)
{
	return(s->next == NULL);
}
void Push(LinkStack*& s,char e)
{
	LinkStack *q;
	q = (LinkStack*)malloc(sizeof(LinkStack));
	q->data = e;
	q->next = s->next;
	s->next = q;
}
bool Pop(LinkStack*& s,char &e)
{
	if( s->next == NULL)
		return false;
	LinkStack *p;
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}
int StackLength(LinkStack *s)
{
	int n;
	for( s = s->next; s;s = s->next)
		n++;
	return n;
}
void PrintStack(LinkStack *s)
{
	if(s->next == NULL)
		return;
	LinkStack *q;
	for( q = s->next; q->next; q = q->next)
		printf("%c ",q->data);
	printf("%c",q->data);		
}
