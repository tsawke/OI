#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[51000],sum[51000]={0},maxp,maxx=-1;
bool cmp(int x,int y){return x<y;}
int main(){scanf("%d",&n); for(int i=1; i<=n; i++)scanf("%d",a+i);
	for(int i=1; i<=n; i++){
		sum[a[i]]++;
		if(sum[a[i]]>maxx){maxx=sum[a[i]]; maxp=a[i];}
	}printf("%d\n%d\n",maxp,maxx);
	return 0;
}
