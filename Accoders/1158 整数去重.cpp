//1158 整数去重
#include<iostream>
using namespace std;
int a[20001];

int main()
{
	int n,i,j,m,k=0;
	cin>>n;	
	for(i=0;i<n;i++)
	{	
		cin>>m;
		for(j=0;j<=i;j++)
		{
			if(m==a[j])
				break;
		}
		if(j==i+1)
			a[k++]=m;
	}
	for(i=0;i<k;i++)
		cout<<a[i]<<" ";
		
		
	return 0;
}
 
