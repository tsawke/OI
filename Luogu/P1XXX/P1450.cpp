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

#define int ll

template <typename T = int>
inline T read(void);

int c[10], d[10];
int N, s;
int dp[110000];

signed main(){
    for(int i = 1; i <= 4; ++i)c[i] = read(); 
    N = read();
    dp[0] = 1;
	for(int i = 1; i <= 4; ++i)
        for(int j = c[i]; j <= 101000; ++j)
            dp[j] += dp[j - c[i]];
    // for(int i = 1; i <= 100; ++i){
    //     printf("%d%c", dp[i], i % 5 == 0 ? '\n' : ' ');
    // }
    for(int n = 1; n <= N; ++n){
        for(int i = 1; i <= 4; ++i)d[i] = read();
        s = read();
        int ans(dp[s]);
        int S0 = ( 1 << 4 ) - 1;
        for(int S = S0; S; S = (S - 1) & S0){
            int flag(1);
            int current(s);
            for(int i = 1; i <= 4; ++i){
                if(S & ( 1 << (i - 1) )){
                    flag == 1 ? flag = -1 : flag = 1;
                    current -= c[i] * (d[i] + 1);
                }
            }
            if(current < 0)continue;
            ans += flag * dp[current];
            // printf("Now S is %lld, flag is %lld, ans = %lld\n", S, flag, ans);
        }
        printf("%lld\n", ans);
    }

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