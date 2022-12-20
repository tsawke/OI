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

#define MOD (ll)(998244353ll)
#define MAX_STATUS (150000)
#define EXIST(x) (S & (1 << ((x) - 1)))

template < typename T = int >
inline T read(void);

int N, M;
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[2100];
ROPNEW(ed);
Edge* head[20];
ll F[MAX_STATUS], G[MAX_STATUS];
ll pow2[500];
ll ans[20];

int main(){
    pow2[0] = 1;
    for(int i = 1; i <= 300; ++i)pow2[i] = pow2[i - 1] * 2 % MOD;
    N = read(), M = read();
    const int Smx = (1 << N) - 1;
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
    }F[0] = G[0] = 1;
    for(int S = Smx; S; S = (S - 1) & Smx){
        int cnt(0);
        for(int p = 1; p <= N; ++p)
            if(EXIST(p))
                for(auto i = head[p]; i; i = i->nxt)
                    if(EXIST(SON))++cnt;
        G[S] = pow2[cnt];
    }
    for(int S = 1; S <= Smx; ++S){
        for(int T = (S - 1) & S; T; T = (T - 1) & S)
            if(T & 1)
                (F[S] += F[T] * G[S ^ T] % MOD) %= MOD;
        F[S] = (G[S] - F[S] + MOD) % MOD;
    }
    for(int i = 2; i <= N; ++i)
        for(int S = Smx; S; S = (S - 1) & Smx)
            if(EXIST(i) && EXIST(1))(ans[i] += F[S] * G[S ^ Smx] % MOD) %= MOD;
    for(int i = 2; i <= N; ++i)printf("%lld\n", ans[i]);
    // for(int S = Smx; S; S = (S - 1) & Smx)
    //     cout << "G[" << bitset < 6 >(S) << "] = " << G[S] << ", F = " << F[S] << endl;
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