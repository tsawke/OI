#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (998244353ll)
#define DFT (true)
#define IDFT (false)

template < typename T = int >
inline T read(void);

int N;
int lim;
ll g = 3, inv_g;
int pos[280000];

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
    int P[280000];
    void Reverse(void){
        pos[0] = 0;
        for(int i = 1; i <= len - 1; ++i){
            pos[i] = pos[i >> 1] >> 1;
            if(i & 1)pos[i] |= len >> 1;
        }for(int i = 0; i <= len - 1; ++i)if(i < pos[i])swap(P[i], P[pos[i]]);
    }
    void NTT(bool pat){
        Reverse();
        for(int siz = 2; siz <= len; siz <<= 1){
            ll gn = qpow(pat ? g : inv_g, (MOD - 1) / siz);
            for(int* p = P; p != P + len; p += siz){
                int mid = siz >> 1; ll g(1);
                for(int i = 0; i < mid; ++i, (g *= gn) %= MOD){
                    ll tmp = (ll)g * p[i + mid] % MOD;
                    p[i + mid] = ((ll)p[i] - tmp) % MOD;
                    p[i] = ((ll)p[i] + tmp) % MOD;
                }
            }
        }
        if(!pat){
            ll inv_len = qpow(len, MOD - 2);
            for(int i = 0; i <= len - 1; ++i)P[i] = ((ll)P[i] * inv_len) % MOD;
        }
    }
    void Print(void){
        for(int i = 0; i <= len - 1; ++i)printf("%d%c", P[i], i == len - 1 ? '\n' : ' ');
    }
    Polynomial operator %= (const ll &mod){
        for(int i = mod; i <= len - 1; ++i)P[i] = 0;
        len = mod;
        return *this;
    }
    Polynomial operator *= (Polynomial B){
        int rlen(1);
        while(rlen < len + B.len)rlen <<= 1;
        len = B.len = rlen;
        // printf("len = %d\n", rlen);
        // ret.len = rlen;
        // A.Print(), B.Print();
        NTT(DFT), B.NTT(DFT);
        // A.Print(), B.Print();
        for(int i = 0; i <= len - 1; ++i)P[i] = (ll)P[i] * B.P[i] % MOD;
        NTT(IDFT);
        // ret.Print();
        return (*this) %= lim;
    }
    Polynomial operator *= (const ll &mul){
        for(int i = 0; i <= len - 1; ++i)P[i] = ((ll)P[i] * mul) % MOD;
        return *this;
    }
    Polynomial operator -= (const Polynomial &B){
        len = max(len, B.len);
        for(int i = 0; i <= len - 1; ++i)P[i] = (((ll)P[i] - (ll)B.P[i]) % MOD + MOD) % MOD;
        return *this;
    }
}F, H, tmp;

Polynomial Make(int len = N){
    // printf("making len = %d\n", len);
    if(len == 1){
        Polynomial ret;
        ret.len = 1, ret.P[0] = qpow(F.P[0], MOD - 2);
        return ret;
    }
    H = Make(int(ceil((double)len / 2.0)));
    // H.Print();
    lim = len;
    // printf("len = %d, 2H:", len); (H * 2).Print();
    // printf("F: "); F.Print();
    // printf("F * H: "); (F * H).Print();
    // printf("F * H * H: "); (F * H * H).Print();
    tmp = H;
    return (H *= 2) -= ((tmp *= H) *= F);
    // return  H * 2 - F * H * H;
}

int main(){
    // freopen("P4238_16.in", "r", stdin);
    inv_g = qpow(g, MOD - 2);
    F.len = N = read();
    for(int i = 0; i <= N - 1; ++i)F.P[i] = read();
    // decltype(F) tmp; tmp.len = 1; tmp.P[0] = 1;
    // F.Print();
    // tmp.Print();
    // (F * tmp).Print();
    Make().Print();
    // for(int i = 0; i <= N - 1; ++i)printf("%lld%c", G.P[i], i == N - 1 ? '\n' : ' ');
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