//1163 rainbow”Îfreda»æ∆Ï
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int i,j,n,m,x=0;
	char s[100010];
	cin>>n>>m;
	cin>>s;
	i=1;
	for( ; i<n; i++)
	{
		if(s[i]==s[i-1])
		{
			x++;
			i++;
		}
	}
	cout<<x;
	return 0;
	
} 
