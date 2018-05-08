#include <stdio.h>
#include <string.h>
#define Max 21
typedef struct{
	char pre[Max];
	char data[Max];
	int length;
}SqString; 
void StrAssign(SqString &s,char cstr[]);
void FindPre(SqString s[],int n);
int main()
{
	SqString a[1000];
	int n = 0;
	char str[Max];
	while(scanf("%s",str)==1)
		StrAssign(a[n++],str);
	FindPre(a,n);
	for( int i = 0; i < n; i++)
		printf("%s %s\n",a[i].data,a[i].pre);
	
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
void FindPre(SqString s[],int n)
{
	bool found;
	int i,j,k;
	for( i = 0; i < n; i++){
		for( j = 0; j < s[i].length; j++){
			found = true;
			s[i].pre[j] = s[i].data[j];
			s[i].pre[j+1] = '\0';
			for( k = 0; k < n; k++)
				if((strstr(s[k].data,s[i].pre) == s[k].data) && k != i){
					found = false;
					break;
				}
			if(found)
				break;
		}
	}
}
