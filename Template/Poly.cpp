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

auto qpow = [](ll a, ll b, ll mod = MOD)->ll{
    if(b < 0)return 0;
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % mod;
        b >>= 1;
        mul = mul * mul % mod;
    }return ret;
};

const ll g = 3;
const ll invg = qpow(g, MOD - 2);
const ll inv2 = qpow(2, MOD - 2);
vector < int > pos;

enum Pattern{DFT, IDFT};

class Polynomial{
private:
public:
    vector < ll > poly;
    Polynomial(void){this->poly.resize(0);}
    Polynomial(int len){this->poly.assign(len, 0);}
    void Reverse(void){
        int len = poly.size();
        pos.resize(len);
        if(len > 0)pos[0] = 0;
        for(int i = 1; i < len; ++i)
            pos[i] = (pos[i >> 1] >> 1) | (i & 1 ? len >> 1 : 0);
        for(int i = 0; i < len; ++i)if(i < pos[i])swap(poly[i], poly[pos[i]]);
    }
    void NTT(Pattern pat){
        int len = poly.size();
        Reverse();
        for(int siz = 2; siz <= len; siz <<= 1){
            ll gn = qpow(pat == DFT ? g : invg, (MOD - 1) / siz);
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
        this->poly.resize(len, 0);
    }
    void Derivate(void){
        int len = poly.size();
        if(len == 0)return;
        poly[0] = 0;
        for(int i = 1; i < len; ++i)poly[i - 1] = i * poly[i] % MOD, poly[i] = 0;
        Resize(len - 1);
    }
    void Integrate(void){
        int len = poly.size();
        if(len == 0)return;
        Resize(len + 1);
        for(int i = len - 1; i >= 0; --i)poly[i + 1] = poly[i] * qpow(i + 1, MOD - 2) % MOD, poly[i] = 0;
    }
    auto Desc(void){
        int len = poly.size();
        // printf("Polynomial(len = %d): ", len);
        for(int i = 0; i < len; ++i)printf("%lld%c", poly[i], i == len - 1 ? '\n' : ' ');
        return this;
    }
};


auto Multiply = [](Polynomial* baseA, Polynomial* baseB)->Polynomial*{
    auto A = new Polynomial(*baseA), B = new Polynomial(*baseB);
    int len = A->poly.size() + B->poly.size() - 1;
    int base(1); while(base < (len << 1))base <<= 1;
    Polynomial* ret = new Polynomial(base);
    A->Resize(base), B->Resize(base);
    A->NTT(DFT), B->NTT(DFT);
    for(int i = 0; i < base; ++i)
        ret->poly[i] = (A->poly[i] * B->poly[i] % MOD);
    ret->NTT(IDFT);
    ret->Resize(len);
    delete A; delete B;
    return ret;
};

auto Inverse = [](auto&& self, Polynomial* baseF, int len)->Polynomial*{
    if(len == 1){
        Polynomial *G = new Polynomial(1);
        G->poly[0] = qpow(baseF->poly[0], MOD - 2);
        return G;
    }
    auto *H = self(self, baseF, (len + 1) >> 1);
    int base(1); while(base < (len << 1))base <<= 1;
    H->Resize(base);
    Polynomial *G = new Polynomial(base), *F = new Polynomial(base);
    for(int i = 0; i < min(len, (int)baseF->poly.size()); ++i)F->poly[i] = baseF->poly[i];
    H->NTT(DFT), F->NTT(DFT);
    for(int i = 0; i < base; ++i)
        G->poly[i] = (2 * H->poly[i] % MOD - H->poly[i] * H->poly[i] % MOD * F->poly[i] % MOD + MOD) % MOD;
    G->NTT(IDFT), G->Resize(len);
    delete H; delete F;
    return G;
};

//Require A[0] == 1
auto Sqrt = [](auto&& self, Polynomial* baseF, int len)->Polynomial*{
    if(len == 1){
        Polynomial *G = new Polynomial(1);
        G->poly[0] = sqrt(baseF->poly[0]);
        return G;
    }
    auto H = self(self, baseF, (len + 1) >> 1);
    auto invH = Inverse(Inverse, H, len);
    int base(1); while(base < (len << 1))base <<= 1;
    auto G = new Polynomial(base), F = new Polynomial(len);
    for(int i = 0; i < min(len, (int)baseF->poly.size()); ++i)F->poly[i] = baseF->poly[i];
    H->Resize(base), invH->Resize(base), F->Resize(base);
    H->NTT(DFT), F->NTT(DFT), invH->NTT(DFT);
    for(int i = 0; i < base; ++i)G->poly[i] = (F->poly[i] * invH->poly[i] % MOD + H->poly[i]) % MOD * inv2 % MOD;
    G->NTT(IDFT), G->Resize(len);
    delete H; delete invH; delete F;
    return G;
};
auto Ln = [](Polynomial* baseF, int len)->Polynomial*{
    auto F = new Polynomial(len);
    for(int i = 0; i < min(len, (int)baseF->poly.size()); ++i)
        F->poly[i] = baseF->poly[i];
    auto invF = Inverse(Inverse, F, len);
    F->Derivate();
    int clen = F->poly.size() + invF->poly.size() - 1;
    int base(1); while(base < clen)base <<= 1;
    Polynomial* G = new Polynomial(base);
    F->Resize(base), invF->Resize(base);
    F->NTT(DFT), invF->NTT(DFT);
    for(int i = 0; i < base; ++i)
        G->poly[i] = F->poly[i] * invF->poly[i] % MOD;
    G->NTT(IDFT), G->Resize(len - 1);
    G->Integrate();
    delete invF; delete F;
    return G;
};
auto Exp = [](auto&& self, Polynomial* baseF, int len)->Polynomial*{
    if(len == 1){
        Polynomial* G = new Polynomial(1);
        G->poly[0] = 1;
        return G;
    }
    auto H = self(self, baseF, (len + 1) >> 1);
    auto lnH = Ln(H, len);
    int base(1); while(base < (len << 1))base <<= 1;
    auto F = new Polynomial(len), G = new Polynomial(base);
    for(int i = 0; i < min(len, (int)baseF->poly.size()); ++i)F->poly[i] = baseF->poly[i];
    F->Resize(base), H->Resize(base), lnH->Resize(base);
    F->NTT(DFT), H->NTT(DFT), lnH->NTT(DFT);
    for(int i = 0; i < base; ++i)
        G->poly[i] = (H->poly[i] * ((1 - lnH->poly[i] + MOD) % MOD) % MOD + F->poly[i] * H->poly[i] % MOD) % MOD;
    G->NTT(IDFT), G->Resize(len);
    delete F; delete lnH; delete H;
    return G;
};

auto Quickpow = [](Polynomial* baseF, ll k1, ll k2, ll mx)->Polynomial*{
    int len = baseF->poly.size();
    if(baseF->poly[0] == 0 && mx >= len){
        Polynomial* G = new Polynomial(len);
        for(int i = 0; i < len; ++i)
            G->poly[i] = 0;
        return G;
    }
    if(len == 1){
        Polynomial* G = new Polynomial(1);
        G->poly[0] = qpow(baseF->poly[0], k2);
        return G;
    }
    int offset(0);
    while (offset < len && baseF->poly[offset] == 0) ++offset;
    if((ll)offset * k1 >= len)return new Polynomial(len);
    ll mul = qpow(baseF->poly[offset], k2), inv = qpow(baseF->poly[offset], MOD - 2);
    auto F = new Polynomial(*baseF);
    for(int i = 0; i + offset < len; ++i)F->poly[i] = F->poly[i + offset] * inv % MOD;
    for(int i = len - offset; i < len; ++i)F->poly[i] = 0;
    auto lnF = Ln(F, len);
    for(int i = 0; i < len; ++i)lnF->poly[i] = lnF->poly[i] * k1 % MOD;
    auto eLnF = Exp(Exp, lnF, len);
    ll shift = offset * k1;
    for(int i = len - 1; i >= shift; --i)
        eLnF->poly[i] = eLnF->poly[i - shift];
    for(int i = 0; i < shift; ++i)
        eLnF->poly[i] = 0;
    for(auto i = 0; i < len; ++i)eLnF->poly[i] = eLnF->poly[i] * mul % MOD;
    delete lnF; delete F;
    return eLnF;
};

struct Complex{
    ll x, y;
    static ll w;
    friend Complex operator *(const Complex &a, const Complex &b){
        return Complex{
            (a.x * b.x % MOD + w * a.y % MOD * b.y % MOD) % MOD,
            (a.x * b.y % MOD + a.y * b.x % MOD) % MOD
        };
    }
    static ll qpow(Complex a, ll b){
        Complex ret{1, 0};
        while(b){
            if(b & 1)ret = ret * a;
            a = a * a;
            b >>= 1;
        }return ret.x;
    }
};
ll Complex::w;
auto Cipolla = [](ll x)->ll{
    if(qpow(x, (MOD - 1) >> 1) == MOD - 1)return -1;
    while(true){
        ll a = (1ll * rnd() << 15 | rnd()) % MOD;
        Complex::w = (a * a % MOD + MOD - x) % MOD;
        if(qpow(Complex::w, (MOD - 1) >> 1) == MOD - 1) {
            ll res = Complex::qpow(Complex{a, 1}, (MOD + 1) >> 1);
            return min(res, MOD - res);
        }
    }
};

//Require A[0] is a quadratic residue modulo 998244353
auto ExSqrt = [](auto&& self, Polynomial* baseF, int len)->Polynomial*{
    if(len == 1){
        Polynomial *G = new Polynomial(1);
        auto res = Cipolla(baseF->poly[0]);
        G->poly[0] = min(res, MOD - res);
        return G;
    }
    auto H = self(self, baseF, (len + 1) >> 1);
    auto invH = Inverse(Inverse, H, len);
    int base(1); while(base < (len << 1))base <<= 1;
    auto G = new Polynomial(base), F = new Polynomial(len);
    for(int i = 0; i < min(len, (int)baseF->poly.size()); ++i)F->poly[i] = baseF->poly[i];
    H->Resize(base), invH->Resize(base), F->Resize(base);
    H->NTT(DFT), F->NTT(DFT), invH->NTT(DFT);
    for(int i = 0; i < base; ++i)G->poly[i] = (F->poly[i] * invH->poly[i] % MOD + H->poly[i]) % MOD * inv2 % MOD;
    G->NTT(IDFT), G->Resize(len);
    delete H; delete invH; delete F;
    return G;
};

// auto CDQ = [](Polynomial* baseF, int l, int r)->Polynomial*{
//     if(l == r)return BuildPoly(l);
//     int mid = (l + r) >> 1;
//     Polynomial L = CDQ(l, mid, mx), R = CDQ(mid + 1, r, mx);
//     // for(int i = l; i <= r; ++i)pol[i].poly.clear(), pol[i].poly.shrink_to_fit(), pol[i].len = 0;
//     return Mul(L, R, mx);
// }

namespace Tests{
    auto ImplementMultiply = [](void)->void{
        int N = read() + 1, M = read() + 1;
        Polynomial *A = new Polynomial(N), *B = new Polynomial(M);
        for(int i = 0; i < N; ++i)A->poly[i] = read();
        for(int i = 0; i < M; ++i)B->poly[i] = read();
        delete Multiply(A, B)->Desc();
        delete A; delete B;
    };
    auto ImplementInverse = [](void)->void{
        int N = read();
        Polynomial *A = new Polynomial(N);
        for(int i = 0; i < N; ++i)A->poly[i] = read();
        delete Inverse(Inverse, A, N)->Desc();
        delete A;
    };
    auto ImplementLn = [](void)->void{
        int N = read();
        Polynomial *A = new Polynomial(N);
        for(int i = 0; i < N; ++i)A->poly[i] = read();
        delete Ln(A, N)->Desc();
        delete A;
    };
    auto ImplementExp = [](void)->void{
        int N = read();
        Polynomial *A = new Polynomial(N);
        for(int i = 0; i < N; ++i)A->poly[i] = read();
        delete Exp(Exp, A, N)->Desc();
        delete A;
    };
    auto ImplementSqrt = [](void)->void{
        int N = read();
        Polynomial *A = new Polynomial(N);
        for(int i = 0; i < N; ++i)A->poly[i] = read();
        delete Sqrt(Sqrt, A, N)->Desc();
        delete A;
    };
    auto ImplementExSqrt = [](void)->void{
        int N = read();
        Polynomial *A = new Polynomial(N);
        for(int i = 0; i < N; ++i)A->poly[i] = read();
        delete ExSqrt(ExSqrt, A, N)->Desc();
        delete A;
    };
    auto ImplementQuickPow = [](void)->void{
        auto ReadIndex = [](void)->tuple < ll, ll, ll >{
            ll ret1(0), ret2(0), mx(0);
            char c = getchar(); while(!isdigit(c))c = getchar();
            while(isdigit(c)){
                ((ret1 *= 10) += c - '0') %= MOD;
                ((ret2 *= 10) += c - '0') %= MOD - 1;
                if(mx < 10000000)
                    mx = mx * 10 + c - '0';
                c = getchar();
            }return {ret1, ret2, mx};
        };
        int N = read();
        Polynomial *A = new Polynomial(N);
        auto [k1, k2, mx] = ReadIndex();
        for(int i = 0; i < N; ++i)A->poly[i] = read();
        delete Quickpow(A, k1, k2, mx)->Desc();
        delete A;
    };
    
}

int main(){
    Tests::ImplementExSqrt();

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