//1016 三角形面积 
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main() 
{ 
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	const double S=((a+b+c)/2);
	printf("%0.3lf",sqrt(S*(S-a)*(S-b)*(S-c)));
	return 0;
} 
