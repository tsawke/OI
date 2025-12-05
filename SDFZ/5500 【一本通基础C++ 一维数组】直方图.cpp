#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[51000],sum[51000]={0};
bool cmp(int x,int y){return x<y;}
int main(){scanf("%d",&n); for(int i=1; i<=n; i++)scanf("%d",a+i);
	for(int i=1; i<=n; i++)sum[a[i]]++;
	sort(a+1,a+n+1,cmp);
	for(int i=0; i<=a[n]; i++)printf("%d\n",sum[i]);
	return 0;
}
