//1025 ³æ×Ó³ÔÆ»¹û 
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int n,x,y;
	scanf("%d %d %d",&n,&x,&y);
if((y%x)>0)
{
if((n-y/x-1)<0)
{
	cout<<"0";
}
else
{
	printf("%d",n-y/x-1);
}
}
else
{
if((n-y/x)<0)
{
	cout<<"0";
}
else
{
	printf("%d",n-y/x);
}
}
    return 0;
}
