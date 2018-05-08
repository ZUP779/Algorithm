#include <iostream>
#include <string>
using namespace std;
string str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
string str2 = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
bool ispal(string str){
	for( int i = 0; i < str.size() / 2; i++)
		if( str[i] != str[str.size()-i-1])
			return false;
	return true;
}
bool ismir(string str){
	for( int i = 0; i <= str.size() / 2; i++){
		for( int j = 0; j < str1.size(); j++){
			if( str[i] == str1[j]){
				if( str2[j] == ' ' || str[str.size()-1-i] != str2[j]){
					//cout<<str[i]<<str[str.size()-1-i];
					return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	bool f1,f2;
	string str;
	while(cin>>str){
		f1 = false;
		f2 = false;
	
		if( ispal(str))
			f1 = true;
		if( ismir(str))
			f2 = true;
			
		//cout<<f1<<f2;
		if( f1 && f2)
			cout<<str<<" -- is a mirrored palindrome."<<endl<<endl;
		else if( f1)
			cout<<str<<" -- is a regular palindrome."<<endl<<endl;
		else if( f2)
			cout<<str<<" -- is a mirrored string."<<endl<<endl;
		else
			cout<<str<<" -- is not a palindrome."<<endl<<endl;
	}
	return 0;
}
