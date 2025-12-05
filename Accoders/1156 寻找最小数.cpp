//1156 Ñ°ÕÒ×îÐ¡Êý
#include<iostream>
using namespace std;

long long a[1000][1000];
int main()
{
	int n,m,i,j,min,x,y;
	
	cin>>n>>m;
	i=0;
	for( ; i<n; i++)
	{
		j=0;
		for( ; j<m; j++)
		{
			cin>>a[i][j];
		}
	}
	
	
	min=a[0][0];
	x=1;
	y=1;
	
	
	i=0;
	for( ; i<n; i++)
	{
		j=0;
		for( ; j<m; j++)
		{
			if(a[i][j]<min)
			{
				min=a[i][j];
				x=i+1;
				y=j+1;
			}
		}
		
	}
	cout<<min<<" "<<x<<" "<<y<<" ";
	
	return 0;
} 
