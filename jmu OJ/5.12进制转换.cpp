#include <stdio.h>
#include <iostream>
using namespace std;
char str[40],ans[200];
int nums[40],n,len;
int main() {
    while(scanf("%s",str) == 1){
        n=0;
        for( n = 0; str[n]; n++) 
			nums[n] = str[n]-'0';
        int d;
        len = 0;
        int start = 0,tmp;
        while(start < n){
            d = 0;
            ans[len++] = nums[n-1]%2 +'0';
            for( int i = start; i<n; i++){
                tmp = nums[i];
                nums[i] = (nums[i]+d) / 2;
                if(tmp % 2) d=10;
                else d=0;
            }
            if(nums[start] == 0) start++;
        }
        for(int i = len - 1; i >= 0; i--)
            printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}
