//1073 矩阵对角线之和
#include<iostream>
using namespace std;
int main()
{
	int a[3][3],sum1,sum2,i,j;
	i=0;
	for( ; i<=2; i++)
	{
		j=0;
		for( ; j<=2; j++)
		{
			cin>>a[i][j];
		}
	}
	sum1=a[0][0]+a[1][1]+a[2][2];
	sum2=a[0][2]+a[1][1]+a[2][0];
	cout<<sum1<<" "<<sum2;
	
	return 0;
} 
