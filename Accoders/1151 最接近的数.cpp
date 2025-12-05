//1151 最接近的数(错) 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
//此为互换的函数 
using namespace std;
int a[1004];


int main()
{
	int i,j,n,k,k1,k2,sum;
	
	cin>>n;
	for(i=1; i<=n; i++)
	{
		cin>>a[i];
	} 
	
	for(int i=1; i<=n-1; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			if(a[j]<a[i])
		swap(a[j],a[i]);
		}
	}
	//上为排序代码
	
	int p=2147483647;
	for(int i=n; i>=2; i--)
	{
		k+a[i]-a[i-1];
		if(k<=p)
		{
			p=k;
			k1=a[i-1];
			k2=a[i];
		}
	} 
	cout<<k1<<k2;
	return 0;
} 
