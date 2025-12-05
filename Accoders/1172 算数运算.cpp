//1172 ËãÊıÔËËã
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	double a,b;
	char c;
	scanf("%lf %lf %c",&a,&b,&c);
	if(c=='+')
		printf("%.2lf\n",a+b);
	if(c=='-')
		printf("%.2lf\n",a-b);
	if(c=='*')
		printf("%.2lf\n",a*b);
	if(c=='/')
		printf("%.2lf\n",a/b);
		
		
	return 0;
} 
