#include <iostream>
using namespace std;
int main()
{
	char str[55];
	cin>>str;
	for( int i = 0; str[i] != '\0'; i++){
		if( str[i] >= 'A' && str[i] < 'Z')
			str[i]++;
		else if( str[i] == 'Z')
			str[i] = 'a';
		else if( str[i] >= 'a' && str[i] < 'z')
			str[i]++;
		else if( str[i] == 'z')
			str[i] = 'A';
	}
	cout<<str;
	return 0;
}
