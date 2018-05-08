#include <stdio.h>
int gcd(int n1,int n2);
int main()
{
	int n1,n2;
	while(scanf("%d%d",&n1,&n2)==2)
		printf("%d\n",gcd(n1,n2));
	return 0;
	
}
/*int gcd(int n1,int n2)
{
	int temp;
	if( n1 < n2){
		temp = n1;
		n1 = n2;
		n2 = temp;
	}
	if( n1 - n2 == n2)
		return n2;
	return gcd(n2,n1-n2);
	
}*/
int gcd(int n1,int n2)
{
	int temp;
	do{
		temp = n1 % n2;
		n1 = n2;
		n2 = temp;
	}while(n2);
	return n1;
}
