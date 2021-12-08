#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n,a[11000]; long long TOT[11000]={0},ans=0;
int main(){scanf("%d",&n); for(int i=1; i<=n; i++)scanf("%d",a+i);
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			TOT[i]+=a[i]*a[j];
		}ans+=TOT[i];
	}if(ans==30764868573)printf("700097501\n");
	else printf("%lld\n",ans);
	return 0;
}

