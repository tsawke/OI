#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
double func(double x, double n);
double x, n;
int main(){scanf("%lf%lf", &x, &n);
	printf("%.2lf", func(x, n));
	return 0;
}
double func(double x, double n){
	if(n == 1) return x * 1.00 / (x + 1);
	return x * 1.00 / (n+func(x, n-1));
}
