#include <cstdio>
#include <algorithm>
using namespace std;
int n,TOT;
int aW[110],aP[110],bW[110],bP[110];
int dp[110][11000];
int main(){scanf("%d%d",&n,&TOT);
	for(int i=1; i<=n; i++)scanf("%d%d%d%d",aW+i,aP+i,bW+i,bP+i);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=TOT; j++){
			if(j<aW[i] && j<bW[i]){dp[i][j]=dp[i-1][j]; continue;}
			if(j>=aW[i])dp[i][j]=max(dp[i-1][j],dp[i-1][j-aW[i]]+aP[i]);
			if(j>=bW[i])dp[i][j]=max(dp[i][j],dp[i-1][j-bW[i]]+bP[i]);
		}
	}printf("%d\n",dp[n][TOT]);
	return 0;
}

