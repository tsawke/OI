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

int N, M;
int X[51000], Y[51000];
int pos[610000];
ll g(3), inv_g;
ll ans(0), sumX(0), sumY(0);

ll qpow(ll a, ll b){
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
    ll poly[610000];
    Polynomial(void){
        len = 0;
        memset(poly, 0, sizeof poly);
    }
    void Reverse(void){
        memset(pos, 0, sizeof(ll) * (len + 10));
        for(int i = 0; i < len; ++i)
            pos[i] = (pos[i >> 1] >> 1) | (i & 1 ? len >> 1 : 0);
        for(int i = 0; i < len; ++i)if(i < pos[i])swap(poly[i], poly[pos[i]]);
    }
    void NTT(bool pat){
        Reverse();
        for(int siz = 2; siz <= len; siz <<= 1){
            ll gn = qpow(pat ? g : inv_g, (MOD - 1) / siz);
            for(auto p = poly; p != poly + len; p += siz){
                int mid(siz >> 1); ll g(1);
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
};

int main(){
    inv_g = qpow(g, MOD - 2);
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)X[i] = read(), ans += X[i] * X[i], sumX += 2 * X[i];
    for(int i = 1; i <= N; ++i)Y[N - i + 1] = read(), ans += Y[N - i + 1] * Y[N - i + 1], sumY += 2 * Y[N - i + 1];
    Polynomial A, B;
    for(int i = 1; i <= N; ++i)A.poly[i] = A.poly[i + N] = X[i], B.poly[i] = Y[i];
    A.len = N * 2 + 1, B.len = N + 1;
    int clen = A.len + B.len - 1, base(1);
    while(base < clen)base <<= 1;
    A.len = B.len = base;
    A.NTT(DFT), B.NTT(DFT);
    for(int i = 0; i < A.len; ++i)A.poly[i] = A.poly[i] * B.poly[i] % MOD;
    A.NTT(IDFT);
    ll mx(-1);
    for(int i = 0; i < A.len; ++i)mx = max(mx, A.poly[N + i]);
    ans -= 2 * mx;
    ll mn(LONG_LONG_MAX);
    for(ll c = -100; c <= 100; ++c)
        mn = min(mn, N * c * c + c * sumX - c * sumY);
    ans += mn;
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