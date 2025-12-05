//1161 ÄãµÄ·ÉµúÔÚÕâ
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	char a1[10],a2[10];
	int i,a=1,b=1;
	cin>>a1[10];
	cin>>a2[10];
	i=0;
	for( ; i<strlen(a1); i++)
	{
		a=a*a1[i]-'A'+1;
	}
	a=a%47;
	
	i=0;
	for( ; i<=strlen(a2); i++)
	{
		b=b*a2[i]-'A'+1;
	}
	b=b%47;
	
	if(a==b)
	{
		cout<<"GO";
	}
	else
	{
		cout<<"STAY";
	}
	
	return 0;
	 
	
} 
