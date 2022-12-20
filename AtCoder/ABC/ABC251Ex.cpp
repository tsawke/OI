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

#define MOD (7)
#define SPL (117649) //7^6

template < typename T = int >
inline T read(void);

int f[10][10];
int N, M, K;
int origin(0);
int sumf[210];
int lucas_div[SPL + 10], lucas_mod[SPL + 10];
struct Blk{int l, r; int val;} blk[210];

int qpow(int a, int b){
    int ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
int fact[10], inv[10];
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
int O1Lucas(ll m){
    return (lucas_div[m / SPL] * lucas_mod[m % SPL]) % MOD;
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
    N = read(), M = read(), K = read();
    for(int i = 0; i <= SPL; ++i)lucas_div[i] = Lucas((N - K) / SPL, i), lucas_mod[i] = Lucas((N - K) % SPL, i);
    int curl(1);
    for(int i = 1; i <= M; ++i)blk[i].val = read(), blk[i].l = curl, blk[i - 1].r = blk[i].l - 1, curl += read();
    blk[M].r = N; int lim = N - K + 1;
    for(int i = 1; i <= M; ++i)
        sumf[i] = (F(N - K, blk[i].r - 1) - F(N - K, blk[i].l - 2) + MOD) % MOD;
    for(int i = 1; i <= M; ++i){
        int l = blk[i].l, r = blk[i].r;
        if(l > lim)break;
        if(r <= lim)(origin += sumf[i] * blk[i].val % MOD) %= MOD;
        else (origin += (F(N - K, lim - 1) - F(N - K, l - 2) + MOD) % MOD * blk[i].val % MOD) %= MOD;
    }printf("%d ", origin);
    int cl = 1, cr = lim;
    for(int i = 2; i <= K; ++i){
        for(int m = 1; m <= M; ++m){
            int r = blk[m].r;
            if(cl <= r && r <= cr)
                origin = (origin - O1Lucas(r - cl) * blk[m].val % MOD + O1Lucas(r - cl) * blk[m + 1].val % MOD + MOD) % MOD;
        }++cl, ++cr;
        printf("%d ", origin);
    }printf("\n");
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