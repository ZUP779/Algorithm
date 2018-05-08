#include<stdio.h>   
#include<iostream>
#define Max 256
using namespace std;
typedef struct{
	int i;
	int j;
}Point;
typedef struct{	
	Point data[Max];
	int top;
}SqStack;

int m,n,mg[16][16],k=1,xe,ye,xi,yi;   
bool exist = false;
SqStack q;
void Print();
bool Exist(int x,int y);
void Path(int x,int y);

int main()   
{   
	q.top = 0;
	cin>>m>>n;
 	for(int i = 1; i <= m; i++)
   		for( int j = 1; j <= n; j ++)
    		cin>>mg[i][j];

	cin>>xi>>yi>>xe>>ye;

	q.top++;
	q.data[q.top].i = xi;
	q.data[q.top].j	= yi;
	
	Path(xi,yi);
    
	if(!exist)                          
    	printf("-1");   
}

void Print()           
{   
	int i;   
 	exist = true;   
 	for( i = 1; i <= q.top - 1; i++)   
    	printf("(%d,%d)->",q.data[i].i,q.data[i].j);   

	printf("(%d,%d)\n",q.data[q.top].i,q.data[q.top].j);   
}
bool Exist(int x,int y)   
{   
	int i;   
	if(mg[x][y] != 1|| x < 0|| y < 0|| x > m|| y > n)         
    	return false;   
   
 	for( i = 1; i <= q.top; i++)   
    	if(q.data[i].i == x && q.data[i].j == y)           
    		return false;   
 	return true;   
}    
   
void Path(int x,int y)   
{   
	if(x == xe && y == 	ye)   
    	Print();
 	else{
  		if(Exist(x-1,y)){
    		q.top++;
   	 		q.data[q.top].i = x-1;
   	 		q.data[q.top].j = y;
    		Path(x-1,y);
    		q.top--;
		}
    	if(Exist(x,y-1)){   
			q.top++;   
	    	q.data[q.top].i = x;   
	    	q.data[q.top].j = y-1;
	    	Path(x,y-1);   
	    	q.top--;   
	   	}	   
	    if(Exist(x,y+1)){   
			q.top++;   
	   		q.data[q.top].i = x;
   	 		q.data[q.top].j = y + 1; 
	   		Path(x,y+1);   
	    	q.top--;   
	   	}   
	    if(Exist(x+1,y)){   
	    	q.top++;   
	   		q.data[q.top].i = x+1;
   	 		q.data[q.top].j = y;  
	    	Path(x+1,y);   
	    	q.top--;   
	   	}   
 	}   
}
