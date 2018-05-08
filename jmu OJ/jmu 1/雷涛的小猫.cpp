#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int N,H,Delta,k;
	int data[20][50];
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 50; j++)
			data[i][j] = 0;	
	
	cin>>N>>H>>Delta;
	
	for(int i = 0; i < N; i++){
		cin>>data[i][0];
		for( int j = 0; j < data[i][0]; j++){
			cin>>k;
			data[i][k]++;
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < data[i][0]; j++)
			cout<<data[i][j];
		cout<<endl;
	}
}
