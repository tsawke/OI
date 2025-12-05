//1057 ÍêÈ«Êı
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,i,i2,x;
	cin>>a>>b;
	
	i=a;
	for( ; i<=b; i++)
	{
		i2=1;
		x=0;
		for( ; i2<i; i2++)
		{
			if(i%i2==0)
			{
				x=x+i2;
			}
		}
		if(x==i)
		{
			cout<<x<<endl;
		}
	}
    return 0;
} 
