#include <stdio.h>
int num(int n);
int main()
{
	int n,total = 0;
	scanf("%d",&n);
	printf("%d",num(n));
}
int num(int n)
{
	if( n == 0 || n == 1)
		return 1;
	int total = 0;
	for( int i = 0; i < n ; i++)
		total += num(i)*num(n-1-i); 
	return total;
}
