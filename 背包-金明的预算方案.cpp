#include <bits/stdc++.h>
#define MAXM 32005
#define MAXN 65
/*
	������Ԥ�㷽����
	�������ı������� - 
	�������Ž���https://blog.csdn.net/pi9nc/article/details/8142876�� 

	��Ŀ����Ǯ��n����Ʒ��Ŀm����Ӧv p q���� 
	
	������l�������Ϊl�飬ÿ������ֻ���Ǹ�����ֵ��01������
	����f[l][money]����Ӧ����money�õ�������ֵ��0<=money<=m-v[l],
	���ڷ��븽��ǰ�����ȷ���������
	������ֵF[l][money] = f[l][money-v[l]] + v[l]*p[l],  v[l]<=money<=m
	
	���������������ı������⻯��Ϊ����ı������⣬
	������f����ÿ��F[l]��ѡ��һ���������õ�������ֵ
	
	(ע��forѭ��˳��)
	for( i = 0; i < l; i++)//����l�� 
		for( j = n; j >= v[i]; j--)//������ֵ 
			for( k = v[i]; k <= n; k++)//�����������п��� 
				dp[j] = max(dp[j],dp[j-k]+F[i][k]);
	
*/
using namespace std;
int n,m;
int mainNum;//����(����)��Ŀ 
int l[MAXN]={0};//��¼ÿ��������Ʒ���� 
int v[MAXN][MAXN]={0};//��¼ÿ����������������vֵ������v[i][0]��������,1~k[i]-1������ 
int p[MAXN][MAXN]={0};//ͬ�� 

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
			
			//��ÿ���ڵĸ�����01���� 
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
	for( i = 0; i < l; i++)//����l�� 
		for( j = n; j >= v[i]; j--)//������ֵ 
			for( k = v[i]; k <= n; k++)//�����������п��� 
				dp[j] = max(dp[j],dp[j-k]+F[i][k]);
	*/
	for( int i = 1; i <= m; i++){
		if( l[i] == 0)
			continue;
		for( int j = n; j >= v[i][0]; j--){
			for( int k = v[i][0]; k <= j && k <= v[i][0]+v[i][1]+v[i][2]; k++){//k�ķ�Χ��Ҫ�Ż���kֵ��߲����ܴ������и���֮�� 
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
