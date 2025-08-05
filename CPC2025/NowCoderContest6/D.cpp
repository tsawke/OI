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



template<typename T = int>
inline T read(void);

const int LIM = 501000;
const ll MOD = 998244353ll;
ll N, M;
ll fact[510000], invf[510000];

int main(){
    auto qpow = [](ll a, ll b)->ll{
        ll ret(1), mul(a);
        while(b){
            if(b & 1)ret = ret * mul % MOD;
            b >>= 1, mul = mul * mul % MOD;
        }return ret;
    };
    fact[0] = 1;
    for(int i = 1; i < LIM; ++i)fact[i] = fact[i - 1] * i % MOD;
    invf[LIM - 1] = qpow(fact[LIM - 1], MOD - 2);
    for(int i = LIM - 1 - 1; i >= 0; --i)invf[i] = invf[i + 1] * (i + 1) % MOD;

    N = read(), M = read();
    ll K = N * (N - 1) % MOD;
    ll ans(1);
    for(ll i = K + 1; i <= K + M; ++i)ans = (ans * i) % MOD;
    printf("%lld\n", (ans * invf[M]) % MOD);

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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