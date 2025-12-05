#include <cstdio>
#include <algorithm>
using namespace std;
int a[110]={0,1,1}; int n;
void func(int n){for(int i=3; i<=n; i++)a[i]=a[i-1]+a[i-2];}
int main(){scanf("%d",&n); func(n);
	for(int i=1; i<=n; i++)printf("%d%c",a[i],i!=n?' ':'\n');
	return 0;
}
