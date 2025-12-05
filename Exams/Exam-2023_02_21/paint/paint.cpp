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

ll N, K;

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

ll dp[20][20][20];
ll ans(0);

int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    // printf("%lld\n", 17 * qpow(9, MOD - 2) % MOD);
    N = read(), K = read();
    if(K == 1){
        // ll v = (N + 2) >> 1;
        // printf("%lld\n", ((v * ((2 * N + 2) % MOD) % MOD - v * (v + 1) % MOD + (N - v) * ((2 * N + 2) % MOD) % MOD - (N + v + 1) % MOD * (N - v) % MOD) % MOD + MOD) % MOD * qpow(N, MOD - 2) % MOD * qpow(N, MOD - 2) % MOD);
        printf("%lld\n", (((N + 1) * (N + 1) % MOD * N % MOD - N * (N + 1) % MOD * ((2 * N + 1) % MOD) % MOD * qpow(3, MOD - 2) % MOD - N) % MOD + MOD) % MOD * qpow(N, MOD - 2) % MOD * qpow(N, MOD - 2) % MOD);
        exit(0);
    }
    ll base = qpow(N, MOD - 2) * qpow(N, MOD - 2) % MOD;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            (dp[1][min(i, j)][max(i, j)] += base) %= MOD;
    for(int i = 2; i <= K; ++i){
        for(int j = 1; j <= N; ++j){
            for(int k = 1; k <= N; ++k){
                int l = min(j, k), r = max(j, k);
                for(int L = 1; L <= N; ++L){
                    for(int R = L; R <= N; ++R){
                        int rl = min(l, L), rr = max(r, R);
                        (dp[i][rl][rr] += dp[i - 1][L][R] * base % MOD) %= MOD;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= N; ++i)
        for(int j = i; j <= N; ++j)
            (ans += dp[K][i][j] * (j - i + 1) % MOD) %= MOD;
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