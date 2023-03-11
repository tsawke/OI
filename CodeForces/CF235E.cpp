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

#define LIM (2100)
#define MOD (ll)(1073741824)

template < typename T = int >
inline T read(void);

int A, B, C;
ll ans(0);
ll mu[LIM + 100], smu[LIM + 100];
ll G[LIM + 100][LIM + 100];
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
    for(int x = 1; x <= LIM; ++x)for(int i = 1; i <= LIM; ++i){
        if(__gcd(x, i) != 1)continue;
        for(int y = i; y <= LIM; y += i)(++G[x][y]) %= MOD;
    }
    for(int x = 1; x <= LIM; ++x)for(int y = 1; y <= LIM; ++y)(G[x][y] += G[x][y - 1]) %= MOD;
    A = read(), B = read(), C = read();
    for(int x = 1; x <= A; ++x)
        for(int d = 1; d <= min(B, C); ++d){
            if(__gcd(x, d) != 1)continue;
            (ans += A / x * mu[d] % MOD * G[x][B / d] % MOD * G[x][C / d] % MOD) %= MOD;
        }
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