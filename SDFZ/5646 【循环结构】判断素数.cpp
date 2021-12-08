#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
long long n; bool flag=true;
int main(){scanf("%lld",&n); if(n==1 || n==-1)flag=false;
	for(int i=2; i<=sqrt(n); i++)
		if(n%i==0){flag=false; break;}
	if(flag)printf("prime\n"); else printf("not prime\n");
	return 0;
}
