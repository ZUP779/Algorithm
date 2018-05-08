#include <stdio.h>
int main()
{
	char ch;
	bool flag = false;
	char str[100000];
	int i = 0;
	while( scanf("%c",&ch) != EOF){
		if(ch == '"'){
			if( !flag){
				str[i++] = '`';
				str[i++] = '`';
			}
			else{
				str[i++] = '\'';
				str[i++] = '\'';
			}
			flag = !flag;
		}
		else
			str[i++] = ch;
	}
	printf("%s",str);
	return 0;
}
