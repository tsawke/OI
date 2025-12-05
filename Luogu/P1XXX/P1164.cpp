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
typedef unsigned long long unll;
typedef long long ll;
template <typename T = int>
inline T read(void);
int Money, N;
int money[110];
int dp[1100];
int main(){
	N = read(), Money = read();
    for(int i = 1; i <= N; ++i)money[i] = read();
    for(int i = 1; i <= N; ++i)
        for(int j = Money; j >= 1; --j)
            if(j == money[i])++dp[j];
            else if(j > money[i])dp[j] += dp[j - money[i]];
    printf("%d\n", dp[Money]);
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