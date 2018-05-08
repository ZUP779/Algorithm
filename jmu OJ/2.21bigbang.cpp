#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct list{
	char name[31];
	struct list* next;
}LinkList;
void InitList(LinkList*& L);
void Insert(LinkList*& L,int n,char name[]);
void Delete(LinkList*& L,char name[]);
void Show(LinkList* L);
int Search(LinkList* L,char name[]);
int main()
{
	char a[7];
	char name[31];
	int n;
	LinkList *L;
	InitList(L);
	while(~scanf("%s",a)){
		if(!strcmp(a,"insert")){
			scanf("%d%s",&n,name);
			Insert(L,n,name);
		}
		else if(!strcmp(a,"delete")){
			scanf("%s",name);
			Delete(L,name);
		}
		else if(!strcmp(a,"show"))
			Show(L);
		else if(!strcmp(a,"search")){
			scanf("%s",name);
			printf("%d\n",Search(L,name));
		}
		else break;
	}

	return 0;
}
void InitList(LinkList*& L)
{
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;	
}
void Insert(LinkList*& L,int n,char name[])
{
	int i;
	LinkList *p,*t;
	InitList(t);
	strcpy(t->name,name);
	for( p = L,i = 1; p; p = p->next , i++)
		if( i == n){
			t->next = p->next;
			p->next = t;
			break;
		}
}
void Delete(LinkList*& L,char name[])
{
	LinkList *p,*q;
	for( p = L, q = p->next; q; p = q, q = q->next)
		if( !strcmp(name,q->name)){
			p->next = q->next;
			free(q);
			break;
		}
}
void Show(LinkList* L)
{
	LinkList *p;
	if( L->next == NULL){
		printf("\n");
		return;
	}
	for( p = L->next; p->next; p = p->next)
		printf("%s ",p->name);
	printf("%s\n",p->name);
}
int Search(LinkList* L,char name[])
{
	LinkList *p;
	int n = 1;
	for( p = L->next; p; p = p->next,n++)
		if( !strcmp(p->name,name))
			return n;
}
