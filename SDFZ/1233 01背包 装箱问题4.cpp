#include <cstdio>
#include <algorithm>
using namespace std;
int dp[110][21000]; int n,V; int v[110];
int main(){scanf("%d%d",&V,&n);
	for(int i=1; i<=n; i++)scanf("%d",v+i);
	for(int i=1; i<=n; i++)for(int j=1; j<=V; j++){
		if(j<v[i])dp[i][j]=dp[i-1][j];
		else dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+v[i]);
	}printf("%d\n",V-dp[n][V]);
	
	return 0;
}

