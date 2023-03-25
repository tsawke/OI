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

#define MOD (10007)

template < typename T = int >
inline T read(void);

int N, M, S;
int powS[6500000];
ll dp[110][110][110];
ll f[110][110][110]; //from j = i, pos = j, s = k
ll g[110][110][110]; //from i = i, pos = j, s = k

int main(){
    freopen("greedhead.in", "r", stdin);
    freopen("greedhead.out", "w", stdout);
    powS[0] = 1;
    dp[1][1][0] = 1;
    N = read(), M = read(), S = read();
    for(int i = 1; i <= N * M; ++i)powS[i] = powS[i - 1] * S % MOD;
    for(int i = 1; i < N; ++i){
        for(int j = 1; j < M; ++j){
            for(int k = 0; k <= S; ++k){
                for(int s = 0; s + k <= S; ++s){
                    (dp[i][j + 1][s + k] += dp[i][j][k] * (s + 1)) %= MOD;
                    // else (dp[i][j + 1][s + k] += dp[i][j][k])
                }
                for(int s = 0; s + k <= S; ++s){
                    (dp[i + 1][j][s + k] += dp[i][j][k] * s) %= MOD;
                }
            }
        }
    }
    for(int j = 1; j <= M; ++j){
        for(int k = 0; k <= S; ++k){
            f[j][j][k] = dp[N][j][k];
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int k = 0; k <= S; ++k){
            g[i][i][k] = dp[i][M][k];
        }
    }
    for(int j = 1; j <= M; ++j){
        for(int p = j; p <= M; ++p){
            for(int k = 0; k <= S; ++k){
                for(int s = 0; s + k <= S; ++s){
                    (f[j][p + 1][s + k] += f[j][p][k]) %= MOD;
                }
            }
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int p = i; p <= N; ++p){
            for(int k = 0; k <= S; ++k){
                for(int s = 0; s + k <= S; ++s){
                    (g[i][p + 1][s + k] += g[i][p][k]) %= MOD;
                }
            }
        }
    }
    // for(int i = 1; i <= N; ++i){
    //     for(int j = 1; j <= M; ++j){
    //         for(int s = 0; s <= S; ++s){
    //             printf("dp[%d][%d][%d] = %lld\n", i, j, s, dp[i][j][s]);
    //         }
    //     }
    // }
    ll ans(0);
    for(int j = 1; j < M; ++j)(ans += f[j][M][S] * powS[N * M - (N + M - 2 - (M - j)) * 2 - 2]) %= MOD;//, printf("j = %d, val = %lld\n", j, f[j][M][S]);
    for(int i = 1; i < N; ++i)(ans += g[i][N][S] * powS[N * M - (N + M - 2 - (N - i)) * 2 - 2]) %= MOD;//, printf("i = %d, val = %lld\n", i, g[i][N][S]);
    (ans += dp[N][M][S]) %= MOD;
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