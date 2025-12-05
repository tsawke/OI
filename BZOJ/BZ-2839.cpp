#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (ll)(1e9 + 7)

template < typename T = int >
inline T read(void);

ll qpow(ll a, ll b, ll mod = MOD){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % mod;
        b >>= 1;
        mul = mul * mul % mod;
    }return ret;
}

int N, K;
ll ans(0);
ll fact[1100000], inv[1100000];

void Init(void){fact[0] = 1;
    for(int i = 1; i <= 1010000; ++i)fact[i] = fact[i - 1] * i % MOD;
    inv[1010000] = qpow(fact[1010000], MOD - 2);
    for(int i = 1009999; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}
ll C(int n, int m){if(n < m || n < 0 || m < 0)return 0; return fact[n] * inv[m] % MOD * inv[n - m] % MOD;}
ll F(ll i){return (qpow(2, qpow(2, N - i, MOD - 1)) - 1 + MOD) % MOD * C(N, i) % MOD;}

int main(){
    Init();
    N = read(), K = read();
    for(int i = K, mul(1); i <= N; ++i, mul *= -1)(ans += mul * C(i, K) * F(i) % MOD) %= MOD;
    printf("%lld\n", (ans + MOD) % MOD);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    int flag(1);
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