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
#define MOD (1004535809ll)

template < typename T = int >
inline T read(void);

int N;
ll g = 3, inv_g;
int pos[300000];

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
    ll poly[300000];
    Polynomial(void){
        len = 0;
        memset(poly, 0, sizeof poly);
    }
    void Reverse(void){
        memset(pos, 0, sizeof(int) * (len + 10));
        // memset(pos, 0, sizeof pos);
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
    auto operator %= (const int &mod){
        for(int i = mod; i <= len; ++i)poly[i] = 0;
        len = min(len, mod);
    }
    void Print(void){
        printf("Polynomial(len = %d): ", len);
        for(int i = 0; i < len; ++i)printf("%lld ", poly[i]);
        printf("\n");
    }
};
Polynomial F, H;
Polynomial CalInv(Polynomial &baseF, int len){
    // static Polynomial F;
    // Polynomial H;
    if(len == 1){
        // Polynomial ret;
        H.len = 1, H.poly[0] = qpow(baseF.poly[0], MOD - 2);
        return H;
    }
    H = CalInv(baseF, (len + 1) >> 1);
    F = baseF;
    int clen = H.len + H.len + F.len - 2;
    int base(1); while(base < clen)base <<= 1;
    H.len = F.len = base;
    H.NTT(DFT), F.NTT(DFT);
    for(int i = 0; i < H.len; ++i)H.poly[i] = (2 * H.poly[i] % MOD - F.poly[i] * H.poly[i] % MOD * H.poly[i] % MOD + MOD) % MOD;
    H.NTT(IDFT), F.NTT(IDFT);
    H %= len, F %= len;
    return H;
}

ll fact[310000], inv[310000];

void Init(void){
    inv_g = qpow(g, MOD - 2);
    fact[0] = 1;
    for(int i = 1; i <= 300000; ++i)fact[i] = fact[i - 1] * i % MOD;
    inv[300000] = qpow(fact[300000], MOD - 2);
    for(int i = 299999; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}
ll GetC2(ll n){
    if(n < 2)return 0;
    return n * (n - 1) / 2;
}

int main(){
    Init();
    N = read();
    Polynomial G, H;
    G.len = H.len = N + 1;
    for(int i = 0; i < G.len; ++i)G.poly[i] = qpow(2, GetC2(i) % (MOD - 1)) * inv[i] % MOD;
    for(int i = 1; i < H.len; ++i)H.poly[i] = qpow(2, GetC2(i) % (MOD - 1)) * inv[i - 1] % MOD;
    // G.Print(), H.Print();
    G = CalInv(G, G.len);
    // G.Print();
    int clen = G.len + H.len - 1;
    int base(1); while(base < clen)base <<= 1;
    G.len = H.len = base;
    G.NTT(DFT), H.NTT(DFT);
    for(int i = 0; i < H.len; ++i)H.poly[i] = H.poly[i] * G.poly[i] % MOD;
    H.NTT(IDFT);
    printf("%lld\n", H.poly[N] * fact[N - 1] % MOD);
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