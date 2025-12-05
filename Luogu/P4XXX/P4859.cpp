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

#define MOD (ll)(1e9 + 9)

template < typename T = int >
inline T read(void);

int N, K;
int A[2100], B[2100];
int cnt[2100];
ll ans(0);
ll dp[2100][2100];
ll fact[2100], inv[2100];

ll C(int n, int m){if(n < m || n < 0 || m < 0)return 0; return fact[n] * inv[m] % MOD * inv[n - m] % MOD;}
ll F(int i){return fact[N - i] * dp[N][i] % MOD;}
ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
void Init(void){fact[0] = 1;
    for(int i = 1; i <= 2010; ++i)fact[i] = fact[i - 1] * i % MOD;
    inv[2010] = qpow(fact[2010], MOD - 2);
    for(int i = 2009; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}

int main(){
    Init();
    N = read(), K = read();
    if((N + K) & 1)printf("0\n"), exit(0);
    for(int i = 1; i <= N; ++i)A[i] = read();
    for(int i = 1; i <= N; ++i)B[i] = read();
    sort(A + 1, A + N + 1), sort(B + 1, B + N + 1);
    for(int a = 1, b = 0; a <= N; ++a){
        while(b + 1 <= N && B[b + 1] < A[a])++b;
        cnt[a] = b;
    }dp[0][0] = 1;
    for(int i = 1; i <= N; ++i)for(int j = 0; j <= i; ++j)
        dp[i][j] = (dp[i - 1][j] + (j ? (cnt[i] - (j - 1)) * dp[i - 1][j - 1] % MOD : 0)) % MOD;
    int lim = (N + K) >> 1;
    for(int j = lim, mul(1); j <= N; ++j, mul *= -1)
        (ans += mul * C(j, lim) % MOD * F(j) % MOD) %= MOD;
    printf("%lld\n", (ans + MOD) % MOD);
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