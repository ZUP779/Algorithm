#include <iostream>
using namespace std;
void DelPack(char *s){
	for( int i = 0; s[i] != '\0'; i++){
		for( int j = i + 1; s[j] != '\0'; j++){
			if( s[j] == s[i]){
				for( int k = j; s[k] != '\0'; k++)
					s[k] = s[k+1];
				for( int k = i; s[k] != '\0'; k++)
					s[k] = s[k+1];
			}
		}
	}
}
int main()
{
	char str[105];
	cin>>str;
	DelPack(str);
	cout<<str;
	return 0;
}
