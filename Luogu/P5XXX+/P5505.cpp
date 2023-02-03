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

ll N, M;
ll fact[2100], inv[2100];
ll c[1100];
ll C(int n, int m){if(n < m || n < 0 || m < 0)return 0; return fact[n] * inv[m] % MOD * inv[n - m] % MOD;}
ll F(int x){
    ll ret(1);
    for(int i = 1; i <= M; ++i)(ret *= C(N - x - 1 + c[i], N - x - 1)) %= MOD;
    ll mul = C(N, x);
    return ret * mul % MOD;
}

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
void Init(void){fact[0] = 1;
    for(int i = 1; i <= 2010; ++i)fact[i] = fact[i - 1] * i % MOD;
    inv[2010] = qpow(fact[2010], MOD - 2);
    for(int i = 2009; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}

int main(){
    Init();
    N = read(), M = read();
    for(int i = 1; i <= M; ++i)c[i] = read();
    ll ans(0);
    for(int i = 0, mul(1); i <= N - 1; ++i, mul *= -1)(ans += mul * F(i)) %= MOD;
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