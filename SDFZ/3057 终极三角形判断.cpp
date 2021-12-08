#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
double a,b,c;
bool equ(double a,double b,double c){
	return a==b && a==c;
}
bool iso(double a,double b,double c){
	return a==b || b==c || a==c;
}
bool rig(double a,double b,double c){
	return sqrt(a*a+b*b)==c || sqrt(a*a+c*c)==b || sqrt(c*c+b*b)==a;
}
bool simple(double a,double b,double c){
	return a+b>c && b+c>a && a+c>b;
}
int main(){scanf("%lf%lf%lf",&a,&b,&c);
	if(!simple(a,b,c))printf("error\n");
	else if(equ(a,b,c))printf("equilateral triangle\n");
	else if(iso(a,b,c))printf("isoscelse triangle\n");
	else if(rig(a,b,c))printf("right-angled triangle\n");
	else printf("triangle\n");
	return 0;
}

