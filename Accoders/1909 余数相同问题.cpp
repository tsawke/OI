//1909 余数相同问题
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,x;
	cin>>a>>b>>c;
	for(x=2; ; x++)
	{
		if(a%x==b%x && b%x==c%x)
		{
			cout<<x;
			break;
		}
	}
	
	return 0;
} 
