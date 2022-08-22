#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <mmintrin.h>

#define PI M_PI
#define E M_E
#define DFT true
#define IDFT false
#define eps 1e-6

#define comp complex < double >

/******************************
abbr
pat -> pattern
pol/poly -> polynomial
omg -> omega
******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

class Polynomial{
    private:
        int lena, lenb;
        int len;
        comp A[2100000], B[2100000];
    public:
        comp Omega(int, int, bool);
        void Init(void);
        void FFT(comp*, int, bool);
        void Reverse(comp*);
        void MakeFFT(void);
}poly;

template<typename T = int>
inline T read(void);

int main(){
    poly.Init();
    poly.MakeFFT();

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
void Polynomial::MakeFFT(void){
    FFT(A, len, DFT), FFT(B, len, DFT);
    for(int i = 0; i <= len; ++i)A[i] *= B[i];
    FFT(A, len, IDFT);
    for(int i = 0; i <= lena + lenb - 2; ++i)
        printf("%d%c", int(A[i].real() / len + eps + 0.5), i == lena + lenb - 2 ? '\n' : ' ');
}
void Polynomial::Reverse(comp* pol){
    int pos[len + 10];
    memset(pos, 0, sizeof(pos));
    for(int i = 0; i < len; ++i){
        pos[i] = pos[i >> 1] >> 1;
        if(i & 1)pos[i] |= len >> 1;
    }
    for(int i = 0; i < len; ++i)if(i < pos[i])swap(pol[i], pol[pos[i]]);
}
void Polynomial::FFT(comp* pol, int len, bool pat){
    Reverse(pol);
    for(int size = 2; size <= len; size <<= 1){
        for(comp* p = pol; p != pol + len; p += size){
            int mid(size >> 1);
            for(int i = 0; i < mid; ++i){
                auto tmp = Omega(size, i, pat) * p[i + mid];
                p[i + mid] = p[i] - tmp;
                p[i] = p[i] + tmp;
            }
        }
    }
}
void Polynomial::Init(void){
    lena = read(), lenb = read();
    for(int i = 0; i <= lena; ++i)A[i].real((double)read());
    for(int i = 0; i <= lenb; ++i)B[i].real((double)read());
    len = 1;
    lena++, lenb++;
    while(len <= lena + lenb)len <<= 1;
}
comp Polynomial::Omega(int n, int k, bool pat){
    if(pat == DFT)return comp(cos(2 * PI * k / n), sin(2 * PI * k / n));
    return conj(comp(cos(2 * PI * k / n), sin(2 * PI * k / n)));
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