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

int N, M;

ll QueryOdd(ll l, ll r){
    if(!(l & 1))++l;
    if(!(r & 1))--r;
    if(l > r)return 0;
    return (((l + r) * (((r - l) >> 1) + 1)) >> 1) % MOD;
}
ll QueryEven(ll l, ll r){
    if(l & 1)++l;
    if(r & 1)--r;
    if(l > r)return 0;
    return (((l + r) * (((r - l) >> 1) + 1)) >> 1) % MOD;
}
ll CntOdd(ll l, ll r){
    if(!(l & 1))++l;
    if(!(r & 1))--r;
    if(l > r)return 0;
    return (((r - l) >> 1) + 1) % MOD;
}
ll CntEven(ll l, ll r){
    if(l & 1)++l;
    if(r & 1)--r;
    if(l > r)return 0;
    return (((r - l) >> 1) + 1) % MOD;
}

int main(){
    N = read(), M = read();
    int Q = read();
    while(Q--){
        ll ans(0);
        int a = read(), b = read(), c = read(), d = read();
        (ans += QueryOdd(c, d) * CntOdd(a, b) % MOD) %= MOD;
        (ans += ((QueryOdd(a, b) - CntOdd(a, b) + MOD) % MOD) * CntOdd(c, d) % MOD * M % MOD) %= MOD;
        (ans += QueryEven(c, d) * CntEven(a, b) % MOD) %= MOD;
        (ans += ((QueryEven(a, b) - CntEven(a, b) + MOD) % MOD) * CntEven(c, d) % MOD * M % MOD) %= MOD;
        printf("%lld\n", ans);
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