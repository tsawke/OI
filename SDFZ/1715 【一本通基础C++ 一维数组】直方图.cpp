#include <cstdio>
#include <algorithm>
using namespace std;
int n; int a[11000]; int sum[11000] = {0}; int maxx(-1);
int main(){scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d", a+i);
		++sum[a[i]];
		maxx = max(maxx, a[i]);
	}
	for(int i=0; i<=maxx; i++)printf("%d\n",sum[i]);


	return 0;
}

