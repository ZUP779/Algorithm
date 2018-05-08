#include <stdio.h>
int main()
{
	int m,n,a;
	while(1){
		scanf("%d %d",&m,&n);
		if(m == 0|| n == 0)
			break; 
		do{
			a = m % n;
			m = n;
			n = a;
		}while(a != 0);
		printf("%d\n",m);
	}
	return 0;
}
