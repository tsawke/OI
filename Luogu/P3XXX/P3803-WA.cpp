#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;


template<typename T = int>
inline T read(void);

class Polynomial{
    private:
        int N, M;
        int lim;
        vector< complex<double> >A;
        vector< complex<double> >B;
        int n;
    public:
        Polynomial(void);

        void Init(void);
        void ReadA(void);
        void ReadB(void);
        complex<double>CalOmega(int, int, bool = true);
        void FFT(vector< complex<double> >&, bool = true/*true-DFT, false-IDFT*/);
        void MakeFFT(void);
};

int main(){
    (void)!freopen("in.txt", "r", stdin);
    Polynomial poly;
    poly.Init();
    poly.ReadA();
    poly.ReadB();
    //printf("Init Complete.\n");
    poly.MakeFFT();
    return 0;
}
void Polynomial::MakeFFT(void){
    // reverse(A.begin(), A.end());
    // reverse(B.begin(), B.end());
    //printf("A:");for(auto i : A)cout<<i<<endl;
    //printf("B:");for(auto i : B)cout<<i<<endl;
    this->FFT(this->A), this->FFT(this->B);
    //printf("DFT Complete.\n");
    //printf("A:");for(auto i : A)cout<<i<<endl;
    //printf("B:");for(auto i : B)cout<<i<<endl;
    for(int i = 0; i <= this->lim - 1; ++i){
        this->A.at(i) *= this->B.at(i);
    }
    //printf("C:");for(auto i : A)cout<<i<<endl;
    this->FFT(this->A, false);
    // for(int i = 0; i <= this->n; ++i)//printf("%d%c", (int)this->A.at(i).real(), i == this->n ? '\n' : ' ');
    //Error
}
void Polynomial::FFT(vector< complex<double> > &A, bool flag){
    //printf("################# FFT - size=%d, flag=%d\n", A.size(), flag);
    int len = A.size();
    if(len == 1)return;
    int mid = len >> 1;
    vector< complex<double> > A1, A2;
    for(int i = 0; i <= mid - 1; ++i){
        A1.push_back(complex<double>(A.at(i << 1)));
        A2.push_back(complex<double>(A.at(i << 1 | 1)));
    }
    //printf("Spilit Comptete.\n");
    this->FFT(A1, flag), this->FFT(A2, flag);
    // A.clear();
    for(int i = 0 ; i <= mid - 1; ++i){
        auto omega = this->CalOmega(len, i);
        A.at(i) = A1.at(i) + omega * A2.at(i);
        A.at(i + mid) = A1.at(i) - omega * A2.at(i);
        //printf("Merge i=%d, mid=%d", i, mid);
    }
}
complex<double>Polynomial::CalOmega(int n, int k, bool flag){
    if(flag)return complex<double>(cos(M_PI * 2.00 * k / n), sin(M_PI * 2.00 * k / n));
    return conj(complex<double>(cos(M_PI * 2.00 * k / n), sin(M_PI * 2.00 * k / n)));
}
Polynomial::Polynomial(void){
    ;
}
void Polynomial::Init(void){
    this->N = read(), this->M = read();
    this->n = this->N + this->M;
    this->lim = 1;
    while(this->lim <= this->N + this->M)this->lim <<= 1;
    
    //printf("LIM-%d\n", this->lim);
}
void Polynomial::ReadA(void){
    for(int i = 0; i <= this->N; ++i)this->A.push_back(complex<double>((double)read(), 0.00));
    for(int i = this->N + 1; i <= this->lim - 1; ++i)this->A.push_back(complex<double>(0.00, 0.00));
}
void Polynomial::ReadB(void){
    for(int i = 0; i <= this->M; ++i)this->B.push_back(complex<double>((double)read(), 0.00));
    for(int i = this->M + 1; i <= this->lim - 1; ++i)this->B.push_back(complex<double>(0.00, 0.00));
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