//1055 ½×³ËºÍ
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long i,n,x,a,b;
	cin>>n;
	b=0;
	for(i=1; i<=n; i++)
	{
	    a=1;
		for(x=1; x<=i; x++)
		{
			a=a*x;
		}
	    b=b+a;
	}
	cout<<b;
	return 0;
}
