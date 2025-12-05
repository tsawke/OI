#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define MOD (998244353)

template<typename T = int>
inline T read(void);

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

ll inv(ll a){
    return qpow(a, MOD - 2);
}
ll ans(0);

int main(){
    int N = read();
    for(int m = 0; m <= min(N - 1, 30); ++m){
        ll lim = 1ll << (m + 1);
        for(ll S = 0; S < lim; ++S){
            ll flag = __builtin_popcountll(S) & 1 ? -1 : 1;
            ll inv1 = inv(1ll << (m + 1));
            // ll val = ((1 - S * inv1 % MOD) % MOD + MOD) % MOD;
            ll val = (((((1ll << (m + 1)) % MOD - S) % MOD + MOD) % MOD * inv1 % MOD) % MOD + MOD) % MOD;
            val = qpow(val, N);
            ans += flag * val % MOD;
            ans %= MOD;
            ans = (ans + MOD) % MOD;
        }
    }printf("%lld\n", ans);

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(c != '-' && !isdigit(c))c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}