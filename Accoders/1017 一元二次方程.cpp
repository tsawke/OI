//1017 一元二次方程 
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	printf("%0.2lf",(-b+sqrt(b*b-4*a*c))/(2*a));
	cout<<" ";
	printf("%0.2lf",(-b-sqrt(b*b-4*a*c))/(2*a));
	return 0;
}
