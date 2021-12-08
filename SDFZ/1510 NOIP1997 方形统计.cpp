#include <cstdio>
#include <algorithm>
using namespace std;
long long Z=0,C=0; int n,m;
int main(){scanf("%d%d",&n,&m);
	for(int i=n,j=m; ; ){
		if(i<1 || j<1)break;
		Z+=i*j;
		i--; j--;
	}
	C=(n+1)*(m+1)*n*m/4-Z;
	printf("%lld %lld\n",Z,C);
	return 0;
}
