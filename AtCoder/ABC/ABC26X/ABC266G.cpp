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

ll R, G, B, K;
ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
ll GetC(ll n, ll m){
    if(m > n)return 0;
    ll ret(1);
    for(int i = 1; i <= n; ++i)(ret *= i) %= MOD;
    ll div(1);
    for(int i = 1; i <= m; ++i)(div *= i) %= MOD;
    for(int i = 1; i <= n - m; ++i)(div *= i) %= MOD;
    return ret * qpow(div, MOD - 2) % MOD;
}

int main(){
    R = read(), G = read(), B = read(), K = read();
    printf("%lld\n", GetC(G + B, G) * GetC(G, K) % MOD * GetC(R + B, R - K) % MOD);
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