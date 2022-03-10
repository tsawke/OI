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

#define _int long long
// #define i_int _int

using namespace std;
// typedef unsigned _int u_int;
typedef unsigned long long unll;
typedef long long ll;
template <typename T = _int>
inline T read(void);
_int N, minScheme, qCoinMaxNum(0);
_int num[1100000], price[1100000];
_int dp[1100000];
void makeDP(_int, _int);
int main(){
	N = read(), minScheme = read();
    for(_int i = 1; i <= N; ++i)num[i] = read();
    for(_int i = 1; i <= N; ++i)price[i] = read(), qCoinMaxNum += num[i] * price[i];
    // pr_intf("COINMAX=%d\n", qCoinMaxNum);
    for(_int i = 0; i <= qCoinMaxNum; ++i)dp[i] = 1;
    for(_int i = 1; i <= N; ++i){
        // _int base(1);
        // _int times = num[i];
        // // while(times > 0){
        // //     if(base > times){
        // //         makeDP(price[i] * times, times);
        // //         break;
        // //     }
        // //     else{
        // //         times -= base;
        // //         makeDP(price[i] * base, base);
        // //         base <<= 1;
        // //     }
        // //     pr_intf("I=%d --- ", i);for(_int ii = 1; ii <= qCoinMaxNum; ++ii)pr_intf("%d%c", dp[ii], ii == qCoinMaxNum ? '\n' : ' ');
        // // }
        // makeDP(price[i] * times, times);
        for(_int j = qCoinMaxNum; j >= 1; --j){
            for(_int k = 1; k <= num[i]; ++k){
                if(j >= k * price[i])dp[j] = max(dp[j], dp[j - k * price[i]] * k);
            }
        }
        
    }
    // for(_int i = 1; i <= qCoinMaxNum; ++i)pr_intf("%d%c", dp[i], i == qCoinMaxNum ? '\n' : ' ');
    _int ans;
    for(ans = 1; dp[ans] < minScheme; ++ans);
    printf("%lld\n", ans);
    return 0;
}
void makeDP(_int price, _int times){
    printf("MAKING DP price=%d  times=%d\n", price, times);
    for(_int i = qCoinMaxNum; i >= price; --i){
        dp[i] = max(dp[i], dp[i - price] * times);
    }
}
template <typename T = _int>
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