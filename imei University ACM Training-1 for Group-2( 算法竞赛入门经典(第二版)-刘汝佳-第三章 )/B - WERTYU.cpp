#include <stdio.h>
#include <cstring>
int main()
{
	bool flag = false;
	char s[] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
	char ch;
	char str[100000];
	int  i = 0;
	while( scanf("%c",&ch) != EOF){
			flag = false;
			for( int j = 0; j < strlen(s); j++){
				if( ch == s[j]){
					if( ch != '`' && ch != 'Q' && ch != 'A' && ch != 'Z'){
						flag = true;
						str[i++] = s[j-1];
					}
				}
			}
			if( !flag)
				str[i++] = ch;
	}
	printf("%s",str);
}
