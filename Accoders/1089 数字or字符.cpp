//1089 Êý×Öor×Ö·û
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a[1010];
	int i;
	cin>>a;
	cout<<strlen(a)<<endl;
	i=0;
	for( ; i<=strlen(a)-1; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	i=strlen(a)-1;
	for( ; i>=0; i--)
	{
		cout<<a[i];
	}
	
	
	return 0;
} 
