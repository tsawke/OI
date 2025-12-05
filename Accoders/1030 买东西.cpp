//1030 Âò¶«Î÷ 
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
	if((n%4)==0)
	{
		cout<<"A=0 B=0 C=";
		cout<<n/4;
	}
	else
	{
		if((n%4)==1)
		{
			cout<<"A=0 B=1 C="<<n/4-1;
		}
		else
		{
			if((n%4)==2)
			{
				cout<<"A=1 B=0 C="<<n/4-1;
			}
			else
			{
				if((n%4)==3)
				{
					cout<<"A=1 B=1 C="<<n/4-2;
				}	
			}
		}
	}
    return 0;
}
