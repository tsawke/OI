//C++11 - Template
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <functional>
#include <unistd.h>

using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);

int N;
int a[1100][1100];
int dp[1100][1100];
int main(){
	N = read();
	for(int i = 1; i <= N; ++i)for(int j = 1; j <= i; ++j)a[i][j] = read();
	dp[1][1] = a[1][1];
	for(int i = 2; i <= N; ++i)
		for(int j = 1; j <= i; ++j)
			dp[i][j] = max(j != i ? dp[i - 1][j] : -1, j != 1 ? dp[i - 1][j - 1] : -1) + a[i][j];
	int ans(INT_MIN);
	for(int i = 1; i <= N; ++i)ans = max(ans, dp[N][i]);
	printf("%d\n", ans);

    return 0;
}

template <typename T = int>
inline T read(void)
{
	T ret(0);
	short flag(1);
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')flag = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		ret *= 10, ret += (c - '0');
		c = getchar();
    }
    ret *= flag;
	return ret;
}