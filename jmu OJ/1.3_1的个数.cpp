#include <stdio.h>
#include <math.h>

int main()
{
	int i,n,x,c;
	scanf("%d",&n);
	int a[n];
	int b[n];
	for(i = 0; i < n; i++)
		b[i] = 0;
	for(i = 0; i < n; i++)
		scanf("%d",&a[i]);
	for(i = 0; i < n; i++){
		x = 1;
		while(pow(2,x) <= a[i])
			x++;
		while(x != 0){
			x--;
			c=pow(2,x);
			if((int)(a[i] / pow(2,x)) == 1)
				b[i]++;
			a[i] -= (int)(a[i] / pow(2,x)) * pow(2,x);
		}
	}
	for(i = 0; i < n; i++)
		printf("%d\n",b[i]);	
}
