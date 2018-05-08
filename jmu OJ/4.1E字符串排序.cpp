#include <stdio.h>
#include <string.h>
#define Max 101
typedef struct{
	char data[Max];
	int length;
}SqString;
void StrAssign(SqString &s,char cstr[]);
int main()
{
	int i,j,k,num;
	char str[Max];
	SqString a[Max],temp;
	while(scanf("%d",&num) == 1){
		getchar();
		for( i = 0; i < num; i++){
			gets(str);
			if(!strcmp(str,"stop")){
				num = i;
				break;
			}
			StrAssign(a[i],str);
		}
		for( i = 0; i < num - 1; i++)
			for( j = 0; j < num - i - 1; j++)
				if( a[j].length > a[j+1].length){
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
		for( i = 0; i < num; i++)
			printf("%s\n",a[i].data);
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
