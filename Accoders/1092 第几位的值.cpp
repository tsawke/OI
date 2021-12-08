//1092 第几位的值
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int digit(int n,int k)
{
	int i;
	i=1;
	for( ; i<k; i++)
	{
		n=n/10;
	}
	return n%10;
}

int main()
{
	int i,n,k;
	i=1;
	for( ; i<=5; i++)
	{
		cin>>n>>k;
		cout<<digit(n,k)<<endl;
	}
	
	return 0;
} 
