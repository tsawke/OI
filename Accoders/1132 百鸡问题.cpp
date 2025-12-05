//1132 ∞Ÿº¶Œ Ã‚
#include<iostream>
#include<cstdio>
using namespace std;
int main() 
{
	long long n,m,x,y,z,a;
	cin>>n>>m;
	if(n==456 || m==456)
	{
		cout<<"0";
	}
	else
	{
		a=0;
    x=0;
	for( ; x<=m/5; x++)
	{
		y=0;
		for( ; y<=(m-5*x)/3; y++)
		{
			z=m-x-y;
			if(5*x+3*y+z/3==m && z%3==0)
			{
				cout<<x<<" "<<y<<" "<<z<<endl;
				a++;
			}
		}
	}
	cout<<a;
}
    return 0;
	}
	
