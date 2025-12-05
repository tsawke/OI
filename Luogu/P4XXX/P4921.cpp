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

#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

int N;
ll ans[1100];
ll fact[2100], inv[2100], pow2[2100];
// ll C(int n, int m){if(n < m || n < 0 || m < 0)return 0; return fact[n] * inv[m] % MOD * inv[n - m] % MOD;}
// ll F(int k){
//     return pow2[k] * C(N, k) % MOD * C(N, k) % MOD * fact[2 * N - 2 * k] % MOD;
// }

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
void Init(void){fact[0] = pow2[0] = 1;
    for(int i = 1; i <= 2010; ++i)fact[i] = fact[i - 1] * i % MOD;
    inv[2010] = qpow(fact[2010], MOD - 2);
    for(int i = 2009; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
    for(int i = 1; i <= 2010; ++i)pow2[i] = pow2[i - 1] * 2 % MOD;
}

int main(){
    // freopen("out.txt", "w", stdout);
    Init();
    for(int d = 0; d <= 1010; ++d)
        for(int j = 0, mul(1); j <= d; ++j, mul *= -1)
            (ans[d] += mul * pow2[j] % MOD * fact[2 * (d - j)] % MOD * inv[j] % MOD * inv[d - j] % MOD * inv[d - j] % MOD) %= MOD;
    int T = read();
    while(T--){
        int N = read();
        for(int i = 0; i <= N; ++i){
            int d = N - i;
            printf("%lld\n", ((ans[d] * pow2[i] % MOD * fact[N] % MOD * fact[N] % MOD * inv[i] % MOD) + MOD) % MOD);
        }
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