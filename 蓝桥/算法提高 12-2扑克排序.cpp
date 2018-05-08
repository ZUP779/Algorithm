#include <iostream>
using namespace std;
typedef struct{
	int c;
	int num;
	char C;
	char N;
}Pock;
int main()
{
	char ch;
	Pock p[5],temp;
	for(int i = 0; i < 5; i++){
		cin>>ch;
		p[i].N = ch;
		if( ch == '1'){
			cin>>ch;
			p[i].num = 10;
		}
		else if(ch == 'J')
			p[i].num = 11;
		else if(ch == 'Q')
			p[i].num = 12;
		else if(ch == 'K')
			p[i].num = 13;
		else if(ch == 'A')
			p[i].num = 14;
		else if(ch <= '9' && ch >= '2')
			p[i].num = ch - '0';
		
		cin>>ch;
		p[i].C = ch;
		if( ch == 'd')
			p[i].c = 1;
		else if( ch == 'c')
			p[i].c = 2;
		else if( ch == 'h')
			p[i].c = 3;
		else if( ch == 's')
			p[i].c = 4;
	}
	for(int i = 0; i < 5 - 1; i++){
		for( int j = 0; j < 5 - i - 1; j++){
			if( p[j].num > p[j+1].num){
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
			else if( p[j].num == p[j+1].num){
				if( p[j].c > p[j+1].c){
					temp = p[j];
					p[j] = p[j+1];
					p[j+1] = temp;
				}
			}
		}
	}
	for( int i = 0; i < 5; i++){
		if(p[i].N == '1')
			cout<<"10";
		else
			cout<<p[i].N;
		cout<<p[i].C<<" ";
	}
	return 0;
}
