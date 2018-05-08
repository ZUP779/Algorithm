#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> queue;
	int front = 0;
	int rear = 0;
	int n,d;
	queue.resize(55,0);
	cin>>n;
	while(n--){
		cin>>d;
		switch(d){
			case 1:	cin>>d;
					queue[rear++] = d;
					break;
			case 2:	if(rear == front){
						cout<<"no"<<endl;
						return 0;
					}
					cout<<queue[front++]<<endl;
					break;
			case 3:	cout<<(rear - front)<<endl;
					break;
		}
	}
}
