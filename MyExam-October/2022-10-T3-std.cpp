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

#define MOD 1145141
#define MAXN 11000000

template<typename T = int>
inline T read(void);

int N, M;
ll fact[MAXN], inv[MAXN];
ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }
    return ret;
}
void Init(void){
    fact[0] = 1;
    for(int i = 1; i <= N; ++i)fact[i] = fact[i - 1] * i % MOD;
    inv[N] = qpow(fact[N], MOD - 2);
    for(int i = N - 1; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}
ll GetC(ll n, ll m){
    if(m > n)return 0;
    return fact[n] * inv[m] % MOD * inv[n - m] % MOD;
}
ll out_pts[MAXN];
bool changed[MAXN];
ll ans(0);
int main(){
    freopen("fxxk_triatomic_ring.in", "r", stdin);
    freopen("fxxk_triatomic_ring.out", "w", stdout);
    N = read(), M = read();
    Init();
    for(int i = 1; i <= N; ++i)out_pts[i] = N - i;
    ans = GetC(N, 3);
    for(int i = 1; i <= N; ++i)ans = (ans - GetC(out_pts[i], 2) + MOD) % MOD;
    printf("%lld\n", ans);
    while(M--){
        int s = read(), t = read();
        if(s > t)swap(s, t);
        ans = ((ans + GetC(out_pts[s], 2)) % MOD + GetC(out_pts[t], 2)) % MOD;
        --out_pts[s], ++out_pts[t];
        ans = ((ans - GetC(out_pts[s], 2) + MOD) % MOD - GetC(out_pts[t], 2) + MOD) % MOD;
        printf("%lld\n", ans);
    }
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