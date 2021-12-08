#include <cstdio>
#include <algorithm>
using namespace std;
unsigned long long n,sum=0;
int main(){scanf("%lld",&n);
	for(int i=2; i<=n; i++)sum=(sum+3)%i;
	printf("%d\n",++sum);return 0;
}

