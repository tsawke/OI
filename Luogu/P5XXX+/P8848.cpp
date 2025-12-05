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

#define MOD (ll)(998244353)

template < typename T = int >
inline T read(void);

int N;
int cnt_1, cnt1;
int sum(0);

ll fact[11000], inv[11000];
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
    for(int i = 1; i <= N + 10; ++i)fact[i] = fact[i - 1] * i % MOD;
    inv[N + 10] = qpow(fact[N + 10], MOD - 2);
    for(int i = N + 9; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}
ll GetC(int n, int m){
    if(m > n)return 0;
    return fact[n] * inv[m] % MOD * inv[n - m] % MOD;
}
ll dp[2][11000];

int main(){
    N = read();
    Init();
    for(int i = 1; i <= N; ++i){
        int v = read(); sum += v;
        v == 1 ? ++cnt1 : ++cnt_1;
    }
    if(cnt_1 >= cnt1)printf("%lld\n", GetC(cnt_1 + 1, cnt1));
    else{
        dp[1][1] = dp[1][0] = 1;
        for(int i = 2; i <= N; ++i){
            for(int j = 0; j <= sum; ++j)
                (dp[i & 1][j] = (j - 1 >= 0 ? dp[(i - 1) & 1][j - 1] : 0) + dp[(i - 1) & 1][j + 1]) %= MOD;
        }
        printf("%lld\n", dp[N & 1][sum]);
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