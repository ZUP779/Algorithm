#include <stdio.h>
#define Max 20000
typedef struct{
	char data[Max];
	int length;
}SqString;
void StrAssign(SqString &s,char cstr[]);
void GetNext(SqString t,int next[]);
int KMPIndex(SqString s,SqString t);
int main()
{
	int t;
	char str[Max];
	SqString S,T;
	scanf("%d",&t);
	for( int i = 0; i < t; i++){
		scanf("%s",str);
		StrAssign(S,str);
		scanf("%s",str);
		StrAssign(T,str);
		printf("%d\n",KMPIndex(S,T));
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
void GetNext(SqString t,int next[])
{
	int j,k;
	j = 0;	k = -1;	next[0] = -1;
	while( j < t.length - 1){
		if( k == -1 || t.data[j] == t.data[k]){
			j++;	k++;
			next[j] = k;
		}
		else k = next[k];
	}//abcdabd
/*	for( j = 0; j < t.length; j++)
		printf("%d",next[j]);*/
}
int KMPIndex(SqString s,SqString t)
{
	int next[Max],i = 0, j = 0;
	GetNext(t,next);
	while( i < s.length && j < t.length){
		if( j == -1 || s.data[i] == t.data[j]){
			i++;	j++;
		}
		else j = next[j];
	}
	if( j >= t.length)
		return i-t.length;
	else 
		return -1;
} 
