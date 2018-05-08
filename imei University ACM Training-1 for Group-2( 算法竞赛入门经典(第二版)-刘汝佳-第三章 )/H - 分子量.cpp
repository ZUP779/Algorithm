#include <iostream>
#include <string>
#include <stdio.h>
#define mc 12.01
#define mh 1.008
#define mo 16.00
#define mn 14.01
using namespace std;
int main()
{
	int n;
	int num;
	double sum;
	string str;
	cin>>n;
	while(n--){
		sum = 0;
		cin>>str;
		for( int i = 0; i < str.size(); i++){
			num = 0;
			if( str[i] == 'C'){
				sum += mc;
				while( i+1 < str.size() && str[i+1] >= '0' && str[i+1] <= '9'){
					num *= 10;
					num += (double)(str[i+1] - '0'); 
					i++;
				}
				if( num)
					num--;
				sum += num * mc;
			}
			else if( str[i] == 'N'){
				sum += mn;
				while( i+1 < str.size() && str[i+1] >= '0' && str[i+1] <= '9'){
					num *= 10;
					num += (double)(str[i+1] - '0'); 
					i++;
				}
				if( num)
					num--;
				sum += num * mn;
			}
			else if( str[i] == 'H'){
				sum += mh;
				while( i+1 < str.size() && str[i+1] >= '0' && str[i+1] <= '9'){
					num *= 10;
					num += (double)(str[i+1] - '0'); 
					i++;
				}
				if( num)
					num--;
				sum += num * mh;
			}
			else if( str[i] == 'O'){
				sum += mo;
				while( i+1 < str.size() && str[i+1] >= '0' && str[i+1] <= '9'){
					num *= 10;
					num += (double)(str[i+1] - '0'); 
					i++;
				}
				if( num)
					num--;
				sum += num * mo;
			}
		}
		printf("%.3lf\n",sum);
	}
}
