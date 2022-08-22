#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());

#define DFT true
#define IDFT false

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define int ll

#define MOD 469762049
#define EPS 1e-8

int N;
int a[110000];
int cnt[10];
template<typename T = int>
inline T read(void);

complex<double>f1[210000], f2[210000];
complex<double> Ome(int n, int k, bool flag){
    if(flag == DFT)return complex<double>(cos(2.0000 * PI * k / n), sin(2.0000 * PI * k / n));
    return conj(complex<double>(cos(2.0000 * PI * k / n), sin(2.0000 * PI * k / n)));
}
void FFT(complex<double> *f, int n, bool flag){
    
    // printf("FFT: n = %lld, flag = %d\n", n, flag);
    //     for(int i = 0; i <= n; ++i)printf("%.2lf ", f[i].real());
    //     printf("\n");
    if(n == 1)return;
    complex<double>fa[n / 2 + 1], fb[n / 2 + 1];
    for(int i = 0; i <= n / 2 - 1; ++i){
        fa[i] = f[i * 2];
        fb[i] = f[i * 2 + 1];
    }
    FFT(fa, n / 2, flag);
    FFT(fb, n / 2, flag);
    int mid = n / 2;
    for(int i = 0; i <= mid - 1; ++i){
        complex<double>tmp = Ome(n, i, flag);
        f[i] = fa[i] + tmp * fb[i];
        f[i + mid] = fa[i] - tmp * fb[i];
    }
}
signed main(){
    freopen("poly.in", "r", stdin);
    freopen("poly.out", "w", stdout);
    N = read();
    if(N == 1){
        int a = read();
        if(a >= 2)printf("%lld\n%d\n%d\n", a - 2, 2, 0);
        if(a == 1)printf("%d\n%d\n%d\n", 0, 0, 1);
        if(a == 0)printf("0\n0\n0\n");
        return 0;
    }
    if(N == 2){
        int a1 = read(), a2 = read();
        if(a1 >= 2 && a2 >= 2)printf("%lld\n%lld\n%d\n%d\n%d\n", a1 * a2 - (a1 * 2 + a2 * 2 - 4), a1 * 2 + a2 * 2 - 4 - 4, 4, 0, 0);
        if((a1 == 1 && a2 == 2) || (a1 == 2 && a2 == 1))printf("%d\n%d\n%d\n%d\n%d\n", 0, 0, 0, 2, 0);
        if(a1 == 1 && a2 == 1)printf("%d\n%d\n%d\n%d\n%d\n", 0, 0, 0, 0, 1);
        if(a1 == 0 || a2 == 0)printf("%d\n%d\n%d\n%d\n%d\n", 0, 0, 0, 0, 0);
        return 0;
    }
    for(int i = 1; i <= N; ++i){
        a[i] = read();
        if(a[i] == 0)++cnt[0];
        if(a[i] == 1)++cnt[1];
    }
    if(cnt[0]){for(int i = 1; i <= N * 2 + 1; ++i)printf("0\n"); return 0;}
    if(cnt[1] == N){for(int i = 1; i <= N * 2; ++i){printf("0\n");} printf("1\n"); return 0;}
    int lena(0);
    //i == 1
    {
        switch(a[1]){
            case 1:{f1[2].real(1.0000); break;}
            default:{
                f1[1].real(2.0000);
                f1[0].real((a[1] - 2) * 1.0000);
                break;
            }
        }
        for(int j = lena; j <= lena + 3; ++j)if(f1[j].real() > 0.0000 || f1[j].real() < 0.0000)lena = j;
    }


    for(int i = 2; i <= N; ++i){
       
        //init f1?
        for(int j = 0; j <= 3; ++j)f2[j].real(0.0000), f2[j].imag(0.0000);
        switch(a[i]){
            case 1:{f2[2].real(1.0000); break;}
            default:{
                f2[1].real(2.0000);
                f2[0].real((a[i] - 2) * 1.0000);
                break;
            }
        }
        int lenb(0);
        for(int j = 0; j <= 2; ++j)if(f2[j].real() > 0.0000 || f2[j].real() < 0.0000)lenb = j;

        // printf("No.%lld\n", i);
        // for(int i = 0; i <= lena; ++i)printf("%.2lf ", f1[i].real());
        // printf("\n");
        // for(int i = 0; i <= lenb; ++i)printf("%.2lf ", f2[i].real());
        // printf("\n\n");


        int n = 1;
        //lena + lenb + (1?)
        while(n <= lena + lenb)n <<= 1;
        // reverse(f1, f1 + lena);
        // reverse(f2, f2 + lenb);
        FFT(f1, n, DFT);
        FFT(f2, n, DFT);
        for(int j = 0; j <= n; ++j)f1[j] = f1[j] * f2[j];
        FFT(f1, n, IDFT);
        for(int j = 0; j <= n; ++j)f1[j].real(double( (int)(f1[j].real() / (double)n + EPS) % (MOD) ));
        for(int j = lena; j <= lena + 3; ++j)if(f1[j].real() > 0.0000 || f1[j].real() < 0.0000)lena = j;
        //upd lena
        // reverse(f1, f1 + lena);
        // reverse(f2, f2 + lenb);

    }
    for(int i = 0; i <= N * 2; ++i)printf("%d\n", (signed)f1[i].real() % MOD);

    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
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