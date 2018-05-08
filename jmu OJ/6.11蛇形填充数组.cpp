#include <stdio.h>

int main()
{
	int num[10][10] = {0},number[20] = {0};
	int i = 0,j = 0,a = 1,count;
	int n,m;
	scanf("%d",&n);
	for( int k = 0; k < 2 * n - 1; k++){
		if( k < n)
			number[k] = k + 1;
		else number[k] = number[k-1] - 1;
	}
	for( m = 1; m <= 2 * n - 1; m++){
		count = 0;
		while(1){
			num[i][j] = a++;
			count ++;
			if( count == number[m-1]){
				if( m < n){
					if( m % 2)
						j++;
					else
						i++;
				}
				else{
					if( m % 2)
						i++;
					else
						j++;	
				}
				break;
			}
			if( m % 2 == 0){
				i++;	j--;
			}
			else{
				i--;	j++;
			}
		}
	}
	for( i = 0; i < n; i++){
		printf("%d",num[i][0]);
		for( j = 1; j < n; j++)
			printf(" %d",num[i][j]);
		printf("\n");
	}
}
