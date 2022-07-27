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

#define int unll
#define MOD 1000000007

template <typename T = int>
inline T read(void);
unll f[20][10];

unll L, R;
int T;

unll kPow(unll, unll, unll);
unll DP(unll);
void Init(void);
signed main(){
    Init();
	// T = read();
    
    // for(int t = 1; t <= T; ++t){
    //     L = read(), R = read();
    //     printf("%llu\n", DP(R) - DP(L - 1));
    // }

    for(int i = 1; i <= 3; ++i){
        for(int j = 1; j <= 9; ++j){
            printf("[%llu][%llu]=%llu%c", i, j, f[i][j], j == 9 ? '\n' : ' ');
        }
    }

    return 0;
}
unll DP(unll N){
    if(!N)return 0;
    unll ret(0);
    vector<int>nums;
    while(N)nums.push_back(N % 10), N /= 10;
    unll len = (unll)nums.size();
    for(int i = 1; i <= len - 1; ++i){
        for(int j = 1; j <= 9; ++j){
            ret += f[i][j];
            ret %= MOD;
        }
    }
    int s(-1);
    for(vector<int>::iterator itea = nums.begin(); itea != nums.end(); ++itea){
        ++s;
        for(int i = itea == nums.begin() ? 1 : 0; i < *itea; ++i){
            ret += f[len - s][i];
            ret %= MOD;
            ret += i * f[len - s][i] % MOD;
            ret %= MOD;
        }
    }
    for(auto i : nums)ret += i;
    ret %= MOD;
    return ret;
}
// unll CreateNum(unll s, unll e, vector<int>nums){
//     bool allZero(true);
//     unll ret(0ull);
//     unll mul(1ull);
//     for(int i = e; i >= s; --i){
//         if(allZero && nums.at(i - 1) != 0)allZero = false;
//         ret += nums.at(i - 1) * mul, mul *= 10ull;
//     }
//     if(allZero) return 0ull;
//     return ret % MOD;
// }
void Init(void){
    for(int i = 0; i <= 9; ++i)f[1][i] = i;
    for(int i = 2; i <= 18; ++i){
        for(int j = 0; j <= 9; ++j){
            for(int r = 0; r <= 9; ++r){
                f[i][j] += f[i - 1][r] % MOD;
                f[i][j] %= MOD;
            }
            f[i][j] += j * kPow(10, i - 1, MOD) % MOD;
            f[i][j] %= MOD;
        }
    }
}
unll kPow(unll a, unll b, unll __MOD){
    unll ret(1ull);
    unll MUL(a);
    while(b){
        if(b & 1)ret = (ret * MUL) % MOD;
        MUL = (MUL * MUL) % MOD;
        b >>= 1;
    }
    return ret;
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