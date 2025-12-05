#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define LIM (11000000)
#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

ll N, M;
ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

ll fact[LIM + 100], inv[LIM + 100];
ll ans(0);

int main(){
    fact[0] = 1;
    for(int i = 1; i <= LIM; ++i)fact[i] = fact[i - 1] * i % MOD;
    inv[LIM] = qpow(fact[LIM], MOD - 2);
    for(int i = LIM - 1; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
    auto C = [](int n, int m)->ll{
        if(n < m || n < 0 || m < 0)return 0;
        return fact[n] * inv[m] % MOD * inv[n - m] % MOD;
    };
    N = read(), M = read();
    for(ll k = 0; k <= N - 1; ++k)
        if((M - 2 * (N - k - 1) - k) >= 0)
            (ans += C(N - 1, k) * C(N + (M - 2 * (N - k - 1) - k) / 3, N) % MOD) %= MOD;
    --M;
    for(ll k = 0; k <= N - 1; ++k)
        if((M - 2 * (N - k - 1) - k) >= 0)
            (ans += C(N - 1, k) * C(N + (M - 2 * (N - k - 1) - k) / 3, N) % MOD) %= MOD;
    --M;
    for(ll k = 0; k <= N - 1; ++k)
        if((M - 2 * (N - k - 1) - k) >= 0)
            (ans += C(N - 1, k) * C(N + (M - 2 * (N - k - 1) - k) / 3, N) % MOD) %= MOD;
    printf("%lld\n", ans);
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