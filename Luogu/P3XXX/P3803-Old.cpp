#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

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
        printf("%d%c", int(A[i].real() / len + eps + 0.5), i == lena + lenb - 1 ? '\n' : ' ');
}
void Polynomial::FFT(comp* pol, int len, bool pat){
    if(len == 1)return;
    comp sA[len / 2 + 10], sB[len / 2 + 10];
    for(int i = 0; i <= len / 2 - 1; ++i){
        sA[i] = pol[i * 2];
        sB[i] = pol[i * 2 + 1];
    }
    FFT(sA, len / 2, pat), FFT(sB, len / 2, pat);
    for(int i = 0; i <= len / 2 - 1; ++i){
        comp omg = Omega(len, i, pat);
        pol[i] = sA[i] + omg * sB[i];
        pol[i + len / 2] = sA[i] - omg * sB[i];
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