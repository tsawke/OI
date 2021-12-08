//1042 Æ½¾ù·Ö
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,i,test,max,min,x,all;
	cin>>n>>x; 
	all=x;
	max=x;
	min=x;
	i=2;
for( ; i<=n; i++)
{
	cin>>test;
	all=test+all;
if(test>max)
    max=test;
if(test<min)
    min=test;
}
    const double first=(all-max-min);
    const double second=(n-2);
    printf("%.2lf",first/second);
    return 0;
} 
