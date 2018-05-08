#include <stdio.h>
#include <string.h>
#include <math.h> 
int main()
{
	int i,n,x,j;
	scanf("%d",&n);
	char a[n][10001];
	int b[n];
	char c[n][10001];
	for( i = 0; i < n; i++){
		scanf("%s",a[i]);
		b[i] = 0;
	}
	for( i = 0; i < n; i++){
		x = 1;
		for( j = strlen(a[i]) - 1; j >= 0; j--){
			b[i] += (a[i][j] - '0') * x;
			x *= 2;
		}
	}
	/*for( i = 0; i < n; i++)
		printf("%X\n",b[i]);*/
	for(i = 0; i < n; i++){
		x = 1;
		while(pow(16,x) <= b[i])
			x++;
		for(j = 0; x!=0; j++ ){
			x--;
			if((int)(b[i] / pow(16,x)) >= 10){
				c[i][j] = b[i] / pow(16,x) + 'A';
				b[i] -= (c[i][j] - 'A') * pow(16,x);
			}
			else{
				c[i][j] = b[i] / pow(16,x) + '0';
				b[i] -= (c[i][j] - '0') * pow(16,x);
			}
			/*switch((int)(b[i] / pow(16,x))){
				case 0:	
				case 1:	
				case 2:	
				case 3:	
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:	
					c[i][j] = b[i] / pow(16,x) + '0';
					b[i] -= (c[i][j] - '0') * pow(16,x);	
					break;
				case 10:
					c[i][j] = 'A';
					b[i] -= 10 *pow(16,x);
					break;
				case 11:
					c[i][j] = 'B';
					b[i] -= 11 *pow(16,x);
					break;
				case 12:
					c[i][j] = 'C';
					b[i] -= 12 *pow(16,x);
					break;
				case 13:
					c[i][j] = 'D';
					b[i] -= 13 *pow(16,x);
					break;
				case 14:
					c[i][j] = 'E';
					b[i] -= 14 *pow(16,x);
					break;
				case 15:
					c[i][j] = 'F';
					b[i] -= 15 *pow(16,x);
					break;
			}
			*/
		}
		c[i][j]='\0';
	}
	for( i = 0; i < n; i++)
		printf("%s\n",c[i]);
	return 0;
}
