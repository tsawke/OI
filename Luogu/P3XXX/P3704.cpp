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

#define LIM (1100000)
#define MOD (ll)(1e9 + 7)

template < typename T = int >
inline T read(void);

int N, M;
ll ans(0);
ll mu[LIM + 100], smu[LIM + 100];
ll F[LIM + 100], invF[LIM + 100];
ll G[LIM + 100], mulG[LIM + 100], invmulG[LIM + 100];
bitset < LIM + 100 > notPrime;
basic_string < int > Prime;

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

int main(){mu[1] = 1;
    for(int i = 2; i <= LIM; ++i){
        if(!notPrime[i])Prime += i, mu[i] = -1;
        for(auto p : Prime){
            if((ll)i * p > LIM)break;
            mu[i * p] = i % p == 0 ? 0 : mu[i] * mu[p];
            notPrime[i * p] = true;
            if(i % p == 0)break;
        }
    }
    F[0] = 0, F[1] = 1;
    for(int i = 2; i <= LIM; ++i)F[i] = (F[i - 1] + F[i - 2]) % MOD;
    for(int i = 1; i <= LIM; ++i)invF[i] = qpow(F[i], MOD - 2);
    for(int i = 0; i <= LIM; ++i)G[i] = 1;
    for(int i = 1; i <= LIM; ++i)
        for(int j = i; j <= LIM; j += i)
            (G[j] *= mu[j / i] == 1 ? F[i] : (mu[j / i] == 0 ? 1 : invF[i])) %= MOD;
    mulG[0] = invmulG[0] = 1;
    for(int i = 1; i <= LIM; ++i)mulG[i] = mulG[i - 1] * G[i] % MOD, invmulG[i] = qpow(mulG[i], MOD - 2);
    int T = read();
    while(T--){
        ans = 1;
        N = read(), M = read();
        int lim = min(N, M);
        int l = 1;
        while(l <= lim){
            int r = min(N / (N / l), M / (M / l));
            (ans *= qpow(mulG[r] * invmulG[l - 1] % MOD, (ll)(N / l) * (M / l))) %= MOD;
            l = r + 1;
        }printf("%lld\n", ans);
    }
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