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

#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[6100];
ROPNEW;
Edge* head[3100];
int C[3100];
ll deg[3100];
ll invd[3100];
ll ans(0);
ll dp[3100][3100][3];

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

int N, M, K;

int main(){
    N = read(), M = read(), K = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
        ++deg[s], ++deg[t];
    }
    for(int i = 1; i <= N; ++i)C[i] = read();
    for(int i = 1; i <= N; ++i)invd[i] = qpow(deg[i], MOD - 2);
    dp[0][1][0] = 1;
    for(int k = 0; k < K; ++k){
        for(int p = 1; p <= N; ++p){
            for(auto i = head[p]; i; i = i->nxt){
                if(C[SON]){
                    (dp[k + 1][SON][0] += dp[k][p][0] * invd[p] % MOD) %= MOD;
                    (dp[k + 1][SON][1] += dp[k][p][1] * invd[p] % MOD) %= MOD;
                    (dp[k + 1][SON][2] += dp[k][p][2] * invd[p] % MOD) %= MOD;
                }else{
                    (dp[k + 1][SON][0] += dp[k][p][0] * invd[p] % MOD) %= MOD;
                    (dp[k + 1][SON][1] += (dp[k][p][1] + dp[k][p][0]) * invd[p] % MOD) %= MOD;
                    (dp[k + 1][SON][2] += (dp[k][p][2] + 2 * dp[k][p][1] + dp[k][p][0]) * invd[p] % MOD) %= MOD;
                }
            }
        }
    }
    // for(int k = 0; k < K; ++k)
    //     for(int p = 1; p <= N; ++p)
    //         for(int i = 0; i <= 2; ++i)
    //             printf("dp[%d][%d][%d] = %lld\n", k, p, i, dp[k][p][i]);
    for(int i = 0; i <= K; ++i)for(int p = 1; p <= N; ++p)if(C[p])(ans += dp[i][p][2]) %= MOD;
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