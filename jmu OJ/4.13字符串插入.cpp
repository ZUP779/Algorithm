#include <stdio.h>
#include <stdlib.h>
typedef struct snode{
	char data;
	struct snode *next;
}LiString;
void StrAssgin(LiString *&s, char cstr[]);
void StrPrint(LiString *s);
LiString* Insert(LiString *str,LiString *substr);
int main()
{
	LiString *str,*substr,*r;
	char ch[11];
	while(1){
		if(scanf("%s",ch) != 1)
			break;
		StrAssgin(str,ch);
		scanf("%s",ch);
		StrAssgin(substr,ch);
		r = Insert(str,substr);
		StrPrint(r);
	}
	return 0;
}
void StrAssgin(LiString *&s, char cstr[])
{
	int i;
	LiString *r,*p;
	s = (LiString *)malloc(sizeof(LiString));
	r = s;
	for( i = 0; cstr[i] != '\0'; i++){
		p = (LiString *)malloc(sizeof(LiString));
		p->data = cstr[i];
		r->next = p;
		r = p;
	}
	r->next = NULL; 
}
void StrPrint(LiString *s)
{
	LiString *p;
	for( p = s->next; p; p = p->next)
		printf("%c",p->data);
	printf("\n");
}
LiString* Insert(LiString *str,LiString *substr)
{
	LiString *p,*q;
	int i,num,max = -1,maxnum;
	for( num = 0, p = str->next; p; p = p->next,num++){
		if( p->data > max){
			max = p->data;
			maxnum = num;
		}
	}
	
	for( i = 0, p = str->next; i < maxnum; i++, p = p->next);
	for( q = substr->next; q->next; q = q->next);
	if(p->next)
		q->next = p->next;
	p->next = substr->next;
	
	return str;
	
}
