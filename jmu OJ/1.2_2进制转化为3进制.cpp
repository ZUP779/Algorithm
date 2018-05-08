#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int x,n,i,j;
	scanf("%d",&n);
	char a[n][65];
	int b[n];
	char c[n][65];
	for(i = 0; i < n; i++)
		b[i] = 0;
	for(i = 0; i<n; i++)
		scanf("%s",a[i]);
	for(i = 0; i<n; i++){
		x = 1;
		for(j = strlen(a[i]) - 1; j>=0; j--){
			b[i] += (a[i][j] - '0') * x;
			x *= 2;
		}
	}
	for(i = 0; i < n; i++){
		x = 1;
		while(pow(3,x) <= b[i])
			x++;
		for(j = 0; x!=0; j++ ){
			x--;
			c[i][j] = b[i] / pow(3,x) + '0';
			b[i] -= (c[i][j] - '0') * pow(3,x);	
		}
		c[i][j]='\0';
	}
	for(i = 0; i < n; i++)
		printf("%s\n",c[i]);
	return 0;
}
