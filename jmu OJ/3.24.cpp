#include <stdio.h>
#include <iostream>
#define Max 1000
using namespace std;
typedef struct{
	int i;
	int j;
}Point;
typedef struct{	
	Point data[Max];
	int top;
}SqStack;

SqStack q,ans;
int num = 0,len = 999;
int xi,yi,xe,ye;
int mg[10][10]={0};

void Get();
bool Exist(int x,int y);
bool RoadExist(int xi,int yi,int xe,int ye);
void Path(int x,int y);
void PrintStack(SqStack q);

int main()
{
	int i,j;
	int M;
	cin>>xi>>yi>>xe>>ye;
	cin>>M;
	for( int k = 0; k < M; k++){
		cin>>i>>j;
		mg[i][j] = 1;
	}
	//Init
	ans.top = -1;
	q.top = -1;
	q.top++;
	q.data[q.top].i = xi;
	q.data[q.top].j = yi;
	
	Path(xi,yi);
	
	if( num == 1)
		PrintStack(ans);
	else
		printf("%d",num);
	return 0;
}
void Get()
{   
 	for( int i = 0; i  <= q.top ; i++)   
		ans.data[i] = q.data[i];
	ans.top = q.top;
	len = q.top + 1;
	if(q.top == len)
		num++;
	else 
		num = 1;
//	PrintStack(ans);
}
bool Exist(int x,int y)   
{   
	int i;
	if(mg[x][y] != 0|| x < 0|| y < 0|| x > xe|| y > ye)         
    	return false;

 	for( i = 0; i <= q.top; i++)   
    	if( q.data[i].i == x && q.data[i].j == y)           
    		return false;
/*	if(q.top > 10)
    	return false;*/
 	return true;
}
bool RoadExist(int xi,int yi,int xe,int ye)
{
	if( xe == xi + 1 || xe == xi -1)
		if(mg[xi][(yi+ye)/2] == 1)
			return false;
	if( ye == yi + 1 || ye == yi -1)
		if(mg[(xi+xe)/2][yi] == 1)
			return false;
	return true;
}
void Path(int x,int y)   
{   
	if(x == xe && y == 	ye && q.top <= len)
		Get();
	else{
		if(Exist(x-1,y-2) && RoadExist(x,y,x-1,y-2)){   
			q.top++;   
			q.data[q.top].i = x - 1;
			q.data[q.top].j = y - 2;
			Path(x-1,y-2);
			q.top--;
		}	   
    	if(Exist(x-1,y+2) && RoadExist(x,y,x-1,y+2)){   
			q.top++;   
	    	q.data[q.top].i = x - 1;   
	    	q.data[q.top].j = y + 2;
	    	Path(x-1,y+2);   
	    	q.top--;   
	   	}	   
	    if(Exist(x-2,y+1) && RoadExist(x,y,x-2,y+1)){   
			q.top++;   
	   		q.data[q.top].i = x - 2;
	 		q.data[q.top].j = y + 1; 
	   		Path(x-2,y+1);   
	    	q.top--;   
	   	}   
	    if(Exist(x-2,y-1) && RoadExist(x,y,x-2,y-1)){   
	    	q.top++;   
	   		q.data[q.top].i = x - 2;
   	 		q.data[q.top].j = y - 1;  
	    	Path(x-2,y-1);   
	    	q.top--;   
	   	}   
	   	if(Exist(x+1,y+2) && RoadExist(x,y,x+1,y+2)){   
    		q.top++;   
   	 		q.data[q.top].i = x + 1;
   	 		q.data[q.top].j = y + 2;
    		Path(x+1,y+2);
    		q.top--;
   		}	   
    	if(Exist(x+1,y-2) && RoadExist(x,y,x+1,y-2)){   
			q.top++;   
	    	q.data[q.top].i = x + 1;   
	    	q.data[q.top].j = y - 2;
	    	Path(x+1,y-2);   
	    	q.top--;   
	   	}	   
	    if(Exist(x+2,y+1) && RoadExist(x,y,x+2,y+1)){   
			q.top++;   
	   		q.data[q.top].i = x + 2;
   	 		q.data[q.top].j = y + 1; 
	   		Path(x+2,y+1);   
	    	q.top--;   
	   	}   
	    if(Exist(x+2,y-1) && RoadExist(x,y,x+2,y-1)){   
	    	q.top++;   
	   		q.data[q.top].i = x + 2;
   	 		q.data[q.top].j = y - 1;  
	    	Path(x+2,y-1);   
	    	q.top--;   
	   	}   
 	}   
}
void PrintStack(SqStack q)
{
	for( int i = 0; i < q.top; i++)
		printf("(%d,%d)-",q.data[i].i,q.data[i].j);
	printf("(%d,%d)",q.data[q.top].i,q.data[q.top].j);
}
