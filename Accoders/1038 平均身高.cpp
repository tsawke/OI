//1038 平均身高 
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,i;
	double x,y;
	scanf("%d",&n);
	i=1;
for( ; i<=n; i++)
{
	scanf("%lf",&x);
	y=y+x;
}
    printf("%0.1lf",y/n);
    return 0;
}
