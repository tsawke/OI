//1174 ÕûÀíÒ©Ãû
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[10100];
	int i,j,n;
	cin>>n;
	i=1;
	for( ; i<=n; i++)
	{
		cin>>a;
		if(a[0]>='a' && a[0]<='z')
		{
			a[0]=a[0]-32;
		}
		
		
		j=1;
		for( ; j<strlen(a); j++)
		{
			if(a[j]>='A' && a[j]<='Z')
			{
				a[j]=a[j]+32;
			}
		}
		
		cout<<a<<endl;
		
	}
	
	return 0;
}
