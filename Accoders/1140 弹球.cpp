//1140 µ¯Çò
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,i;
	double m,a;
	scanf("%lf %d",&m,&n);
	i=1;
	a=-m;
	for( ; i<=n; i++)
	{
		a=a+2*m;
		m=m/2;
	}
	printf("%.2lf %.2lf",m,a);
	return 0;
} 
