#include <stdio.h>
int main()
{
	int n; 
	int num[100][100];
	int i,j,m,a = 1;
	scanf("%d",&n);
	for( m = 1 ;m <= (n+1) / 2; m++) {
		j = m - 1;
		for( i = m - 1; i < n - m; i++) 
			num[i][j] = a++;
		for( j = m - 1; j < n - m; j++) 
			num[i][j] = a++;
		for( i = n - m; i > m - 1; i--) 
			num[i][j] = a++;
		for( j = n - m; j > m - 1; j--) 
			num[i][j] = a++;
	}
	if( n % 2 == 1) 
		num[n/2][n/2] = a; 
	for( i = 0; i < n; i++){
		printf("%d",num[i][0]);
		for(j = 1; j < n; j++)
			printf(" %-2d",num[i][j]);
		printf("\n");
	}
}
