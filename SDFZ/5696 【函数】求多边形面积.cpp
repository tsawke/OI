#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
double HL(double a,double b,double c){
	const double P=(a+b+c)/2;
	return sqrt(P*(P-a)*(P-b)*(P-c));
}
double S(){return HL(3,3,5)+HL(4.5,5,6.9)+HL(4.7,4.8,6.9)+HL(2.5,3.4,4.8);}
int main(){printf("%.2lf\n",S());return 0;}

