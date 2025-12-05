#include <algorithm>
#include <cstdio>
long long func(int n){long long a[110]={0,1,2};
	if(n<=2)return a[n];
	for(int i=3; i<=n; i++)a[i]=a[i-1]+a[i-2]; return a[n];
}
int main(){int n;
	scanf("%d",&n); printf("%lld\n",func(n));
	return 0;
}

