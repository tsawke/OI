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

int N, K; ll T;
int pos[410000];
ll g(3), inv_g;
ll A[410000];

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
    void Reverse(void){
        for(int i = 0; i < len; ++i)
            pos[i] = (pos[i >> 1] >> 1) | (i & 1 ? len >> 1 : 0);
        for(int i = 0; i < len; ++i)if(i < pos[i])swap(poly[i], poly[pos[i]]);
    }
    void Shrink(void){
        for(int i = N; i < len; ++i)(poly[i % N] += poly[i]) %= MOD, poly[i] = 0;
        for(int i = 0; i < len; ++i)poly[i] %= 2;
        len = min(len, N);
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
            Shrink();
        }
    }
    void Print(void){
        printf("Polynomial(len = %d): ", len);
        for(int i = 0; i < len; ++i)printf("%lld ", poly[i]);
        printf("\n");
    }
};

Polynomial ret, mul;
void qpow(Polynomial* a, ll b){
    for(int i = 0; i < ret.len; ++i)ret.poly[i] = 0;
    ret.len = 1, ret.poly[0] = 1;
    mul = *a;
    while(b){
        if(b & 1){
            int base(1); while(base < ret.len + mul.len - 1)base <<= 1;
            ret.len = mul.len = base;
            ret.NTT(DFT), mul.NTT(DFT);
            for(int i = 0; i < base; ++i)ret.poly[i] = ret.poly[i] * mul.poly[i] % MOD;
            ret.NTT(IDFT), mul.NTT(IDFT);
        }
        b >>= 1;
        int base(1); while(base < mul.len + mul.len - 1)base <<= 1;
        mul.len = base;
        mul.NTT(DFT);
        for(int i = 0; i < base; ++i)mul.poly[i] = mul.poly[i] * mul.poly[i] % MOD;
        mul.NTT(IDFT);
    }
}


int main(){
    freopen("xortwo.in", "r", stdin);
    freopen("xortwo.out", "w", stdout);
    inv_g = qpow(g, MOD - 2);
    N = read(), K = read(); T = read < ll >();
    Polynomial origin;
    origin.len = K;
    for(int i = 0; i < origin.len; ++i)origin.poly[i] = 1;
    // {
    //     int base(1); while(base < origin.len)base <<= 1;
    //     origin.len = base;
    //     origin.Print();
    //     origin.NTT(DFT), origin.NTT(IDFT);
    //     origin.Print();
    //     base = (1); while(base < origin.len)base <<= 1;
    //     origin.len = base;
    //     origin.NTT(DFT), origin.NTT(IDFT);
    //     origin.Print();
    // }
    qpow(&origin, T);
    basic_string < int > isTrue;
    for(int i = 0; i < N; ++i)if(ret.poly[i])isTrue += i;
    // ret.Print();
    for(int i = 0; i < N; ++i)A[i] = read();
    for(int i = 0; i < N; ++i){
        ll val(0);
        for(auto j : isTrue)val ^= A[(i + j) % N];
        printf("%lld%c", val, i == N - 1 ? '\n' : ' ');
    }
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

/*
5 3 1
3 0 2 1 2

5 3 2
3 0 2 1 2

5 3 15
3 0 2 1 2

11 5 1000000000000000000
2 2 4 5 9 1 5 7 7 1 8
*/

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