#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <unistd.h>

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

int pos[410000];
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
    ll poly[410000];
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
    void Derivate(void){
        poly[0] = 0;
        for(int i = 1; i < len; ++i)poly[i - 1] = i * poly[i] % MOD, poly[i] = 0;
    }
    void Integrate(void){
        for(int i = len - 1; i >= 0; --i)poly[i + 1] = poly[i] * qpow(i + 1, MOD - 2) % MOD, poly[i] = 0;
        ++len;
    }
    void Resize(int P){
        for(int i = P; i < len; ++i)poly[i] = 0;
        for(int i = len; i < P; ++i)poly[i] = 0;
        len = P;
    }
    void Print(void){
        // printf("Polynomial(len = %d): ", len);
        for(int i = 0; i < len; ++i)printf("%lld ", poly[i]);
        printf("\n");
    }
}basic[3];
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

int N;
Polynomial A;

int main(){
    inv_g = qpow(g, MOD - 2);
    N = A.len = read();
    for(int i = 0; i < A.len; ++i)A.poly[i] = read();
    auto invA = Inverse(&A, A.len);
    A.Derivate();
    int base(1); while(base < A.len + invA->len)base <<= 1;
    A.Resize(base), invA->Resize(base);
    A.NTT(DFT), invA->NTT(DFT);
    for(int i = 0; i < base; ++i)A.poly[i] = A.poly[i] * invA->poly[i] % MOD;
    A.NTT(IDFT), A.Resize(N);
    A.Integrate(), A.Resize(N);
    A.Print();
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