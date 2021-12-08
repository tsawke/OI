//1072 二位数组的最大值
#include<iostream>
using namespace std;
int main()
{
	int a[3][4],max,i,j,x,y;
	i=0;
	for( ; i<=2; i++)
	{
		j=0;
		for( ; j<=3; j++)
		{
			cin>>a[i][j];
		}
		
	}
	max=a[0][0];
	x=1;
	y=1;
	
	
	i=0;
	for( ; i<=2; i++)
	{
		j=0;
		for( ; j<=3; j++)
		{
			if(a[i][j]>max)
			{
				max=a[i][j];
				x=i+1;
				y=j+1;
			}
		}
		
	}
	cout<<max<<" "<<x<<" "<<y<<" ";
	
	return 0;
} 
