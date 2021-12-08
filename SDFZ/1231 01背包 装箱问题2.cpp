/*#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stdlib.h>*/
#include <bits/stdc++.h>
#define MIN -0x3f3f3f
using namespace std;
int dp[110][11000]; int n,m; int w[1100],v[1100];
int main(){scanf("%d%d",&n,&m); memset(dp,MIN,sizeof(dp));
	//for(int i=1; i<=101; i++)for(int j=1; j<=10100; j++)dp[i][j]=MIN;
	for(int i=1; i<=n; i++)scanf("%d",w+i);
	for(int i=1; i<=n; i++)scanf("%d",v+i);
	dp[0][0]=false;
	for(int i=1; i<=n; i++){dp[i][0]=false;
		for(int j=1; j<=m; j++){
			if(j<w[i])dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
		}
	}
	/*for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			printf("%d ",dp[i][j]);
		}puts("");
	}
	for(int i=1; i<=n; i++)printf("%d & %d\n",w[i],v[i]);*/
	if(dp[n][m]<0)printf("-1\n");else printf("%d\n",dp[n][m]);
	return 0;
}

