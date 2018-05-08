#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  

int max(int a,int b){ return a>b?a:b; }  
int min(int a,int b){ return a<b?a:b; }  
  
int main(){  
    int N, len, n, dist;  
    scanf("%d",&N);  
    while(N--){  
        scanf("%d%d",&len, &n);  
        int sho = 0, lat = 0;   
        for(int i=0; i<n; ++i){  
            scanf("%d",&dist);  
            lat = max(lat, max(dist, len-dist));  
            sho = max(sho, min(dist, len-dist));  
        }  
        printf("%d %d\n", sho, lat);  
    }  
    return 0;  
}  
