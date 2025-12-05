#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD 998244353

template<typename T = int>
inline T read(void);

int N, M, K;
int arr[110];
ll dp[110][40][40][20];
ll v[110];
ll fact[110], inv[110];

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
void Init(void){
    fact[0] = 1;
    for(int i = 1; i <= 101; ++i)fact[i] = fact[i - 1] * i % MOD;
    inv[101] = qpow(fact[101], MOD - 2);
    for(int i = 100; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}
ll GetC(ll n, ll m){
    if(n < m)return 0;
    return fact[n] * inv[m] % MOD * inv[n - m] % MOD;
}
ll ans(0);
int main(){
    N = read(), M = read(), K = read();
    Init();
    for(int i = 0; i <= M; ++i)v[i] = read();
    dp[0][0][0][0] = 1;
    for(int i = 0; i <= M; ++i)
        for(int j = 0; j <= N; ++j)
            for(int k = 0; k <= K; ++k)
                for(int l = 0; l <= j >> 1; ++l)
                    for(int t = 0; t <= N - j; ++t)
                        dp[i + 1][j + t][k + ((t + l) & 1)][(t + l) >> 1] =
                        (dp[i + 1][j + t][k + ((t + l) & 1)][(t + l) >> 1] +
                        qpow(v[i], t) * GetC(N - j, t) % MOD * dp[i][j][k][l] % MOD) % MOD;
    for(int k = 0; k <= K; ++k)
        for(int l = 0; l <= N >> 1; ++l)
            if(k + __builtin_popcount(l) <= K)
                ans = (ans + dp[M + 1][N][k][l]) % MOD;
    printf("%lld\n", ans);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template<typename T>
inline T read(void){
    T ret(0);
    short flag(1);
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