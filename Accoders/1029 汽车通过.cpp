//1029 Æû³µÍ¨¹ý
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double x1,y1,x2,y2,L;
	scanf("%lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&L);
	const double A=x1-y1;
	const double B=y1-x1;
	const double C=x2-y2;
	const double D=y2-x2;
	if(A>=L || B>=L)
	{
		printf("%s","yes");
	}
	else
	{
		if(C>=L || D>=L)
		{
			printf("%s","yes");
		}
		else
		{
			printf("%s","no");
		}
	} 
    return 0;
} 
