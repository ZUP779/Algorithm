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

int len = 999,mg[5][5];   
SqStack q,p;
void Set();
bool Exist(int x,int y);
void Path(int x,int y);
void Print(void);
int main()   
{   
	q.top = 0;
 	for(int i = 0; i < 5; i++)
   		for( int j = 0; j < 5; j ++)
    		cin>>mg[i][j];

	q.top++;
	q.data[q.top].i = 0;
	q.data[q.top].j	= 0;
	
	Path(0,0);
	
	Print();
	
	return 0;
}

void Set()           
{
	if( q.top > len) 
		return;
	int i;   
 	len = q.top;
 	for( i = 1; i <= q.top; i++)   
		p.data[i] = q.data[i];
	p.top = q.top;  
}
bool Exist(int x,int y)   
{   
	int i;   
	if(mg[x][y] != 0|| x < 0|| y < 0|| x >= 5|| y >= 5)         
    	return false;   
   
 	for( i = 1; i <= q.top; i++)   
    	if(q.data[i].i == x && q.data[i].j == y)           
    		return false;   
 	return true;   
}    
   
void Path(int x,int y)   
{   
	if(x == 4 && y == 4)   
    	Set();
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
void Print(void)
{
	for( int j = 1; j <= p.top; j++)
		printf("(%d, %d)\n",p.data[j].i,p.data[j].j);
}
