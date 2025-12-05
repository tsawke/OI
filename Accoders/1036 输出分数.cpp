//1036 Êä³ö·ÖÊı
#include<iostream>
#include<cstdio>
using namespace std;
int main() 
{
	int n,i;
	cin>>n;
	cout<<"1";
	i=2;
	for( ; i<=n; i++)
	{
		if(i%2==1)
		{
			cout<<",1/"<<i;
		}
		else
		{
			cout<<",-1/"<<i;
		}
	}
    return 0;
}
