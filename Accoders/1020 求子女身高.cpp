//1020 求子女身高
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() 
{
	double m,n;
	int p;
	scanf("%lf %lf %d",&m,&n,&p);
if(p==1)
{
	printf("%0.2lf",(m+n)*1.087/2);
}
else
{
	printf("%0.2lf",(m*0.973+n)/2);
}
    return 0;
}
