//1048 ½Ç¹È²ÂÏë
#include<iostream>
using namespace std;
int main()
{
	int x,i;
	cin>>x;
	while(x>1)
	{
		if(x%2==0)
		{
			cout<<x<<"/2="<<x/2<<endl;
			x=x/2;
		}
		else
		{
			cout<<x<<"*3+1="<<x*3+1<<endl;
			x=x*3+1;
		}
		if(x==1)
		{
			break;
		}
	}
    return 0;
} 
