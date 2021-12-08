#include <cstdio>
#include <algorithm>
using namespace std;
int N,m; int pri[110],imp[110];
int dp[51][31000];
int main(){scanf("%d%d",&N,&m);
	for(int i=1; i<=m; i++)scanf("%d%d",pri+i,imp+i);
	for(int i=1; i<=m; i++){
		for(int j=1; j<=N; j++){
			if(j<pri[i])dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-pri[i]]+imp[i]*pri[i]);
		}
	}printf("%d\n",dp[m][N]);

	return 0;
}

