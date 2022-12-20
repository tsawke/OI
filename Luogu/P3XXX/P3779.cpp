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

#define comp complex < ld >
#define DFT (true)
#define IDFT (false)
#define EPS (ld)(1e-10)

template < typename T = int >
inline T read(void);

int N, M;

comp comp_qpow(comp a, ll b){
    comp ret(1.0, 0.0), mul(a);
    while(b){
        if(b & 1)ret = ret * mul;
        b >>= 1;
        mul = mul * mul;
    }return ret;
}

class Polynomial{
private:
public:
    int len;
    comp A[2100000];
    comp Omega(int n, int k, bool pat){
        if(pat == DFT)return comp(cos(2 * PI * k / n), sin(2 * PI * k / n));
        return conj(comp(cos(2 * PI * k / n), sin(2 * PI * k / n)));
    }
    void Reverse(comp* pol){
        int pos[len + 10];
        memset(pos, 0, sizeof pos);
        for(int i = 0; i < len; ++i){
            pos[i] = pos[i >> 1] >> 1;
            if(i & 1)pos[i] |= len >> 1;
        }
        for(int i = 0; i < len; ++i)if(i < pos[i])swap(pol[i], pol[pos[i]]);
    }
    void FFT(comp* pol, int len, bool pat){
        Reverse(pol);
        for(int siz = 2; siz <= len; siz <<= 1)
            for(comp* p = pol; p != pol + len; p += siz){
                int mid = siz >> 1;
                for(int i = 0; i < mid; ++i){
                    auto tmp = Omega(siz, i, pat) * p[i + mid];
                    p[i + mid] = p[i] - tmp, p[i] = p[i] + tmp;
                }
            }
        if(pat == IDFT)
            for(int i = 0; i <= len; ++i)
            A[i].real(A[i].real() / (ld)len), A[i].imag(A[i].imag() / (ld)len);
    }
    void MakeFFT(void){
        FFT(A, len, DFT);
        for(int i = 0; i < len; ++i)A[i] = comp_qpow(A[i], N);
        FFT(A, len, IDFT);
    }
}poly;

ld mu, sigma2;

ld f(ld x){
    return exp(-(x - mu) * (x - mu) / 2.0 / sigma2) / sqrt(2.0 * PI * sigma2);
}
ld Simpson(ld a, ld b){
    return (b - a) * (f(a) + f(b) + 4 * f((a + b) / 2.0)) / 6.0;
}
ld Adaptive(ld l, ld r, ld cur, ld eps = 1e-6){
    ld mid = (l + r) / 2.0;
    ld lval = Simpson(l, mid), rval = Simpson(mid, r);
    if(fabs(lval + rval - cur) <= eps * 15.0)return lval + rval + (lval + rval - cur) / 15.0;
    return Adaptive(l, mid, lval, eps / 2.0) + Adaptive(mid, r, rval, eps / 2.0);
}

int main(){
    int T = read();
    while(T--){
        M = read(), N = read();
        if(N * M <= (int)1e5){
            memset(poly.A, 0, sizeof poly.A);
            for(int i = 0; i <= M - 1; ++i)
                poly.A[i].real((ld)1.0 / (ld)M), poly.A[i].imag(0.0);
            poly.len = 1;
            while(poly.len <= N * M)poly.len <<= 1;
            poly.MakeFFT();
            for(int i = 1; i <= 10; ++i){
                int A = read(), B = read();
                ld ans(0.0);
                for(int j = A; j <= B; ++j)ans += poly.A[j].real();
                printf("%.10Lf\n", ans);
            }
        }else{
            mu = 0.0, sigma2 = 1.0;
            ld real_mu = (ld)(M - 1) / 2.0;
			ld real_sig = ((ld)M * M - 1.0) / 12.0;
            for(int i = 1; i <= 10; ++i){
                int A = read(), B = read();
                ld L = (ld)((ld)A - N * real_mu) / sqrt(N * real_sig);
                ld R = (ld)((ld)B - N * real_mu) / sqrt(N * real_sig);
                // WA(80pts):
                // printf("%.10Lf\n", Adaptive((ld)L, (ld)R, Simpson(L, R)));
                // AC:
                printf("%.8Lf\n", Adaptive((ld)0, (ld)R, Simpson(0, R)) - Adaptive((ld)0, (ld)L, Simpson(0, L)));
            }

            // mu = (ld)N * (ld)(M - 1) / 2.0;
            // sigma2 = (ld)N * (ld)((ll)M * M - 1) / 12.0;
            // for(int i = 1; i <= 10; ++i){
            //     int A = read(), B = read();
            //     // WA(80pts):
            //     // printf("%.8Lf\n", Adaptive((ld)A, (ld)B, Simpson(A, B)));
            //     // WA(70pts):
            //     // printf("%.8Lf\n", Adaptive((ld)0, (ld)B, Simpson(0, B)) - Adaptive((ld)0, (ld)A, Simpson(0, A)));
            // }
        }
    }
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