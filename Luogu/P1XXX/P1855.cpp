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
int n, Money, Time;
int dp[210][210];
int main(){
    n = read(), Money = read(), Time = read();
    for(int i = 1; i <= n; ++i){
        int price = read(), costTime = read();
        for(int j = Money; j >= price; --j)
            for(int k = Time; k >= costTime; --k)
                dp[j][k] = max(dp[j][k], dp[j - price][k - costTime] + 1);
    }
    printf("%d\n", dp[Money][Time]);
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