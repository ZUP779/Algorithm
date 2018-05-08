#include <stdio.h>
#include <string.h>
void Lock(char *p, char *q);
char secret[10005],que[10005];
int quLen,seLen;
int main()
{
	char *p,*q;
	char ch;
	while(scanf("%c",&ch) == 1){
		int i = 0;
		while(ch != 10){
			secret[i++] = ch;
			scanf("%c",&ch);
		}
		secret[i] = '\0';
		gets(que);
		p = que;
		q = secret;
		quLen = strlen(que);
		seLen = strlen(secret);
		Lock(p,q);
		printf("\n");
	}
	return 0;
}
void Lock(char *p,char *q)
{
	if( p - que == quLen)
		return;
	if( q - secret == seLen)
		q = secret;
	char r;	
	if( *p + *q - '0' > 122)
		r = (*p + *q - '0') % 123 + 32;
	else
		r = *p + *q - '0';
	printf("%c",r);
	Lock(++p,++q);
}
/*void Lock(char que[],char secret[])
{
	for(int i = 0; i < quLen ; i++){  
        int r;  
        r = que[i] + secret [ i % seLen ] - '0';
        if(r > 122)
            r = r % 122 + 31;
        que[i] = r;
    }
    printf("%s\n",que);
}*/
