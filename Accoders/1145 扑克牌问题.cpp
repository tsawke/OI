//1145 ÆË¿ËÅÆÎÊÌâ
#include<iostream>
using namespace std;

int main()
{
	int a[101],i,j;
	for(i=1;i<101;i++)
		a[i]=1;
	for(i=2;i<101;i++)
		for(j=i;j<101;j+=i)
		{
			a[j]=1-a[j];
		}
	
	for(i=1;i<101;i++)
	{
		if(a[i]==1)
			cout<<i<<" ";
	}
	return 0;
}

