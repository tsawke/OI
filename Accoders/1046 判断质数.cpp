//1046 еп╤ожййЩ
#include<iostream>
using namespace std;
int main()
{
	int x,i,f=1;
	cin>>x;
	f=1;
for(i=2; i*i<=x; i++)
	if(x%i==0)
	{
		f=0;
		break;
	}
	if(f==1)
	    cout<<"prime";
	else
	    cout<<"not prime";
    return 0;
} 
