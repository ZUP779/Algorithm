#include <stdio.h>
#include <iostream>
using namespace std;
#define Max 300
typedef struct{
	int i,j;
	int pre;
}Point;
typedef struct{
	Point data[Max];
	int front;
	int rear;	
}SqQueue;
bool Path(int xi,int yi,int xe,int ye,int mg[][15]);
void print(SqQueue q,int front,int xe,int ye);
int main()
{
	int mg[15][15]={0};
	int i,j,M,N,xi,yi,xe,ye;
	cin>>M>>N;
	for( i = 0; i < M; i++)
		for( j = 0; j < N; j++)
			cin>>mg[i][j];
			
	cin>>xi>>yi>>xe>>ye;

	if(!Path(xi,yi,xe,ye,mg))
		printf("-1");
	return 0;
}

bool Path(int xi,int yi,int xe,int ye,int mg[][15])
{
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
			print(q,q.front,xe,ye);
			return true;
		}
		for( di = 0; di < 4; di++){
			switch(di){
				case 0:	i = q.data[q.front].i - 1;	j = q.data[q.front].j;	break;
				case 1:	i = q.data[q.front].i;	j = q.data[q.front].j + 1;	break;
				case 2:	i = q.data[q.front].i + 1;	j = q.data[q.front].j;	break;
				case 3:	i = q.data[q.front].i;	j = q.data[q.front].j - 1;	break;
			}
			if( i >= 0 && j >= 0)
				if(mg[i][j] == 0){
					q.rear++;
					q.data[q.rear].i = i;	q.data[q.rear].j = j;
					q.data[q.rear].pre = q.front;
					mg[i][j] = -1;
				}
		}
	}
	return false;
}

void print(SqQueue q,int front,int xe,int ye)
{
	int k = front,j,ns = 0;
	do{
		j = k;
		k = q.data[k].pre;
		q.data[j].pre = -1;
	}while(k != 0);
	k = 0;
	while( k < Max){
		if( q.data[k].pre == -1){
			ns++;
			printf("(%d,%d)",q.data[k].i,q.data[k].j);
			if( ns % 5 == 0)	printf("\n");
		}
		if(q.data[k].i == xe && q.data[k].j == ye)
			return;
		k++;
	}
}
