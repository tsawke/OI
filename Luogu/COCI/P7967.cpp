#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define MOD 1000000007//(int)(1e9 + 7)

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }
    return ret;
}
ll frac[11000], inv[11000];
void Init(int N){
    frac[0] = 1;
    for(int i = 1; i <= N; ++i)frac[i] = frac[i - 1] * i % MOD;
    inv[N] = qpow(frac[N], MOD - 2);
    for(int i = N - 1; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}
ll C(int n, int m){
    if(m > n)return 0;
    return frac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
template<typename T = int>
inline T read(void);

int N, L;
int r[110];
ll dp[55][55][11000];
int main(){
    N = read(), L = read();
    Init(10100);
    for(int i = 1; i <= N; ++i)r[i] = read();
    sort(r + 1, r + N + 1);
    dp[0][0][0] = 1;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= i; ++j)
            for(int k = 1; k <= L; ++k){
                dp[i][j][k] = dp[i - 1][j - 1][k - 1];
                if(k >= r[i])dp[i][j][k] += dp[i - 1][j][k - r[i]] * j % MOD * 2 % MOD;
                if(k >= r[i] * 2 - 1)dp[i][j][k] += dp[i - 1][j + 1][k - r[i] * 2 + 1] * (j + 1) % MOD * (j + 1 - 1) % MOD;
                dp[i][j][k] %= MOD;
            }
    ll ans(0);
    for(int i = 1; i <= L; ++i)ans += dp[N][1][i] * C(L - i + 1 + N - 1, N + 1 - 1) % MOD;
    printf("%lld\n", ans % MOD);
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