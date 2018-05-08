#include <stdio.h>
struct math{
	int x;//系数
	int y;//幂数 
};
typedef struct math M;
int main()
{
	bool exist = false;
	int n,time = 0,i = 0,j = 0,k,temp,len = 0;
	scanf("%d",&n);
	int q[2*n];
	M a[n*2][301],b[n][301];
	while(time < (2 * n)){
		scanf("%d %d",&a[time][i].x,&a[time][i].y);
		if(a[time][i].y < 0){
			q[time] = i;
			time++;
			i=0;
		}
		else 
			i++;
	}
	
	for( i = 0; i < 2*n; i+=2){
		len = 0;
		for( j = 0; j < q[i]; j++){
			exist = false;
			for( k = 0; k < len; k++){
				if( b[i/2][k].y == a[i][j].y){
					b[i/2][k].x += a[i][j].x;
					exist = true;
				}
			}
			if(!exist){
				b[i/2][len].x = a[i][j].x;
				b[i/2][len].y = a[i][j].y;
				len++;
			}
		}//将第一行中所有值存入b结构体数组 
		
		for( j = 0; j < q[i+1]; j++){
			for( k = 0; k < len; k++){
				if(b[i/2][k].y == a[i+1][j].y){
						b[i/2][k].x += a[i+1][j].x;
						exist = true;
				}
			}
			if(!exist){
				b[i/2][len].x = a[i+1][j].x;
				b[i/2][len].y = a[i+1][j].y;
				len++;		
			}
			exist = false; 
		}
		
		q[i/2] = len;
	}
	//排序 
	for( i = 0; i < n; i++){
		for( j = 0; j < q[i] - 1; j++)	
			for( k = 0; k < q[i] - j - 1; k++){
				if(b[i][k].y < b[i][k+1].y){
					temp = b[i][k].y;
					b[i][k].y = b[i][k+1].y;
					b[i][k+1].y = temp;
					
					temp = b[i][k].x;
					b[i][k].x = b[i][k+1].x;
					b[i][k+1].x = temp;
				}
			}
	}
	//删除系数为0的项 
	for( i = 0; i < n; i++){
		for( j = 0; j < q[i]; j++){
			if(b[i][j].x == 0){
				for( k = j; k < q[i]; k++){
					b[i][k].x = b[i][k+1].x;
					b[i][k].y = b[i][k+1].y;
				}
				q[i]--;
			}
		}
	}

	for( i = 0; i < n; i++){	
		for( j = 0; j < q[i]-1; j++)
			printf("[ %d %d ] ",b[i][j].x,b[i][j].y);
		if( q[i]-1 >= 0)
			printf("[ %d %d ]",b[i][q[i]-1].x,b[i][q[i]-1].y);
		printf("\n");
	}

	return 0;
}
