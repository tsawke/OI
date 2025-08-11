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
const ll inv_g = qpow(g, MOD - 2);
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
        this->poly.resize(len, 0);
    }
    void Derivate(void){
        int len = poly.size();
        poly[0] = 0;
        for(int i = 1; i < len; ++i)poly[i - 1] = i * poly[i] % MOD, poly[i] = 0;
        Resize(len - 1);
    }
    void Integrate(void){
        int len = poly.size();
        Resize(len + 1);
        for(int i = len - 1; i >= 0; --i)poly[i + 1] = poly[i] * qpow(i + 1, MOD - 2) % MOD, poly[i] = 0;
    }
    auto Desc(void){
        int len = poly.size();
        // printf("Polynomial(len = %d): ", len);
        for(int i = 0; i < len; ++i)printf("%lld%c", poly[i], i == len - 1 ? '\n' : ' ');
        return this;
    }
}basic[13];

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
    for(int i = 0; i < base; ++i)G->poly[i] = (F->poly[i] * invH->poly[i] % MOD + H->poly[i]) % MOD * qpow(2, MOD - 2) % MOD;
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
auto Quickpow = [](Polynomial* baseF, ll k1, ll k2)->Polynomial*{
    int len = baseF->poly.size();
    int offset(0);
    while (offset < len && baseF->poly[offset] == 0) ++offset;
    if((ll)offset * k1 >= len)return new Polynomial(len);
    ll mul = qpow(baseF->poly[offset], k2), inv = qpow(baseF->poly[offset], MOD - 2);
    auto F = new Polynomial(*baseF);
    for(int i = 0; i + offset < len; ++i)F->poly[i] = F->poly[i + offset];
    for(int i = len - offset; i < len; ++i)F->poly[i] = 0;
    auto lnF = Ln(F, len);
    for(int i = 0; i < len; ++i)H->poly[i] = H->poly[i] * k1 % MOD;
    

    *F = *baseF;
    int offset(0);
    
    
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
    auto ImplementQuickPow = [](void)->void{
        auto ReadIndex = [](void)->tuple < ll, ll, ll >{
            ll ret1(0), ret2(0), mx(0);
            char c = getchar(); while(!isdigit(c))c = getchar();
            while(isdigit(c)){
                ((ret1 *= 10) += c - '0') %= MOD;
                ((ret2 *= 10) += c - '0') %= MOD - 1;
                mx = max({mx, ret1, ret2});
                c = getchar();
            }return {ret1, ret2, mx};
        };

    };

    
}

int main(){
    Tests::ImplementSqrt();

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