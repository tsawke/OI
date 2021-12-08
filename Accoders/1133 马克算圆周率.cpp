//1133 马克算圆周率
#include<iostream>
#include<cstdio>
using namespace std;
int main() 
{
	int i,n;
	double pi,t;
	scanf("%d",&n);
	i=0;
	t=1;
	pi=0;
for( ; i<=n; i++)
{
	pi=pi+t/(2*i+1);
	t=-t;
}
    printf("%.4lf\n",4*pi);
    return 0;
} 
