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

#define MOD (2333)

template < typename T = int >
inline T read(void);

int f[3100][3100];

int qpow(int a, int b){
    int ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
int fact[3100], inv[3100];
void Init(void){
    fact[0] = 1;
    for(int i = 1; i < MOD; ++i)fact[i] = fact[i - 1] * i % MOD;
    inv[MOD - 1] = qpow(fact[MOD - 1], MOD - 2);
    for(int i = MOD - 2; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}
int GetC(int n, int m){
    if(n < m)return 0;
    return fact[n] * inv[m] % MOD * inv[n - m] % MOD;
}
int Lucas(ll n, ll m){
    if(n < MOD && m < MOD)return GetC(n, m);
    return Lucas(n / MOD, m / MOD) * GetC(n % MOD, m % MOD) % MOD;
}
void InitF(void){
    for(int i = 0; i <= MOD - 1; ++i)f[i][0] = f[0][i] = 1;
    for(int i = 1; i <= MOD - 1; ++i)
        for(int j = 1; j <= MOD - 1; ++j)
            f[i][j] = (f[i][j - 1] + Lucas(i, j)) % MOD;
}
int F(ll n, ll k){
    if(n < 0 || k < 0)return 0;
    if(n < MOD && k < MOD)return f[n][k];
    return (f[n % MOD][MOD - 1] * F(n / MOD, k / MOD - 1) % MOD + Lucas(n / MOD, k / MOD) * f[n % MOD][k % MOD] % MOD) % MOD;
}

int main(){
    Init(), InitF();
    int T = read();
    while(T--){
        ll N = read < ll >(), K = read < ll >();
        printf("%d\n", F(N, K));
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