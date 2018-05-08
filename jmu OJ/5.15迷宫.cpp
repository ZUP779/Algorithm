#include <stdio.h>
#include <iostream>
using namespace std;
#define Max 10005
typedef struct{
	int i,j;
	int pre;
}Point;
typedef struct{
	Point data[Max];
	int front;
	int rear;	
}SqQueue;
bool Path(int xi,int yi,int xe,int ye,int M,char mg[][100]);
void print(SqQueue q,int front,int xe,int ye);
int main()
{
	char mg[100][100];
	int i,j,M,N,xi,yi,xe,ye,k;
	cin>>k;
	while( k--){
		cin>>M;

		for( i = 0; i < M; i++)
			for( j = 0; j < M; j++)
				cin>>mg[i][j];
				
		cin>>xi>>yi>>xe>>ye;
	
		printf(Path(xi,yi,xe,ye,M,mg)?"YES\n":"NO\n");
	}
	return 0;
}

bool Path(int xi,int yi,int xe,int ye,int M,char mg[][100])
{
	if(mg[xi][yi] == '#' || mg[xe][ye] == '#')
		return false;
	int i,j,find = 0,di;
	SqQueue q;
	q.front = q.rear = -1;
	q.rear++;
	q.data[q.rear].i = xi;	q.data[q.rear].j = yi;
	q.data[q.rear].pre = -1;
	mg[0][0] = -1;
	while( q.front != q.rear && !find){
		q.front++;
		i = q.data[q.front].i;	j = q.data[q.front].j;
		if( i == xe && j == ye){
			find = 1;
			return true;
		}
		for( di = 0; di < 4; di++){
			switch(di){
				case 0:	i = q.data[q.front].i - 1;	j = q.data[q.front].j;	break;
				case 1:	i = q.data[q.front].i;	j = q.data[q.front].j + 1;	break;
				case 2:	i = q.data[q.front].i + 1;	j = q.data[q.front].j;	break;
				case 3:	i = q.data[q.front].i;	j = q.data[q.front].j - 1;	break;
			}
			if( i >= 0 && j >= 0 && i < M && j < M)
				if(mg[i][j] == '.'){
					q.rear++;
					q.data[q.rear].i = i;	q.data[q.rear].j = j;
					q.data[q.rear].pre = q.front;
					mg[i][j] = 's';
				}
		}
	}
	return false;
}
