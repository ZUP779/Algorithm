#include <stdio.h>
#include <stdlib.h>
typedef struct list{
	char a[100];
	int length;
}sqList;
void InitList(sqList *&a);
void printList(sqList *a);
int lenOfList(sqList *a); 
bool isEmptyList(sqList *a);
int LocateElem(sqList *a, char k);
bool ListInsert(sqList *&a,int i,char e);
bool ListDelete(sqList *&a, int i, char &e);
int main()
{
	char ch;
	int i,n;
	sqList *a;
	scanf("%d",&n);
	InitList(a);
	for( i = 0; i < n; i++){
		getchar();
		scanf("%c",&a->a[i]);
	}
	a->length = n;
	printList(a);
	printf("%d\n",lenOfList(a));
	if(isEmptyList(a))
		printf("yes\n");
	else printf("no\n");
	printf("%c\n",a->a[2]);
	printf("%d\n",LocateElem(a,'a'));
	ListInsert(a,4,'f');
	printList(a);
	ListDelete(a,3,ch);
	printList(a);
	free(a);
	return 0;
}
void InitList(sqList *&a)
{
	a = (sqList*)malloc(sizeof(sqList));
	a->length = 0;
}
void printList(sqList *a)
{
	if(a->length > 0)
		printf("%c",a->a[0]);
	for( int i = 1; i < a->length; i++)
		printf(" %c",a->a[i]);
	printf("\n");
}
int lenOfList(sqList *a)
{
	return a->length;
}
bool isEmptyList(sqList *a)
{
	if(a->length == 0)
		return true;
	return false;
}
int LocateElem(sqList *a, char e)
{
	int i = 0;
	while( i < a->length && a->a[i] != e)
		i++;
	if( i >= a->length)
		return 0;
	else return i+1;
}
bool ListInsert(sqList *&a,int i,char e)
{
	int j;
	if(i > a->length+1 || i<1)
		return false;
	i--;
	for( j = a->length; j > i; j--)
		a->a[j] = a->a[j-1];
	a->a[i] = e;
	a->length++;
	return true;
}
bool ListDelete(sqList *&a, int i, char &e)
{
	int j;
	if(i > a->length+1 || i<1)
		return false;
	i--;
	e = a->a[i];
	for( j = i; j < a->length - 1; j++)
		a->a[j] = a->a[j+1];
	a->length--;
	return true;
}
