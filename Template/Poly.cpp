// #define _USE_MATH_DEFINES
// #include <bits/stdc++.h>

// #define PI M_PI
// #define E M_E

// using namespace std;

// mt19937 rnd(random_device{}());
// int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
// bool rnddd(int x){return rndd(1, 100) <= x;}

// typedef unsigned int uint;
// typedef unsigned long long unll;
// typedef long long ll;
// typedef long double ld;



// template < typename T = int >
// inline T read(void);

// const ll MOD = 998244353ll;
// ll g(3), inv_g;

// ll qpow(ll a, ll b, ll mod = MOD){
//     if(b < 0)return 0;
//     ll ret(1), mul(a);
//     while(b){
//         if(b & 1)ret = ret * mul % mod;
//         b >>= 1;
//         mul = mul * mul % mod;
//     }return ret;
// }

// enum Pattern{DFT, IDFT};

// class Polynomial{
// private:
//     static vector < int > pos;
// public:
//     int len;
//     vector < ll > poly;
//     Polynomial(void){
//         this->len = 0;
//         this->poly.resize(0), this->poly.shrink_to_fit();
//     }
//     Polynomial(int len){
//         this->len = len;
//         this->poly.assign(len, 0);
//     }
//     void Reverse(void){
//         pos.resize(len);
//         if(len > 0)pos[0] = 0;
//         for(int i = 0; i < len; ++i)
//             pos[i] = (pos[i >> 1] >> 1) | (i & 1 ? len >> 1 : 0);
//         for(int i = 0; i < len; ++i)if(i < pos[i])swap(poly[i], poly[pos[i]]);
//     }
//     void NTT(Pattern pat){
//         Reverse();
//         for(int siz = 2; siz <= len; siz <<= 1){
//             ll gn = qpow(pat == DFT ? g : inv_g, (MOD - 1) / siz);
//             for(auto p = poly.begin(); p < next(poly.begin(), len); advance(p, siz)){
//                 int mid = siz >> 1; ll g(1);
//                 for(int i = 0; i < mid; ++i, (g *= gn) %= MOD){
//                     auto tmp = g * p[i + mid] % MOD;
//                     p[i + mid] = (p[i] - tmp + MOD) % MOD;
//                     p[i] = (p[i] + tmp) % MOD;
//                 }
//             }
//         }
//         if(pat == IDFT){
//             ll inv_len = qpow(len, MOD - 2);
//             for(int i = 0; i < len; ++i)(poly[i] *= inv_len) %= MOD;
//         }
//     }
//     void Resize(int len){
//         this->poly.resize(len), this->len = len;
//     }
//     void Derivate(void){
//         poly[0] = 0;
//         for(int i = 1; i < len; ++i)poly[i - 1] = i * poly[i] % MOD, poly[i] = 0;
//         Resize(len - 1);
//     }
//     void Integrate(void){
//         Resize(len + 1);
//         for(int i = (len - 1) - 1; i >= 0; --i)poly[i + 1] = poly[i] * qpow(i + 1, MOD - 2) % MOD, poly[i] = 0;
//     }
//     void Desc(void){
//         // printf("Polynomial(len = %d): ", len);
//         for(int i = 0; i < len; ++i)printf("%lld ", poly[i]);
//         printf("\n");
//     }
// }basic[13];

// vector < int > Polynomial::pos;

// Polynomial* Inverse(Polynomial* baseF, int len){
//     static Polynomial *H = basic, *G = basic + 1, *F = basic + 2;
//     if(len == 1)return G->Resize(1), G->poly[0] = qpow(baseF->poly[0], MOD - 2), G;
//     H = Inverse(baseF, (len + 1) >> 1);
//     int base(1); while(base < (len << 1))base <<= 1;
//     H->Resize(base), G->Resize(base), F->Resize(base);
//     for(int i = 0; i < len; ++i)F->poly[i] = baseF->poly[i];
//     H->NTT(DFT), F->NTT(DFT);
//     for(int i = 0; i < base; ++i)
//         G->poly[i] = (2 * H->poly[i] % MOD - H->poly[i] * H->poly[i] % MOD * F->poly[i] % MOD + MOD) % MOD;
//     G->NTT(IDFT), G->Resize(len);
//     return G;
// }
// Polynomial* Sqrt(Polynomial* baseF, int len){
//     static Polynomial *H = basic + 3, *G = basic + 4, *F = basic + 5;
//     if(len == 1){
//         G->Resize(1);
//         G->poly[0] = sqrt(baseF->poly[0]);
//         return G;
//     }
//     H = Sqrt(baseF, (len + 1) >> 1);
//     auto invH = Inverse(H, len);
//     int base(1); while(base < len * 2)base <<= 1;
//     H->Resize(base), invH->Resize(base), G->Resize(base), F->Resize(base);
//     for(int i = 0; i < len; ++i)F->poly[i] = baseF->poly[i];
//     H->NTT(DFT), F->NTT(DFT), invH->NTT(DFT);
//     for(int i = 0; i < base; ++i)G->poly[i] = (F->poly[i] * invH->poly[i] % MOD + H->poly[i]) % MOD * qpow(2, MOD - 2) % MOD;
//     G->NTT(IDFT), G->Resize(len);
//     return G;
// }
// Polynomial* Ln(Polynomial* baseF, int len){
//     static Polynomial *G = basic + 6, *F = basic + 7;
//     *F = *baseF;
//     auto invF = Inverse(F, len);
//     F->Derivate();
//     int base(1); while(base < F->len + invF->len)base <<= 1;
//     F->Resize(base), invF->Resize(base), G->Resize(base);
//     F->NTT(DFT), invF->NTT(DFT);
//     for(int i = 0; i < base; ++i)
//         G->poly[i] = F->poly[i] * invF->poly[i] % MOD;
//     G->NTT(IDFT), G->Resize(len - 1);
//     G->Integrate();
//     return G;
// }
// Polynomial* Exp(Polynomial* baseF, int len){
//     static Polynomial *H = basic + 8, *G = basic + 9, *F = basic + 10;
//     if(len == 1)return G->Resize(1), G->poly[0] = 1, G;
//     H = Exp(baseF, (len + 1) >> 1);
//     auto lnH = Ln(H, len);
//     int base(1); while(base < (len << 1))base <<= 1;
//     F->Resize(base), G->Resize(base), lnH->Resize(base), H->Resize(base);
//     for(int i = 0; i < len; ++i)F->poly[i] = baseF->poly[i];
//     F->NTT(DFT), H->NTT(DFT), lnH->NTT(DFT);
//     for(int i = 0; i < base; ++i)
//         G->poly[i] = (H->poly[i] * ((1 - lnH->poly[i] + MOD) % MOD) % MOD + F->poly[i] * H->poly[i] % MOD) % MOD;
//     G->NTT(IDFT), G->Resize(len);
//     return G;
// }
// Polynomial* Quickpow(Polynomial* baseF, int len, ll k1, ll k2, ll mx){
//     static Polynomial *F = basic + 11, *H = basic + 12;
//     *F = *baseF;
//     int offset(0);
//     // int offset = 0;
// while (offset < len && F->poly[offset] == 0) ++offset;
// if (offset == len) {            // 全零：返回 0 多项式
//     static Polynomial Z; Z.Resize(len);
//     fill(Z.poly.begin(), Z.poly.end(), 0LL);
//     return &Z;
// }
//     // while(F->poly[offset] == 0)++offset;
//     ll mul = qpow(F->poly[offset], k2), inv = qpow(F->poly[offset], MOD - 2);
//     for(int i = 0; i + offset < len; ++i)F->poly[i] = F->poly[i + offset];
//     for(int i = len - offset; i < len; ++i)F->poly[i] = 0;
//     for(int i = 0; i < len; ++i)(F->poly[i] *= inv) %= MOD;
//     *H = *Ln(F, len);
//     for(int i = 0; i < len; ++i)H->poly[i] = H->poly[i] * k1 % MOD;
//     auto elnF = Exp(H, len);
//     // for(int i = len; i >= offset * mx; --i)elnF->poly[i] = elnF->poly[i - offset * mx];
//     // for(int i = 0; i < min((ll)len, offset * mx); ++i)elnF->poly[i] = 0;
//     for (int i = len - 1; i >= (int)offset * mx; --i) elnF->poly[i] = elnF->poly[i - (int)offset * mx];
//     for (int i = 0; i < min((ll)len, offset * mx); ++i) elnF->poly[i] = 0;
//     for(auto i = 0; i < len; ++i)elnF->poly[i] = elnF->poly[i] * mul % MOD;
//     return elnF;
// }

// Polynomial A;

// tuple < ll, ll, ll > ReadIndex(void){
//     ll ret1(0), ret2(0), mx(0);
//     char c = getchar(); while(!isdigit(c))c = getchar();
//     while(isdigit(c)){
//         ((ret1 *= 10) += c - '0') %= MOD;
//         ((ret2 *= 10) += c - '0') %= MOD - 1;
//         mx = max({mx, ret1, ret2});
//         c = getchar();
//     }return {ret1, ret2, mx};
// }

// int main(){
//     inv_g = qpow(g, MOD - 2);
//     A.Resize(read());
//     auto [k1, k2, mx] = ReadIndex();
//     for(int i = 0; i < A.len; ++i)A.poly[i] = read();
//     Quickpow(&A, A.len, k1, k2, mx)->Desc();

//     // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
//     return 0;
// }

// template < typename T >
// inline T read(void){
//     T ret(0);
//     int flag(1);
//     char c = getchar();
//     while(c != '-' && !isdigit(c))c = getchar();
//     if(c == '-')flag = -1, c = getchar();
//     while(isdigit(c)){
//         ret *= 10;
//         ret += int(c - '0');
//         c = getchar();
//     }
//     ret *= flag;
//     return ret;
// }

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template < typename T = int >
inline T read(void);

const ll MOD = 998244353ll;
ll g(3), inv_g;

ll qpow(ll a, ll b, ll mod = MOD){
    if(b < 0)return 0;
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % mod;
        b >>= 1;
        mul = mul * mul % mod;
    }return ret;
}

enum Pattern{DFT, IDFT};

class Polynomial{
private:
    static vector < int > pos;
public:
    int len;
    vector < ll > poly;
    Polynomial(void){
        this->len = 0;
        this->poly.resize(0), this->poly.shrink_to_fit();
    }
    Polynomial(int len){
        this->len = len;
        this->poly.assign(len, 0);
    }
    void Reverse(void){
        pos.resize(len);
        if(len > 0)pos[0] = 0;
        for(int i = 0; i < len; ++i)
            pos[i] = (pos[i >> 1] >> 1) | (i & 1 ? len >> 1 : 0);
        for(int i = 0; i < len; ++i)if(i < pos[i])swap(poly[i], poly[pos[i]]);
    }
    void NTT(Pattern pat){
        Reverse();
        for(int siz = 2; siz <= len; siz <<= 1){
            ll gn = qpow(pat == DFT ? g : inv_g, (MOD - 1) / siz);
            for(auto p = poly.begin(); p < next(poly.begin(), len); advance(p, siz)){
                int mid = siz >> 1; ll g(1);
                for(int i = 0; i < mid; ++i, (g *= gn) %= MOD){
                    auto tmp = g * p[i + mid] % MOD;
                    p[i + mid] = (p[i] - tmp + MOD) % MOD;
                    p[i] = (p[i] + tmp) % MOD;
                }
            }
        }
        if(pat == IDFT){
            ll inv_len = qpow(len, MOD - 2);
            for(int i = 0; i < len; ++i)(poly[i] *= inv_len) %= MOD;
        }
    }
    void Resize(int len){
        this->poly.resize(len), this->len = len;
    }
    void Derivate(void){
        poly[0] = 0;
        for(int i = 1; i < len; ++i)poly[i - 1] = i * poly[i] % MOD, poly[i] = 0;
        Resize(len - 1);
    }
    void Integrate(void){
        Resize(len + 1);
        for(int i = (len - 1) - 1; i >= 0; --i)poly[i + 1] = poly[i] * qpow(i + 1, MOD - 2) % MOD, poly[i] = 0;
    }
    void Desc(void){
        // printf("Polynomial(len = %d): ", len);
        for(int i = 0; i < len; ++i)printf("%lld ", poly[i]);
        printf("\n");
    }
}basic[13];

vector < int > Polynomial::pos;

Polynomial* Inverse(Polynomial* baseF, int len){
    static Polynomial *H = basic, *G = basic + 1, *F = basic + 2;
    if(len == 1)return G->Resize(1), G->poly[0] = qpow(baseF->poly[0], MOD - 2), G;
    H = Inverse(baseF, (len + 1) >> 1);
    int base(1); while(base < (len << 1))base <<= 1;
    H->Resize(base), G->Resize(base), F->Resize(base);
    for(int i = 0; i < len; ++i)F->poly[i] = baseF->poly[i];
    H->NTT(DFT), F->NTT(DFT);
    for(int i = 0; i < base; ++i)
        G->poly[i] = (2 * H->poly[i] % MOD - H->poly[i] * H->poly[i] % MOD * F->poly[i] % MOD + MOD) % MOD;
    G->NTT(IDFT), G->Resize(len);
    return G;
}
Polynomial* Sqrt(Polynomial* baseF, int len){
    static Polynomial *H = basic + 3, *G = basic + 4, *F = basic + 5;
    if(len == 1){
        G->Resize(1);
        G->poly[0] = sqrt(baseF->poly[0]);
        return G;
    }
    H = Sqrt(baseF, (len + 1) >> 1);
    auto invH = Inverse(H, len);
    int base(1); while(base < len * 2)base <<= 1;
    H->Resize(base), invH->Resize(base), G->Resize(base), F->Resize(base);
    for(int i = 0; i < len; ++i)F->poly[i] = baseF->poly[i];
    H->NTT(DFT), F->NTT(DFT), invH->NTT(DFT);
    for(int i = 0; i < base; ++i)G->poly[i] = (F->poly[i] * invH->poly[i] % MOD + H->poly[i]) % MOD * qpow(2, MOD - 2) % MOD;
    G->NTT(IDFT), G->Resize(len);
    return G;
}
Polynomial* Ln(Polynomial* baseF, int len){
    static Polynomial *G = basic + 6, *F = basic + 7;
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
Polynomial* Exp(Polynomial* baseF, int len){
    static Polynomial *H = basic + 8, *G = basic + 9, *F = basic + 10;
    if(len == 1)return G->Resize(1), G->poly[0] = 1, G;
    H = Exp(baseF, (len + 1) >> 1);
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
Polynomial* Quickpow(Polynomial* baseF, int len, ll k1, ll k2, ll mx){
    static Polynomial *F = basic + 11, *H = basic + 12;
    *F = *baseF;
    int offset(0);
    
    while (offset < len && F->poly[offset] == 0) ++offset;
    if (offset == len) {            // 全零：返回 0 多项式
        static Polynomial Z; Z.Resize(len);
        fill(Z.poly.begin(), Z.poly.end(), 0LL);
        return &Z;
    }
    
    // Check if offset * k >= len (result would be 0)
    if ((ll)offset * k2 >= len) {
        static Polynomial Z; Z.Resize(len);
        fill(Z.poly.begin(), Z.poly.end(), 0LL);
        return &Z;
    }
    
    ll mul = qpow(F->poly[offset], k2), inv = qpow(F->poly[offset], MOD - 2);
    for(int i = 0; i + offset < len; ++i)F->poly[i] = F->poly[i + offset];
    for(int i = len - offset; i < len; ++i)F->poly[i] = 0;
    for(int i = 0; i < len; ++i)(F->poly[i] *= inv) %= MOD;
    *H = *Ln(F, len);
    for(int i = 0; i < len; ++i)H->poly[i] = H->poly[i] * k1 % MOD;
    auto elnF = Exp(H, len);
    
    // Shift back by offset * k2
    ll shift = (ll)offset * k2;
    for (int i = len - 1; i >= shift; --i) 
        elnF->poly[i] = elnF->poly[i - shift];
    for (int i = 0; i < shift && i < len; ++i) 
        elnF->poly[i] = 0;
    
    for(auto i = 0; i < len; ++i)elnF->poly[i] = elnF->poly[i] * mul % MOD;
    return elnF;
}

Polynomial A;

tuple < ll, ll, ll > ReadIndex(void){
    ll ret1(0), ret2(0), mx(0);
    char c = getchar(); while(!isdigit(c))c = getchar();
    while(isdigit(c)){
        ((ret1 *= 10) += c - '0') %= MOD;
        ((ret2 *= 10) += c - '0') %= MOD - 1;
        mx = max({mx, ret1, ret2});
        c = getchar();
    }return {ret1, ret2, mx};
}

int main(){
    inv_g = qpow(g, MOD - 2);
    A.Resize(read());
    auto [k1, k2, mx] = ReadIndex();
    for(int i = 0; i < A.len; ++i)A.poly[i] = read();
    Quickpow(&A, A.len, k1, k2, mx)->Desc();

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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