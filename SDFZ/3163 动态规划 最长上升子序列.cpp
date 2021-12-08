#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[5100]; int a[5100]; int n; int maxx=0;
int main(){scanf("%d",&n);
	for(int i=1; i<=n; i++){scanf("%d",a+i);dp[i]=true;}
	for(int i=2; i<=n; i++){
		for(int j=1; j<=i; j++)
			if(a[i]>a[j])dp[i]=max(dp[i],dp[j]+1);
		maxx=max(maxx,dp[i]);
	}printf("%d\n",maxx);
	return 0;
}

