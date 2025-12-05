#pragma warning(disable:4996)
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
using namespace std;
int n, W;
int weiAll(0);
int wei[300], pri[300];
int dp[11000][1100];
double ans = -1 * 1.0000;
int main() {
	scanf("%d%d", &n, &W);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", wei + i, pri + i);
	for (int i = 1; i <= n; ++i)weiAll += wei[i];
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= weiAll; ++j) {
			if (j < wei[i])dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wei[i]] + pri[i]);
		}
	}
	for (int i = W; i <= weiAll; ++i) {
		int nowPri = dp[n][i];
		int nowWei = i;
		//		printf("\nNo.%d  Pri = %d, Wei = %d\n", i, nowPri, nowWei);
		double value = nowPri * 1.0000 / nowWei * 1.0000;
		//		if (value >= ans)printf("\nFind Ans! No.%d\n", i);
		ans = max(ans, value);
	}
	ans *= 1000;
	int finalAns = int(ans);
	printf("%d\n", finalAns);
}