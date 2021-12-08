//1051 打印等腰三角形
#include<iostream>
using namespace std;
int main()
{
	int n,i,f,x,j,y;
	cin>>n;
    i=1;
    x=n-1;
	for( ; i<=n; i++)
	{
			
		f=1;
		for( ; f<=x; f++)
		{
			cout<<" ";
		}
		x=x-1;
	    j=1;
		for( ; j<=i; j++)
		{
			cout<<"*";
		}
		if(j>2)
		{
			y=1;
			for( ; y<=j-2; y++)
			{
				cout<<"*";
			}
		}
		j=0;
	    cout<<endl;
	} 
    return 0;
} 
