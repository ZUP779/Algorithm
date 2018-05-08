#include <stdio.h>
#include <iostream>
#define Max 100
using namespace std;
typedef struct{
	char data[Max];
	int length;
}SqString;
void StrAssign(SqString &s,char cstr[]);
bool StrEqual(SqString s,SqString t);
void strup(char ch[]);
int main()
{
	SqString q,p;
	char ch[100];
	gets(ch);
	strup(ch);
	StrAssign(q,ch);
	gets(ch);
	strup(ch);
	StrAssign(p,ch);
	
	printf(StrEqual(p,q)?"YES":"NO");
	
	return 0;
}

void StrAssign(SqString &s,char cstr[])
{
	int i;
	for( i = 0; cstr[i]!='\0'; i++)
		s.data[i] = cstr[i];
	s.data[i] = '\0';
	s.length = i;
}
bool StrEqual(SqString s,SqString t)
{
	int i = 0,j = 0;
	while(s.data[i] != '\0' || t.data[j] != '\0'){
		while(s.data[i] == ' ')
			i++;
		while(t.data[j] == ' ')
			j++;
		if(s.data[i++] != t.data[j++])
			return false;
	}
	return true;
}
void strup(char ch[])
{
	for( int i = 0; ch[i] != '\0'; i++){
		if( ch[i] >= 'a' && ch[i] <= 'z')
			ch[i] = ch[i] - 'a' + 'A';
	}
}
