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

int N, M, K;
int pos[810000];
bool A[810000], B[810000], rB[810000];
int sumA[810000], sumB[810000];
int Ans[810000];
int ans(0);
ll g(3), inv_g;
string S1, S2;

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
    ll poly[810000];
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
    void Print(void){
        printf("Polynomial(len = %d): ", len);
        for(int i = 0; i < len; ++i)printf("%lld ", poly[i]);
        printf("\n");
    }
};

Polynomial PA, PB;
int base(1);
void Make(char flag){
    for(int i = 0; i < M; ++i)A[i] = S2.at(i) == flag ? 1 : 0;
    for(int i = 0; i < N; ++i)B[i] = S1.at(i) == flag ? 1 : 0;
    for(int i = 0; i < base; ++i)sumA[i] = (i ? sumA[i - 1] : 0) + A[i], sumB[i] = (i ? sumB[i - 1] : 0) + B[i];
    for(int i = 0; i < N; ++i)if((i + K < N ? sumB[i + K] : sumB[N - 1]) - (i - K - 1 >= 0 ? sumB[i - K - 1] : 0) > 0)rB[i] = 1; else rB[i] = 0;
    // for(int i = 0; i < N; ++i)printf("sumB[%d] = %d\n", i, sumB[i]);
    for(int i = 0; i < base; ++i)PA.poly[i] = A[i], PB.poly[i] = rB[i];
    // PA.Print(), PB.Print();
    PA.NTT(DFT), PB.NTT(DFT);
    for(int i = 0; i < base; ++i)PA.poly[i] = PA.poly[i] * PB.poly[i] % MOD;
    PA.NTT(IDFT);
    // PA.Print();
    for(int i = 0; i < base; ++i)Ans[i] += sumA[i] - PA.poly[i];
    // for(int i = 0; i < base; ++i)printf("Ans[%d] = %d\n", i, Ans[i]);
}

int main(){
    inv_g = qpow(g, MOD - 2);
    N = read(), M = read(), K = read();
    cin >> S1 >> S2;
    reverse(S2.begin(), S2.end());
    int clen = N + M - 1;
    while(base < clen)base <<= 1;
    PA.len = PB.len = base;
    Make('A'), Make('T'), Make('C'), Make('G');
    for(int i = M - 1; i <= N - 1; ++i)if(!Ans[i])++ans;
    printf("%d\n", ans);
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