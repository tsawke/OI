#include <cstdio>
using namespace std;
int n,a[1100]; int ans=-1e9;
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++)scanf("%d",a+i);
	for(int i=1; i<=n; i++){ int t=a[i];
		for(int j=i+1; j<=n; j++){t+=a[j]; if(t>=ans)ans=t;}
	}printf("%d\n",ans);
	return 0;
}
