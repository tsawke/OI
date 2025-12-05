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
ll kpow(ll, ll, ll);
int main(){
	ll a = read<ll>(), b = read<ll>(), mod = read<ll>();
    printf("%lld^%lld mod %lld=%lld\n", a, b, mod, kpow(a, b, mod));

    return 0;
}
ll kpow(ll _a, ll _b, ll MOD){
    ll ret(1);
    ll a(_a);
    ll b(_b);
    while(b > 0){
        if(b & 1) ret = (ret * a) % MOD;
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