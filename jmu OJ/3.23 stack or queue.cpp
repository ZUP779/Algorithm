#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char q[2000],w[2000];
	int i,j,t,n,a,b,A,B;

	scanf("%d",&t);
	
	for( i = 0; i < t; i++){

		scanf("%d",&n);
		A = 0;
		B = 0;
		for( j = 0; j < n; j++){
			scanf("%d",&a);
			scanf("%d",&b);
			
			
			if( a == 1)
				q[A++] = b + '0';
			else
				w[B++] = b + '0';
		}
		q[A] = '\0';
		w[B] = '\0';
		
		if(!strcmp(q,w))
			printf("Queue\n");
		else
			printf("Stack\n");
	}

}
