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

#define DFT (true)
#define IDFT (false)
#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

int S, L, N, M, K;
int pos[810000];
ll g(3), inv_g;

ll qpow(ll a, ll b){
    if(b < 0)return 0;
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

class Polynomial{
private:
public:
    int len;
    ll poly[810000];
    Polynomial(void){
        len = 0;
        memset(poly, 0, sizeof poly);
    }
    void Reverse(void){
        for(int i = 0; i < len; ++i)
            pos[i] = (pos[i >> 1] >> 1) | (i & 1 ? len >> 1 : 0);
        for(int i = 0; i < len; ++i)if(i < pos[i])swap(poly[i], poly[pos[i]]);
    }
    void NTT(bool pat){
        Reverse();
        for(int siz = 2; siz <= len; siz <<= 1){
            ll gn = qpow(pat ? g : inv_g, (MOD - 1) / siz);
            for(auto p = poly; p != poly + len; p += siz){
                int mid = siz >> 1; ll g(1);
                for(int i = 0; i < mid; ++i, (g *= gn) %= MOD){
                    auto tmp = g * p[i + mid] % MOD;
                    p[i + mid] = (p[i] - tmp + MOD) % MOD;
                    p[i] = (p[i] + tmp) % MOD;
                }
            }
        }
        if(!pat){
            ll inv_len = qpow(len, MOD - 2);
            for(int i = 0; i < len; ++i)(poly[i] *= inv_len) %= MOD;
        }
    }
    void Print(void){
        printf("Polynomial(len = %d): ", len);
        for(int i = 0; i < len; ++i)printf("%lld ", poly[i]);
        printf("\n");
    }
};

int fact[21000000], inv[21000000];
void Init(void){
    inv_g = qpow(g, MOD - 2);
    fact[0] = 1;
    for(int i = 1; i <= 20100000; ++i)fact[i] = (ll)fact[i - 1] * i % MOD;
    inv[20100000] = qpow(fact[20100000], MOD - 2);
    for(int i = 20099999; i >= 0; --i)inv[i] = (ll)inv[i + 1] * (i + 1) % MOD;
}
ll GetC(ll n, ll m){
    if(n < m || n < 0 || m < 0)return 0;
    return (ll)fact[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main(){
    Init();
    (void)read(), (void)read(), S = read(), L = read();
    Polynomial A, B;
    for(int i = 0; i <= L; ++i)
        A.poly[i] = (qpow(-1, i) * inv[i] % MOD + MOD) % MOD,
        B.poly[i] = qpow(i, L) * inv[i] % MOD;
    int base(1); while(base < L + 1 + L + 1 - 1)base <<= 1;
    A.len = B.len = base;
    A.NTT(DFT), B.NTT(DFT);
    for(int i = 0; i < A.len; ++i)A.poly[i] = A.poly[i] * B.poly[i] % MOD;
    A.NTT(IDFT);
    while(S--){
        N = read(), M = read(), K = read();
        ll ans(0);
        for(int i = 0; i <= L; ++i)
            (ans += A.poly[i] * fact[i] % MOD * GetC(M, i) % MOD * GetC(N - i, K - i) % MOD) %= MOD;
        printf("%lld\n", ans * inv[N] % MOD * fact[K] % MOD * fact[N - K] % MOD);
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