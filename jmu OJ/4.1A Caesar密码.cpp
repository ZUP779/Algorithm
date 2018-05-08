#include <stdio.h>
#include <string.h> 
#define Max 201
typedef struct{
	char data[Max];
	int length;
}SqString;
void StrAssign(SqString &s,char cstr[]);
void TransLate(SqString &s);
int main()
{
	SqString news;
	char str[Max],str2[15];
	do{
		gets(str2);
		if(!strcmp(str2,"ENDOFINPUT"))
			break;
		gets(str);
		StrAssign(news,str);
		TransLate(news);
		printf("%s\n",news.data);
		gets(str2);
	}while(strcmp(str2,"ENDOFINPUT"));
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
void TransLate(SqString &s)
{
	for( int i = 0; i < s.length; i++){
		if( s.data[i] >= 'F' && s.data[i] <= 'Z')
			s.data[i] =  s.data[i] - 5 ;
		else if(s.data[i] >= 'A' && s.data[i] <= 'E')
			s.data[i] = s.data[i] + 21;
	}
	
}
