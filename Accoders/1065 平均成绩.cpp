//1065 Æ½¾ù³É¼¨
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,all_x,all_num;
	all_x=0;
	all_num=0;
	cin>>n;
	int num[n],x[n];
	int i,j;
	double every;
	i=0;
	for( ; i<=n-1; i++)
	{
	    cin>>num[i];
		cin>>x[i];
		all_x=all_x+x[i];
		all_num++;
	}
	every=all_x/all_num;
	j=0;
	for( ; j<=n-1; j++)
	{
		if(x[j]>every)
		{
			cout<<num[j]<<endl;
		}
	}
	return 0;
}
