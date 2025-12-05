//1074 ¾ØÕó×ª»»
#include<iostream>
using namespace std;
int main() 
{
	int a[3][3],i,j,sum;
	sum=0;
	i=0;
	for( ; i<=2; i++)
	{
		j=0;
		for( ; j<=2; j++)
		{
			cin>>a[i][j];
		}
	}
	
		i=0;
	for( ; i<=2; i++)
	{
		j=0;
		for( ; j<=2; j++)
		{
			cout<<a[j][i]<<" ";
			sum++;
			if(sum==3)
			{
				cout<<endl;
				sum=0;
			}
		}
	}
	return 0;
}
