#include <bits/stdc++.h>
#define MAXM 32005
#define MAXN 65
/*
	金明的预算方案：
	有依赖的背包问题 - 
	（背包九讲：https://blog.csdn.net/pi9nc/article/details/8142876） 

	题目给出钱数n，物品数目m，对应v p q数组 
	
	设主件l个，则分为l组，每组组内只考虑附件价值做01背包，
	则有f[l][money]，对应花费money得到的最大价值，0<=money<=m-v[l],
	由于放入附件前必须先放入主件，
	则最后价值F[l][money] = f[l][money-v[l]] + v[l]*p[l],  v[l]<=money<=m
	
	则问题由有依赖的背包问题化简为分组的背包问题，
	即遍历f，在每个F[l]中选择一个，求最后得到的最大价值
	
	(注意for循环顺序)
	for( i = 0; i < l; i++)//遍历l组 
		for( j = n; j >= v[i]; j--)//遍历价值 
			for( k = v[i]; k <= n; k++)//遍历组中所有可能 
				dp[j] = max(dp[j],dp[j-k]+F[i][k]);
	
*/
using namespace std;
int n,m;
int mainNum;//主件(分组)数目 
int l[MAXN]={0};//记录每个分组物品个数 
int v[MAXN][MAXN]={0};//记录每个分组中主附件的v值，其中v[i][0]代表主件,1~k[i]-1代表附件 
int p[MAXN][MAXN]={0};//同上 

int f[MAXN][MAXM]={0};
int F[MAXN][MAXM]={0};

int dp[MAXM];
int main()
{
	cin>>n>>m;
//	scanf("%d%d",&n,&m);
	int V,P,Q;
	n/=10;
	for( int i = 1; i<= m; i++){
		cin>>V>>P>>Q;
//		scanf("%d%d%d",&V,&P,&Q);
		V/=10;
		if( Q != 0){
			v[Q][l[Q]] = V;
			p[Q][l[Q]] = P;
			
			l[Q]++;
		}
		else{
			v[i][0] = V;
			p[i][0] = P;
			
			l[i] = 1;	
		}
		
	}
	
	for( int i = 1; i <= m; i++ ){
		if( l[i] != 0){
			
			//对每组内的附件做01背包 
			for( int j = 1; j < l[i]; j++){
				for( int k = n - v[i][0]; k >= v[i][j]; k --){
					f[i][k] = max( f[i][k],f[i][k-v[i][j]]+v[i][j]*p[i][j]);
				}
			}
			
			//F[l][money] = f[l][money-v[l]] + v[l]*p[l],  v[l]<=money<=m
			for( int j = v[i][0]; j <= n; j++){
				F[i][j] = f[i][j-v[i][0]] + v[i][0]*p[i][0];
			}
			
		}
	}
	/*
	for( i = 0; i < l; i++)//遍历l组 
		for( j = n; j >= v[i]; j--)//遍历价值 
			for( k = v[i]; k <= n; k++)//遍历组中所有可能 
				dp[j] = max(dp[j],dp[j-k]+F[i][k]);
	*/
	for( int i = 1; i <= m; i++){
		if( l[i] == 0)
			continue;
		for( int j = n; j >= v[i][0]; j--){
			for( int k = v[i][0]; k <= j && k <= v[i][0]+v[i][1]+v[i][2]; k++){//k的范围需要优化，k值最高不可能大于所有附件之和 
				dp[j] = max(dp[j],dp[j-k] + F[i][k]); 
			}
		}
	}
	
//	cout<<F[1][40]<<" ";
//	cout<<endl;
	
	
	cout<<dp[n]*10;
	return 0;
}
/*
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0

800 5
400 3 0
400 5 1
300 5 1
400 3 0
500 2 0

*/
