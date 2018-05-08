#include <stdio.h>
#include <stdlib.h> 
#include <math.h>   
double exp();
int main()   
{   
	double v;   
	v = exp();   
	printf("%f\n",v);   
	return 0;
}   
double exp(){   
	char a[10];   
	scanf("%s",a);   
	switch(a[0]){   
		case'+': return exp( ) + exp( );   
		case'-': return exp( ) - exp( );   
		case'*': return exp( ) * exp( );   
		case'/': return exp( ) / exp( );   
		default: return atof(a);   
	}   
}   
