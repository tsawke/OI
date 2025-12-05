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

#define MOD (998244353)
#define DFT (true)
#define IDFT (false)

template < typename T = int >
inline T read(void);

int N;
ll g(3), inv_g;
int pos[410000];

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
    ll poly[410000];
    Polynomial(void){
        len = 0;
        memset(poly, 0, sizeof poly);
    }
    void Clear(void){
        for(int i = 0; i < len; ++i)poly[i] = 0;
    }
    void Resize(int P){
        for(int i = P; i < len; ++i)poly[i] = 0;
        for(int i = len; i < P; ++i)poly[i] = 0;
        len = P;
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
                    auto tmp = p[i + mid] * g % MOD;
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
        for(int i = 0; i < len; ++i)printf("%lld%c", poly[i], i == len - 1 ? '\n' : ' ');
    }
}base[4];

Polynomial *P = base + 3;

void Divide(Polynomial* baseF, int l, int r){
    static Polynomial *H = base, *G = base + 1, *F = base + 2;
    if(l == r)return;
    int mid = (l + r) >> 1, len = r - l + 1;
    Divide(baseF, l, mid);
    // swap(H, Divide(baseF, l, mid));
    // printf("l = %d, r = %d : ", l, r);H->Print();
    int base(1); while(base <= len)base <<= 1;
    H->Resize(base), G->Resize(base), F->Resize(base);
    H->Clear(), G->Clear(), F->Clear();
    for(int i = l; i <= mid; ++i)H->poly[i - l] = P->poly[i];
    for(int i = 1; i < len; ++i)F->poly[i - 1] = baseF->poly[i];
    // F->poly[0] = 0;
    printf("Mul: \n");
    H->Print(), F->Print();
    H->NTT(DFT), F->NTT(DFT);
    for(int i = 0; i < base; ++i)
        G->poly[i] = H->poly[i] * F->poly[i] % MOD;
    G->NTT(IDFT), G->Resize(len);
    for(int i = mid + 1; i <= r; ++i)(P->poly[i] += G->poly[i - l - 1]) %= MOD;
    Divide(baseF, mid + 1, r);
}

Polynomial A;

int main(){
    P->poly[0] = 1;
    inv_g = qpow(g, MOD - 2);
    N = A.len = read();
    for(int i = 1; i < A.len; ++i)A.poly[i] = read();
    int base(1); while(base < A.len)base <<= 1;
    A.Resize(base);
    // A.Print();
    // A.NTT(DFT), A.NTT(IDFT);
    // A.Print();
    Divide(&A, 0, base - 1);
    P->Print();
    // auto B = Divide(&A, 0, base - 1);
    // for(int i = 0; i < N; ++i)printf("%lld%c", B->poly[i], i == N - 1 ? '\n' : ' ');
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