#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
	int n,i,j,len,Max,max;
	int num[26];
	char ch[1001];
	cin>>n;
	for( i = 0; i < n; i++){
		
		Max = -1;
		for( j = 0; j < 26; j++)
			num[j] = 0;
		
		cin>>ch;
		len = strlen(ch);
		for( j = 0; j < len; j++)
			num[ch[j]-'a']++;
		for( j = 0; j < 26; j++)
			if(num[j] > Max){
				Max = num[j];
				max = j;
			}
		
		printf("%c %d\n",max + 'a',num[max]);
	}
	return 0;
}
