//1139 º«ÐÅµã±ø
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,d,m,i,j,k,d2,m2,d3,m3;
	cin>>n;
	i=1;
	for( ; i<=n; i++)
	{
		j=1;
		cin>>d>>m>>d2>>m2>>d3>>m3;
		k=1; 
		for( ; k<=1000000; k++)
		{
			if(k%d==m && k%d2==m2 && k%d3==m3)
			{
				cout<<k<<endl;
				break;
			}
		}
	}
	return 0;
} 
