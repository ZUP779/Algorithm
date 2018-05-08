#include <iostream>
#include <vector>
using namespace std;
int myStrcmp(char *s1,char *s2){
	int d = 0;
	while( (*s1) != '\0' || (*s2) != '\0'){
		if( (*s1) > (*s2)){
			d = 1;
			break;
		}
		else if( (*s1) < (*s2)){
			d = -1;
			break;
		}
		s1++;
		s2++;
	}
	return d;
}
int main()
{
	char a[101],b[101];
	cin>>a;
	cin>>b;
	cout<<myStrcmp(a,b);
	return 0;
}
