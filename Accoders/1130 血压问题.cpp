//1130 —™—πŒ Ã‚
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,i,n,t,max;
	cin>>n;
	t=0;
	max=0;
	i=1;
	for( ; i<=n; i++)
	{
		cin>>a>>b;
		if(a>=90 && a<=140 && b>=60 && b<=90)
		{
			t++;
			if(t>max)
			{
				max=t;
			}
		}
		else
		{
			t=0;
		}
	}
	cout<<max;
    return 0;
} 
