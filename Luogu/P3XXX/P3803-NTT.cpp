#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <mmintrin.h>

#define PI M_PI
#define E M_E
#define DFT true
#define IDFT false
#define eps 1e-6
#define MOD 998244353

/******************************
abbr
pat -> pattern
pol/poly -> polynomial
******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

ll kpow(int a, int b){
    ll ret(1ll), mul((ll)a);
    while(b){
        if(b & 1)ret = (ret * mul) % MOD;
        b >>= 1;
        mul = (mul * mul) % MOD;
    }
    return ret;
}
class Polynomial{
    private:
        int lena, lenb;
        int len;
        int g, inv_g;
        int A[2100000], B[2100000];
    public:
        int Omega(int, int, bool);
        void Init(void);
        void NTT(int*, int, bool);
        void Reverse(int*);
        void MakeNTT(void);
}poly;

template<typename T = int>
inline T read(void);

int main(){
    poly.Init();
    poly.MakeNTT();
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
void Polynomial::MakeNTT(void){
    NTT(A, len, DFT), NTT(B, len, DFT);
    for(int i = 0; i <= len; ++i)A[i] = ((ll)A[i] * B[i]) % MOD;
    NTT(A, len, IDFT);
    int mul_inv = kpow(len, MOD - 2);
    for(int i = 0; i <= lena + lenb - 2; ++i)
        printf("%d%c", (ll)A[i] * mul_inv % MOD, i == lena + lenb - 2 ? '\n' : ' ');
}
void Polynomial::Reverse(int* pol){
    int pos[len + 10];
    memset(pos, 0, sizeof(pos));
    for(int i = 0; i < len; ++i){
        pos[i] = pos[i >> 1] >> 1;
        if(i & 1)pos[i] |= len >> 1;
    }
    for(int i = 0; i < len; ++i)if(i < pos[i])swap(pol[i], pol[pos[i]]);
}
void Polynomial::NTT(int* pol, int len, bool pat){
    Reverse(pol);
    for(int size = 2; size <= len; size <<= 1){
        int gn = kpow(pat == DFT ? g : inv_g, (MOD - 1) / size);
        for(int* p = pol; p != pol + len; p += size){
            int mid(size >> 1);
            int g(1);
            for(int i = 0; i < mid; ++i, g = ((ll)g * gn) % MOD){
                auto tmp = ((ll)g * p[i + mid]) % MOD;
                p[i + mid] = (p[i] - tmp + MOD) % MOD;
                p[i] = (p[i] + tmp) % MOD;
            }
        }
    }
}
void Polynomial::Init(void){
    lena = read(), lenb = read();
    for(int i = 0; i <= lena; ++i)A[i] = read();
    for(int i = 0; i <= lenb; ++i)B[i] = read();
    len = 1;
    lena++, lenb++;
    while(len < lena + lenb)len <<= 1;
    g = 3;
    inv_g = kpow(g, MOD - 2);
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