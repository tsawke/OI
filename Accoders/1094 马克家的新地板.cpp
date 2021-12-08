//1094 马克家的新地板
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void prt(int m,char k)
{
	int i;
	i=1;
	for( ; i<=m; i++)
	{
		cout<<k;
	}
	cout<<endl;
} 

int main()
{
	int n,m;
	char k;
	cin>>n;
	int i;
	i=1;
	for( ; i<=n; i++)
	{
		cin>>m>>k;
		prt(m,k);
	}
	
	
	
	return 0;
}
