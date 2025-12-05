//2946 ÒÆ¶¯Â·Ïß 
#include <bits/stdc++.h>
using namespace std;

int dp[30][30];

int f(int n,int m)
{
	int mx = max(n, m);
	for(int i=1; i<=mx; i++){
		dp[1][i]=1;
		dp[i][1]=1;
	}
	for(int i=2; i<=n; i++){
		for(int j=2; j<=m; j++){
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		}
	}
	return dp[n][m];
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	printf("%d",f(n,m));
	return 0;
}
