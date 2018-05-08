#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int data[101];
	int top;
}SqStack;
void InitStack(SqStack*& s);
bool Push(SqStack*& s, int e);
bool Pop(SqStack*& s);
bool StackEmpty(SqStack* s);
void DestroyStack(SqStack*& s);
int main()
{
	char cod[10];
	int num;
	int m,n,j,i;
	
	scanf("%d",&m);
	getchar();
	SqStack *s[100];
	int e[m];
	for( i = 0; i < m; i++){
		scanf("%d",&n);
		getchar();
		InitStack(s[i]);
		e[i] = 1;
		for( j = 0; j < n; j++){
			scanf("%s",cod);
			if(!strcmp(cod,"push")){
				scanf("%d",&num);
				Push(s[i],num);
			}
			else/* if(!strcmp(cod,"pop"))*/{
				if(!StackEmpty(s[i]))
					Pop(s[i]);
				else{
					e[i] = 0;
					break;
				}
			}
		}
	}
	
	for( i = 0; i < m; i++){
		if( e[i] == 0){
			printf("error\n");
			continue;
		}
		if( StackEmpty(s[i]))
			continue;
		for( j = 0; j < s[i]->top; j++)
			printf("%d ",s[i]->data[j]);
		printf("%d",s[i]->data[j]);
		if( i != m-1)
			printf("\n");
		DestroyStack(s[i]);
	}
}

void InitStack(SqStack*& s)
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
}
bool Push(SqStack*& s, int e)
{
	if( s->top == 99)
		return false;
	s->top ++;
	s->data[s->top] = e;
	return true;
}
bool Pop(SqStack*& s)
{
	if( s->top == -1)
		return false;
	s->top--;
	return true;
}
bool StackEmpty(SqStack* s)
{
	return(s->top == -1);
}
void DestroyStack(SqStack*& s)
{
	free(s);
}
