//C++11 
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
int N, Weight;

int dp[510000];

int main(){
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    N = read(), Weight = read();
    for(int i = 1; i <= N; ++i){
        int weight = read(), price = read();
        for(int j = weight; j <= Weight + 5010; ++j)
            dp[j] = min(dp[j], dp[j - weight] + price);
    }
    int ans(INT_MAX);
    for(int i = Weight; i <= Weight + 5010; ++i)ans = min(ans, dp[i]);
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