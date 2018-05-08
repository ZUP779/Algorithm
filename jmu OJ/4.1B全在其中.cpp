#include <stdio.h>
#define Max 100001
typedef struct{
	char data[Max];
	int length;
}SqString;
void StrAssign(SqString &s,char cstr[]);
bool Is(SqString s,SqString t);
int main()
{
	SqString s,t;
	char str[Max];
	while(scanf("%s",str)==1){
		StrAssign(s,str);
		scanf("%s",str);
		StrAssign(t,str);
		printf(Is(s,t)?"Yes":"No");
		printf("\n");
	}
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
bool Is(SqString s,SqString t)
{
	int i,j = 0;
	for( i = 0; i < s.length; i++){
		while( t.data[j] != '\0' && s.data[i] != t.data[j])
			j++;
		if( t.data[j] == '\0' && s.data[i] != t.data[j])
			return false;
		j++;
	}
	return true;
}
