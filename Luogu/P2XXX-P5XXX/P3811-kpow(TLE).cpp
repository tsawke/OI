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
ll MOD;
ll kpow(ll, ll);
ll N;
int main(){
	N = read<ll>(), MOD = read<ll>();
	for(int i = 1; i <= N; ++i){
		printf("%lld\n", kpow(i, MOD - 2));
	}

    return 0;
}

ll kpow(ll _a, ll _b){
	ll a(_a), b(_b);
	ll ret(1ll);
	while(b > 0){
		if(b & 1)ret = (ret * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
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