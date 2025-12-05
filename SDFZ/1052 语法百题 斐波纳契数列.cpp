#include <algorithm>
#include <cstdio>
using namespace std;
int n; int a[110]={0,1,1,2,3,5};
void func(int n){
	for(int i=6; i<=n; i++)a[i]=a[i-1]+a[i-2];
	for(int i=1; i<=n; i++)printf("%d ",a[i]);
}
int main(){scanf("%d",&n);
	func(n); puts(""); return 0;
}

