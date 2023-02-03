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

int N, M, X, S;
int cnt[8100];
int pos[32100];
ll g(3), inv_g;
ll gm;
int toLog[8100];

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
    ll poly[32100];
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
                    ll tmp = g * p[i + mid] % MOD;
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
    auto operator %= (const int mod){
        for(int i = mod; i < len; ++i)poly[i] = 0;
        len = min(len, mod);
    }
    void Print(void){
        printf("Polynomial(len = %d): ", len);
        for(int i = 0; i < len; ++i)printf("%lld ", poly[i]);
        printf("\n");
    }
};
Polynomial H[31];
Polynomial Ans;
ll GetGM(void){
    for(int i = 2; true; ++i){
        ll cur = i;
        bool flag(true);
        for(int j = 2; j <= M - 2; ++j){
            (cur *= i) %= M;
            if(cur == 1){flag = false; break;}
        }
        if(flag && cur * i % M == 1)return i;
    }return -1;
}

void Mul(Polynomial *ret, Polynomial a, Polynomial b){
    int base(1);
    while(base < a.len + b.len - 1)base <<= 1;
    a.len = b.len = base;
    a.NTT(DFT), b.NTT(DFT);
    for(int i = 0; i < base; ++i)a.poly[i] = a.poly[i] * b.poly[i] % MOD;
    a.NTT(IDFT);
    *ret %= M - 1; ret->len = M - 1;
    for(int i = 0; i < M - 1; ++i)ret->poly[i] = a.poly[i];
    for(int i = M - 1; i < base; ++i)(ret->poly[i % (M - 1)] += a.poly[i]) %= MOD;
}

int main(){
    inv_g = qpow(g, MOD - 2);
    N = read(), M = read(), X = read(), S = read();
    gm = GetGM();
    toLog[0] = M;
    ll cur(1); toLog[cur] = 0;
    for(int i = 1; i <= M - 1 - 1; ++i)(cur *= gm) %= M, toLog[cur] = i;
    X = toLog[X];
    for(int i = 1; i <= S; ++i)cnt[toLog[read()]]++;
    for(int i = 0; i < M - 1; ++i)H[0].poly[i] = cnt[i];
    H[0].len = M;
    for(int i = 1; i <= 30; ++i)Mul(&H[i], H[i - 1], H[i - 1]);
    Ans.len = 1, Ans.poly[0] = 1;
    for(int i = 0; i <= 30; ++i)if((1 << i) & N)Mul(&Ans, Ans, H[i]);
    printf("%lld\n", Ans.poly[X]);
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