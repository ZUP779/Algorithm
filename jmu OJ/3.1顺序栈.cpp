#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	char data[100];
	int top;
}SqStack;
void InitStack(SqStack*& s);
void DestroyStack(SqStack*& s);
bool StackEmpty(SqStack* s);
bool Push(SqStack*& s, char e);
bool Pop(SqStack*& s,char& e);
bool GetTop(SqStack* s,char& e);
int main()
{
	int i,n;
	char e,ee[100];
	SqStack *s;

	scanf("%d",&n);
	getchar();
	for( i = 0; i < n; i++){
		scanf("%c",&ee[i]);
		getchar();
	}

	InitStack(s);
	printf(StackEmpty(s)?"yes\n":"no\n");
	for( i = 0; i < n; i++){
		Push(s,ee[i]);
	}
	printf(StackEmpty(s)?"yes\n":"no\n");
		
	printf("%d\n",s->top+1);
	
	for( i = s->top; i>0; i--)
		printf("%c ",s->data[i]);
	if(!StackEmpty(s))
		printf("%c\n",s->data[0]);
	
	while( s->top != 0 && Pop(s,e))
		printf("%c ",e);
	Pop(s,e);
	printf("%c\n",e);
	printf(StackEmpty(s)?"yes\n":"no\n");
	DestroyStack(s);
	return 0;
}	
void InitStack(SqStack*& s)
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}
void DestroyStack(SqStack*& s)
{
	free(s);
}
bool StackEmpty(SqStack* s)
{
	return(s->top == -1);
}
bool Push(SqStack*& s, char e)
{
	if( s->top == 99)
		return false;
	s->top ++;
	s->data[s->top] = e;
	return true;
}
bool Pop(SqStack*& s,char &e)
{
	if( s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}
bool GetTop(SqStack* s,char& e)
{
	if( s->top == -1);
		return false;
	e = s->data[s->top];
	return true;
}

