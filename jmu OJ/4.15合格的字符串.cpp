#include <stdio.h>
#include <string.h>
#define Max 51
typedef struct{
	char data[Max];
	int length;
}SqString;
void StrAssign(SqString &s,char cstr[]);
int AnsLen(char ans[]);
char* Get(char ans[]);
void strup(char ch[]);
int main()
{
	bool exist;
	int i,j,k,n,anslen,getlen;
	int rAns[50] = {0};
	SqString a[50],b[50];
	char str[51];
	char ans[51];
	char *get;
	scanf("%d",&n);
	for( i = 0; i < n; i++){
		scanf("%s",str);
		StrAssign(a[i],str);
		strup(str);
		StrAssign(b[i],str);
	}
	scanf("%s",ans);
	strup(ans);
	anslen = AnsLen(ans);
	get = Get(ans);
	getlen = strlen(get);
	for( i = 0; i < n; i++){
		exist = false;
		
		if(b[i].length != anslen)
			continue;
		//判断【前部分 
		for( j = 0; b[i].data[j] != '['; j++)
			if( b[i].data[j] != ans[j])
				break;
		
		if(ans[j] != '[')
			continue;
			
		//判断【】内部分 
		for( k = 0; k < getlen; k++)
			if( b[i].data[j] == get[k]){
				exist = true;
				break;
			}
		if(!exist)
			continue;
		
		//判断】后部分 
		for( j++, k = j + getlen + 1; ans[k] != '\0'; k++, j++){
			if(b[i].data[j] != ans[k])
				break;
		}
		if(ans[k] != '\0')
			continue;
			
		rAns[i] = 1;
	}
	for( i = 0; i < n; i++)
		if(rAns[i] == 1)
			printf("%d %s\n",i+1,a[i].data); 
			
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
int AnsLen(char str[])
{
	int i,j,k;
	for( i = 0; str[i] != '['; i++);
	for( j = 0; str[j] != ']'; j++);
	for( k = j; str[k] != '\0'; k++);
	return i + k - j;
}
char* Get(char ans[])
{
	char get[50];
	int i,j;
	for( i = 0; ans[i] != '['; i++);
	for( j = 0, i++; ans[i] != ']'; j++,i++)
		get[j] = ans[i];
	get[j] = '\0';
	return get;
}
void strup(char ch[])
{
	for( int i = 0; ch[i] != '\0'; i++){
		if( ch[i] >= 'a' && ch[i] <= 'z')
			ch[i] = ch[i] - 'a' + 'A';
	}
}
