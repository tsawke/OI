#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int W[1100],P[1100];
int dp[110][11000];
int main(){scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)scanf("%d",W+i);
	for(int i=1; i<=n; i++)scanf("%d",P+i);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(j<W[i])dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-W[i]]+P[i]);
		}
	}printf("%d\n",dp[n][m]);

	return 0;
}

