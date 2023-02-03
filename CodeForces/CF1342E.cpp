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

#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

ll N, K;
ll fact[210000], inv[210000];
ll C(int n, int m){if(n < m || n < 0 || m < 0)return 0; return fact[n] * inv[m] % MOD * inv[n - m] % MOD;}

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
void Init(void){fact[0] = 1;
    for(int i = 1; i <= 201000; ++i)fact[i] = fact[i - 1] * i % MOD;
    inv[201000] = qpow(fact[201000], MOD - 2);
    for(int i = 200999; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}
ll Sn(int m){
    ll ret(0);
    for(int i = 0; i <= m; ++i)(ret += ((m - i) & 1 ? -1 : 1) * qpow(i, N) % MOD * inv[i] % MOD * inv[m - i] % MOD) %= MOD;
    return (ret + MOD) % MOD;
}

int main(){
    Init();
    N = read(), K = read < ll >();
    if(K >= N)printf("0\n"), exit(0);
    if(!K)printf("%lld\n", fact[N]), exit(0);
    printf("%lld\n", 2ll * C(N, N - K) % MOD * fact[N - K] % MOD * Sn(N - K) % MOD);
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