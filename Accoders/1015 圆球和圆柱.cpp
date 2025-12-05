#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
int main(){ double r,h;
	scanf("%lf %lf",&r,&h);
	printf("C1=%.1lf\nSa=%.1lf\nSb=%.1lf\nVa=%.1lf\nVb=%.1lf\n",2*r*3.14,r*r*3.14,r*r*4*3.14,r*r*r*3.14*4/3,r*r*3.14*h);
	return 0;
} 

