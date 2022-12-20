#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MAX_STATUS (20000)
#define MOD (ll)(998244353)
#define EXIST(x) (S & (1 << ((x) - 1)))

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[1100];
ROPNEW(ed);
Edge* head[20];

int N, M;
int deg[20];
ll G[MAX_STATUS], F[20][MAX_STATUS];
int cnte[MAX_STATUS];
ll fact[30];

int lowbit(int x){return x & -x;}
int CalCnt(int S, int T){return cnte[S | T] - cnte[S] - cnte[T];}
ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

int main(){fact[0] = 1;
    for(int i = 1; i <= 20; ++i)fact[i] = fact[i - 1] * i % MOD;
    N = read(), M = read();
    const int Smx = (1 << N) - 1;
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }
    for(int S = Smx; S; S = (S - 1) & Smx){
        int cnt(0);
        for(int p = 1; p <= N; ++p)
            for(auto i = head[p]; i; i = i->nxt)
                if(EXIST(p) && EXIST(SON))++cnt;
        cnt >>= 1;
        cnte[S] = cnt;
    }
    for(int S = 1; S <= Smx; ++S){
        if(__builtin_popcount(S) == 1){G[S] = 1; continue;}
        for(int T = (S - 1) & S; T; T = (T - 1) & S)
            if(T & lowbit(S))
                (G[S] += G[T] * G[S ^ T] % MOD * CalCnt(T, S ^ T) % MOD) %= MOD;
        (G[S] *= qpow(__builtin_popcount(S) - 1, MOD - 2)) %= MOD;
    }
    for(int i = 0; i <= N - 1; ++i)
        for(int S = 0; S <= Smx; ++S){
            if(__builtin_popcount(S) == i + 1){F[i][S] = G[S]; continue;}
            for(int T = (S - 1) & S; T; T = (T - 1) & S)
                if(T & lowbit(S) && i - (__builtin_popcount(T) - 1) >= 0)
                    (F[i][S] += G[T] * F[i - (__builtin_popcount(T) - 1)][S ^ T]) %= MOD;
        }
    for(int i = 1; i <= N - 1; ++i)
        printf("%lld\n", F[i][Smx] * fact[i] % MOD * qpow(qpow(M, i), MOD - 2) % MOD);
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