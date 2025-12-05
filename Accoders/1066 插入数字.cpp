//1066 ²åÈëÊı×Ö
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,x[10],j,k;
	i=0;
	for( ; i<=9; i++)
	{
		cin>>x[i];
	} 
	j=0;
	for( ; j<=8; j++)
	{
		if(x[9]>x[j] && x[9]<x[j+1])
		{
			cout<<x[j]<<endl;
			cout<<x[9]<<endl;
		}	
		else
		{
			cout<<x[j]<<endl;
		}
	}
	if(x[9]>x[8])
		cout<<x[9];
	return 0;
} 
