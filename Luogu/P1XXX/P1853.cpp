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
int Property, Years, N;
int investment[20], interest[20];
float maxInterestPercent(0.000);
int dp[110000000];
int main(){
	Property = read(), Years = read(), N = read();
    for(int i = 1; i <= N; ++i)
        investment[i] = read(),
        interest[i] = read();
        // maxInterestPercent = max(maxInterestPercent, int(ceil(interest[i] / investment[i])) + 1);
    maxInterestPercent = 1.100;
    int maxProbablyProperty = int(Property * float(pow((float)maxInterestPercent, (float)Years) + 1));
    // printf("%d\n", maxProbablyProperty);
    for(int i = 1; i <= N; ++i)
        for(int j = investment[i]; j <= maxProbablyProperty; ++j)
            dp[j] = max(dp[j], dp[j - investment[i]] + interest[i]);
    int nowProperty(Property);
    for(int i = 1; i <= Years; ++i)
        nowProperty += dp[nowProperty];
    printf("%d\n", nowProperty);
    // for(int i = 1; i <= maxProbablyProperty; ++i)printf("%d%c", dp[i], i == maxProbablyProperty ? '\n' : ' ');
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