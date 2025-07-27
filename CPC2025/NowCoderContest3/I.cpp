#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define MOD (998244353ll)
#define DFT (true)
#define IDFT (false)

template<typename T = int>
inline T read(void);

ll g(3), inv_g;
int pos[1 << 20];

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

class Polynomial{
public:
    int len;
    ll poly[410000];
    Polynomial(){ len=0; memset(poly,0,sizeof poly); }

    void Reverse(void){
        for(int i = 0; i < len; ++i)
            pos[i] = (pos[i >> 1] >> 1) | (i & 1 ? len >> 1 : 0);
        for(int i = 0; i < len; ++i)if(i < pos[i])swap(poly[i], poly[pos[i]]);
    }
    void NTT(bool pat){
        Reverse();
        for(int siz = 2; siz <= len; siz <<= 1){
            ll gn = qpow(pat ? g : inv_g, (MOD - 1) / siz);
            for(auto p = poly; p < poly + len; p += siz){
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
    void Derivate(void){
        for(int i = 1; i < len; ++i)poly[i - 1] = i * poly[i] % MOD;
        poly[len - 1] = 0;
        len = max(1, len - 1);
    }
    void Integrate(void){
        for(int i = len - 1; i >= 0; --i)poly[i + 1] = poly[i] * qpow(i + 1, MOD - 2) % MOD;
        poly[0] = 0;
        ++len;
    }
    void Resize(int n){
        if(n < len)
            for(int i = n; i < len; ++i)poly[i] = 0;
        len = n;
    }
    void Print(void){
        printf("Polynomial(len = %d): ", len);
        for(int i = 0; i < len; ++i)printf("%lld ", poly[i]);
        printf("\n");
    }
}basic[8];

Polynomial*& Inverse(Polynomial* baseF, int len){
    static Polynomial *H = basic, *G = basic + 1, *F = basic + 2;
    if(len == 1)return G->Resize(1), G->poly[0] = qpow(baseF->poly[0], MOD - 2), G;
    swap(H, Inverse(baseF, (len + 1) >> 1));
    int base(1); while(base < (len << 1))base <<= 1;
    H->Resize(base), G->Resize(base), F->Resize(base);
    for(int i = 0; i < len; ++i)F->poly[i] = baseF->poly[i];
    H->NTT(DFT), F->NTT(DFT);
    for(int i = 0; i < base; ++i)
        G->poly[i] = (2 * H->poly[i] % MOD - H->poly[i] * H->poly[i] % MOD * F->poly[i] % MOD + MOD) % MOD;
    G->NTT(IDFT), G->Resize(len);
    return G;
}

Polynomial*& Ln(Polynomial* baseF, int len){
    static Polynomial *G = basic + 3, *F = basic + 4;
    *F = *baseF;
    auto invF = Inverse(F, len);
    F->Derivate();
    int base(1); while(base < F->len + invF->len)base <<= 1;
    F->Resize(base), invF->Resize(base), G->Resize(base);
    F->NTT(DFT), invF->NTT(DFT);
    for(int i = 0; i < base; ++i)
        G->poly[i] = F->poly[i] * invF->poly[i] % MOD;
    G->NTT(IDFT), G->Resize(len - 1);
    G->Integrate();
    return G;
}
Polynomial*& Exp(Polynomial* baseF, int len){
    static Polynomial *H = basic + 5, *G = basic + 6, *F = basic + 7;
    if(len == 1)return G->Resize(1), G->poly[0] = 1, G;
    swap(H, Exp(baseF, (len + 1) >> 1));
    auto lnH = Ln(H, len);
    int base(1); while(base < (len << 1))base <<= 1;
    F->Resize(base), G->Resize(base), lnH->Resize(base), H->Resize(base);
    for(int i = 0; i < len; ++i)F->poly[i] = baseF->poly[i];
    F->NTT(DFT), H->NTT(DFT), lnH->NTT(DFT);
    for(int i = 0; i < base; ++i)
        G->poly[i] = (H->poly[i] * ((1 - lnH->poly[i] + MOD) % MOD) % MOD + F->poly[i] * H->poly[i] % MOD) % MOD;
    G->NTT(IDFT), G->Resize(len);
    return G;
}

// Polynomial Mul(Polynomial &A, Polynomial &B, int mx) {
//     int len = A.len + B.len - 1;
//     int base(1);
//     while(base < len)base <<= 1;
//     Polynomial FA(base), FB(base);
//     for (int i = 0; i < A.len; ++i)FA.poly[i] = A.poly[i];
//     for (int i = 0; i < B.len; ++i)FB.poly[i] = B.poly[i];
//     FA.NTT(DFT), FB.NTT(DFT);
//     for (int i = 0; i < base; ++i) FA.poly[i] = FA.poly[i] * FB.poly[i] % MOD;
//     FA.NTT(IDFT);
//     FA.poly.resize(FA.len = min(mx + 1, len));
//     return FA;
// }

ll mx;
ll K;
ll fact[210000], invf[210000];

// Polynomial BuildPoly(int i){
//     int cur = mx / i;
//     Polynomial P(i * cur + 1);

//     // printf("i = %d, cur = %d, mx = %lld\n", i, cur, mx);
//     // P.len = i * cur + 1;
//     // P.poly.resize(i * cur + 1);
//     for(int m = 0; m <= cur; ++m){
//         P.poly[i * m] = qpow(invf[m], K + 1) * qpow(i, (K + 1) * (MOD - 2) % (MOD - 1) * m % (MOD - 1));
//     }
//     // P.Print();
//     return P;
// }

// Polynomial CDQ(int l, int r, int mx) {
//     if(l == r)return BuildPoly(l);
//     int mid = (l + r) >> 1;
//     Polynomial L = CDQ(l, mid, mx), R = CDQ(mid + 1, r, mx);
//     // for(int i = l; i <= r; ++i)pol[i].poly.clear(), pol[i].poly.shrink_to_fit(), pol[i].len = 0;
//     return Mul(L, R, mx);
// }

basic_string < int > querys;




int main() {
    inv_g = qpow(g, MOD - 2);
    
    int T = read();
    K = read < ll >();
    while(T--)querys += read < ll >();
    mx = *max_element(querys.begin(), querys.end());

    fact[0] = 1;
    for(int i = 1; i <= mx; ++i)fact[i] = fact[i - 1] * i % MOD;
    invf[mx] = qpow(fact[mx], MOD - 2);
    for(int i = mx - 1; i >= 0; --i)invf[i] = invf[i + 1] * (i + 1) % MOD;

    // vector < Polynomial > pol(mx + 1);

    // for(int i = 1; i <= mx; ++i){
    //     int cur = mx / i;
    //     pol[i].len = i * cur + 1;
    //     pol[i].poly.resize(i * cur + 1);
    //     for(int m = 0; m <= cur; ++m){
    //         pol[i].poly[i * m] = qpow(invf[m], K + 1) * qpow(i, (K + 1) * (MOD - 2) % (MOD - 1) * m % (MOD - 1));
    //         // qpow(qpow(qpow(i, K + 1), MOD - 2), m) % MOD;
    //         // printf("val = %lld\n", pol[i].poly[i * m]);
    //     }
    // }

    Polynomial Hpoly;
    Hpoly.Resize(mx + 1);
    Hpoly.poly[0] = 0;
    for(int i = 1; i <= mx; ++i){
        Polynomial pol;
        pol.Resize(mx + 1);
        int cur = mx / i;
        for(int m = 0; m <= cur; ++m){
            pol.poly[i * m] = qpow(invf[m], K+1) * qpow(i, (MOD - 2) * m % (MOD - 1) * (K + 1) % (MOD - 1)) % MOD;
        }
        pol.poly[0] = qpow(invf[0], K+1);
        Polynomial *lnf = Ln(&pol, mx + 1);
        for(int t = 1; t <= mx; ++t){
            Hpoly.poly[t] = (Hpoly.poly[t] + lnf->poly[t]) % MOD;
        }
    }

    Polynomial *res = Exp(&Hpoly, mx+1);

    // auto res = CDQ(1, mx, mx);
    // res.Print();


    for(auto q : querys){
        printf("%lld\n", res->poly[q] * qpow(fact[q], K + 1) % MOD);
    }

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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