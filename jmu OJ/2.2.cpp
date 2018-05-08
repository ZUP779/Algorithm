#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;	
}LinkList;
extern void InitList(LinkList * &L);
extern void DispList(LinkList *L);
extern int ListLength(LinkList *L);
extern bool ListEmpty(LinkList *L);
extern bool GetElem(LinkList *L,int i,ElemType &e);
extern int LocateElem(LinkList *L,ElemType e);
extern bool ListInsert(LinkList * &L,int i,ElemType e);
extern bool ListDelete(LinkList * &L,int i,ElemType &e);
extern void DestroyList(LinkList * &L);

int main()
{
	int n,j,i;
	char ch;
	ElemType e;
	LinkList *L;
	
	InitList(L);
	scanf("%d",&n);
	for( i = 1; i <= n; i++){
		getchar();
		scanf("%c",&ch);
		ListInsert(L,i,ch);
	}
	DispList(L);
	printf("%d\n",ListLength(L));
	if(ListEmpty(L))
		printf("yes\n");
	else printf("no\n");
	GetElem(L,3,e);
	printf("%c\n",e);
	printf("%d\n",LocateElem(L,'a'));
	ListInsert(L,4,'f');
	DispList(L);
	ListDelete(L,3,e);
	DispList(L);
	DestroyList(L);
	
}

void InitList(LinkList * &L)  //��ʼ�� 
{
	L=(LinkList *)malloc(sizeof(LinkList));
	L->next=NULL;
}

void DispList(LinkList *L) //������Ա� 
{
	LinkList *p=L->next;
	if(p){
		printf("%c",p->data);
		p = p->next;
	}
	while(p!=NULL)
	{
		printf(" %c",p->data);
		p=p->next;
	}
	printf("\n");
}

int ListLength(LinkList *L) //���� 
{
	int n=0;
	LinkList *p=L;
	while(p->next!=NULL)
	{
		n++;
		p=p->next;
	}
	return n;
}

bool ListEmpty(LinkList *L) //�жϿձ� 
{
	return L->next==NULL;
}

bool GetElem(LinkList *L,int i,ElemType &e) //��ĳ������Ԫ�ص�ֵ 
{
	int j=0;
	LinkList *p=L;
	while( j < i && p != NULL){
		j++;
		p = p->next;
	}
	if(p == NULL)
		return false;
	e=p->data;
	return true;
}

int LocateElem(LinkList *L,ElemType e) //��Ԫ��ֵ���� 
{
	int i = 1;
	LinkList *p = L->next;
	while(p !=NULL && p->data != e){
		p = p->next;
		i++;
	}
	if(p == NULL)
		return 0;
	return i;
}

bool ListInsert(LinkList * &L,int i,ElemType e) //��������Ԫ��
{
	int j=0;
	LinkList *p=L,*s;
	i--;
	while( j < i && p != NULL){
		j++;
		p=p->next;
	}
	if(p == NULL)
		return false;

	s=(LinkList *)malloc(sizeof(LinkList));
	s->data=e;	
	s->next=p->next;
	p->next=s;
	return true;
} 

bool ListDelete(LinkList * &L,int i,ElemType &e) //ɾ������Ԫ��
{
	int j=0;
	LinkList *p=L,*q;
	while(j<i-1&&p!=NULL)
	{
		j++;
		p=p->next;
	}
	if(p==NULL)
	return false;

	q=p->next;
	if(q==NULL)
		return false;
	e=q->data;
	p->next=q->next;
	free(q);
	return true;
} 

void DestroyList(LinkList * &L)//�������Ա�
{
	LinkList *p=L,*q=p->next;
	while(q!=NULL){
		free(p);
		p=q;
		q=p->next;
	}
	free(p);
} 
