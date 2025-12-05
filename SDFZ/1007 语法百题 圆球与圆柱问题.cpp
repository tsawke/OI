#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
int main(){ double r,h;
	scanf("%lf%lf",&r,&h);
	printf("C1=%.2lf\nSa=%.2lf\nSb=%.2lf\nVa=%.2lf\nVb=%.2lf\n",2*r*3.14,r*r*3.14,r*r*4*3.14,r*r*r*3.14*4/3,r*r*3.14*h);
	return 0;
} 

