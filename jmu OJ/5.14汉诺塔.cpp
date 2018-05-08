#include <iostream>  
using namespace std;  
void moveOne(int numDisk, char init, char desti);
void move(int numDisks, char init, char temp, char desti);
int main()  
{  
    int n;
	char init,temp,desti;
	cin >> n >> init >> temp >> desti;
	move(n,init,temp,desti);    
    return 0;  
}
void moveOne(int numDisk, char init, char desti)
{  
    cout << numDisk << ":" << init << "->" << desti << endl;  
}

void move(int numDisks, char init, char temp, char desti)  
{  
    if(numDisks == 1)  
        moveOne(1, init, desti);  
    else  
    {  
           
        move(numDisks-1, init, desti, temp);
        moveOne(numDisks, init, desti);     
        move(numDisks-1, temp, init, desti);
    }  
}   
  

