#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 10000
int main()
{
	int n;
	scanf("%d",&n);
	char a[n][N],b[n][N/4];
	int i, j=0, l, sum, len;
	
	for( i = 0; i < n; i++){
		sum = 0;
		j = 0;
		scanf("%s",a[i]);
		len=strlen(a[i]);
		if(len>4){
		while(1){
			for( l = 1; l <= 4; l++)
				sum += (a[i][len-l] - '0') * pow(2,l-1);
			if(sum >= 10)
				b[i][j++] = 'A' + sum -10;
			else b[i][j++] = sum + '0';
				len -= 4;
			sum = 0;
			if(len <= 4)
				break;
		}
	}	
		for( l = 1; l <= len; l++)
			sum += (a[i][len-l]-'0') * pow(2,l-1);
		if(sum >= 10)
			b[i][j++] = 'A' + sum - 10;
		else 
			b[i][j++] = sum + '0';
		b[i][j] = '\0';
	}
	for( i = 0; i < n; i++){
		for( len = strlen(b[i])-1; len >= 0; len--)
			printf("%c",b[i][len]);
		printf("\n");
	}
}
