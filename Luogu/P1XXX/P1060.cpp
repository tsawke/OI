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
int n, money;
int price[110], priority[110];
int dp[31000];
int main(){
	money = read(), n = read();
    for(int i = 1; i <= n; ++i)price[i] = read(), priority[i] = read();
    for(int i = 1; i <= n; ++i)
        for(int j = money; j >= 1; --j)
            if(j >= price[i])dp[j] = max(dp[j], dp[j - price[i]] + price[i] * priority[i]);
    printf("%d\n", dp[money]);
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