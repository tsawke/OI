//1077 æÿ’Û≥À∑®
#include<iostream>
using namespace std;
int main()
{
	int m,n,p,i,j,k,k2,x=0,sum=0;
	cin>>m>>n;
	int a[m][n];
	i=0;
	for( ; i<m; i++)
	{
		j=0;
		for( ; j<n; j++)
		{
			cin>>a[i][j];
		}
	}
	
	cin>>n>>p;
	int b[n][p];
	
	i=0;
	for( ; i<n; i++)
	{
		j=0;
		for( ; j<p; j++)
		{
			cin>>b[i][j];
		}
	}
	
	
	cout<<m<<" "<<p<<endl;
	
	int c[m][p];
	
	i=0;
	for( ; i<m; i++)
	{
		j=0;
		for( ; j<p; j++)
		{
			
			k=0;
			for( ; k<n; k++)
			{
				k2=0;
				for( ; k2<n; k2++)
				{
					x=x+a[i][k]*b[j][k2];
				}
			}
			
			
			
			c[i][j]=x;
			x=0;
			
		}
	}
	
	
	
	i=0;
	for( ; i<m; i++)
	{
		j=0;
		for( ; j<p; j++)
		{
			cout<<c[i][j]/3<<" ";
			sum++;
			
			if(sum==p)
			{
				cout<<endl;
				sum=0;
			}
		}
	}
	
	return 0;
} 
