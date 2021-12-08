#include <cstdio>
#include <algorithm>
using namespace std;
double r1,r2;
int main(){scanf("%lf%lf",&r1,&r2);
	const double ans=1/(1/r1+1/r2);
	printf("%.2lf\n",ans);
	return 0;
}
