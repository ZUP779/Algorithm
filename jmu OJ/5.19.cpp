#include <stdio.h>
long f(int n);
int main()
{
	int n;
	while(scanf("%d",&n) == 1){
/*		if( n  > 46 || n < 0)
			break;*/
		printf("%ld\n",f(n-1));
	}
}
/*int f(int n)
{
	if( n == 0)
		return 0;
	if( n == 1 || n == 2)
		return 1;
	return f(n-1) + f(n-2);
}*/
long f(int n)
{
	if( n == 0 || n == 1)
		return 1;
	long a = 1,b = 1,result;
	for(int i = 2; i <= n; i++){
		result = a + b;
		a = b;
		b = result;
	}
	return b;
}
