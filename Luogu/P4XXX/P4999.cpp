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
#define SUBMIT
using namespace std;
typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define int unll
#define MOD (unll)(1e9 + 7)

template <typename T = int>
inline T read(void);
unll f[20][10];

unll L, R;
int T;

unll kPow(unll, unll, unll);
unll DP(unll);
unll CreateNum(unll, unll, vector<int>);
void Init(void);

signed main(){
    Init();
#ifdef SUBMIT
	T = read();
    
    for(int t = 1; t <= T; ++t){
        L = read(), R = read();
        printf("%llu\n", DP(R) - DP(L - 1));
    }
#endif
#ifndef SUBMIT
    for(int i = 1; i <= 20; ++i)printf("[%llu]=%llu%c", i, DP(i), i % 5 == 0 ? '\n' : ' ');

    for(int i = 1; i <= 3; ++i){
        for(int j = 1; j <= 9; ++j){
            printf("[%llu][%llu]=%llu%c", i, j, f[i][j], j == 9 ? '\n' : ' ');
        }
    }
#endif
    return 0;
}
unll DP(unll N){
    if(!N)return 0;
    unll ret(0);
    vector<int>nums;
    while(N)nums.push_back(N % 10), N /= 10;
    reverse(nums.begin(), nums.end());
    unll len = (unll)nums.size();
    for(int i = 1; i <= len - 1; ++i){
        for(int j = 1; j <= 9; ++j){
            ret = (ret + f[i][j]) % MOD;
            ret %= MOD;
        }
    }
#ifndef SUBMIT
    printf("After 1~Len-1 ret = %llu\n", ret);
#endif
    int s(0);
    for(vector<int>::iterator itea = nums.begin(); itea != nums.end(); ++itea){
        ++s;
        for(int i = itea == nums.begin() ? 1 : 0; i < *itea; ++i){
            ret += f[len - s + 1][i];
            ret %= MOD;
        }
        ret =(ret + (*itea * CreateNum(s + 1, len, nums) + MOD) % MOD ) % MOD;
        ret %= MOD;
    #ifndef SUBMIT
        printf("nowRET = %llu\n", ret);
    #endif
    }
#ifndef SUBMIT
    printf("After Add ret = %llu\n", ret);
#endif
    for(auto i : nums)ret += i, ret %= MOD;
    ret %= MOD;
    return ret;
}
unll CreateNum(unll s, unll e, vector<int>nums){
    if(s > e)return 0ull;
    bool allZero(true);
    unll ret(0ull);
    unll mul(1ull);
    for(int i = e; i >= s; --i){
        if(allZero && nums.at(i - 1) != 0)allZero = false;
        ret += nums.at(i - 1) * mul, mul *= 10ull;
    }
    if(allZero) return 0ull;
    return (ret + MOD) % MOD;
}
void Init(void){
    for(int i = 0; i <= 9; ++i)f[1][i] = i;
    for(int i = 2; i <= 18; ++i){
        for(int j = 0; j <= 9; ++j){
            for(int r = 0; r <= 9; ++r){
                f[i][j] = (f[i][j] + (f[i - 1][r] + MOD) % MOD ) % MOD;
                f[i][j] %= MOD;
            }
            f[i][j] = (f[i][j] + (j * kPow(10, i - 1, MOD) + MOD) % MOD ) % MOD;
            f[i][j] %= MOD;
        }
    }
}
unll kPow(unll a, unll b, unll __MOD){
    unll ret(1ull);
    unll MUL(a);
    while(b){
        if(b & 1)ret = ((ret % MOD * MUL % MOD) + MOD) % MOD;
        MUL = ((MUL % MOD * MUL % MOD) + MOD) % MOD;
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