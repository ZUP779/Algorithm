#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char data[10];
	int top;
}SqStack;
void InitStack(SqStack*& s);
bool Push(SqStack*& s, char e);
bool Pop(SqStack*& s,char& e);
int main()
{
	SqStack *s;
	int n,i;
	char num[11];
	char e;
	bool exist;
	InitStack(s);
	while(1){
		s->top = -1;
		exist = true;
		i = 0;
			if(scanf("%d",&n)!=1)
			break;
		getchar();
		if( n < 0)
			break;
		while( n > 0){
			num[i++] = (n % 10) + '0';
			n/=10;
		}
		num[i] = '\0';
		for( i = 0; i < strlen(num); i++)
			Push(s,num[i]);
		for( i = 0; i < strlen(num); i++){
			Pop(s,e);
			if( e != num[i]){
				exist = false;
				break;
			}
		}
		
		if(exist)
			printf("YES\n");
		else printf("NO\n");
	}
}

void InitStack(SqStack*& s)
{
	s = (SqStack *)malloc(sizeof(SqStack));
	s->top = -1;
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
