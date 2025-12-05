#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define EPS (1e-9)

template<typename T = int>
inline T read(void);

struct Fraction{//non-negative
    __int128_t a, b;
    Fraction Shrink(void){
        __int128_t div = __gcd(a, b);
        a /= div, b /= div;
        return *this;
    }
    friend const Fraction operator + (const Fraction &x, const Fraction &y){
        __int128_t below = x.b * y.b / __gcd(x.b, y.b);
        return Fraction{below / x.b * x.a + below / y.b * y.a, below}.Shrink();
    }
    friend const Fraction operator / (const Fraction &x, const int &v){
        return Fraction{x.a, x.b * v}.Shrink();
    }
    friend const Fraction operator / (const Fraction &x, const Fraction &y){
        return Fraction{x.a * y.b, x.b * y.a}.Shrink();
    }
    friend const Fraction operator * (const Fraction &x, const Fraction &y){
        return Fraction{x.a * y.a, x.b * y.b}.Shrink();
    }
    friend const bool operator <= (const Fraction &x, const Fraction &y){
        return x.a * y.b <= y.a * x.b;
    }
    friend const bool operator >= (const Fraction &x, const Fraction &y){
        return x.a * y.b > y.a * x.b;
    }
    friend const bool operator < (const Fraction &x, const Fraction &y){
        return x.a * y.b < y.a * x.b;
    }
    friend const bool operator > (const Fraction &x, const Fraction &y){
        return x.a * y.b > y.a * x.b;
    }
    void Desc(void){
        this->Shrink();
        printf("%lld/%lld\n", (ll)this->a, (ll)this->b);
    }
};

int main(){
    int T = read();
    while(T--){
        int _K = read(), _N = read();
        int A = read(), B = read(), C = read(), D = read();
        Fraction L{A, B}, R{C, D}; L.Shrink(), R.Shrink();
        Fraction ans{-1, -1}, val{1, 114514};
        // int K = _K / __gcd(_K, _N), N = _N / __gcd(_K, _N);
        int K = _K, N = _N;
        for(int i = 1; i * i <= K; ++i){
            if(K % i)continue;
            auto Cal = [&](int a)->void{
                int t = int(ceil((double)a / ((double)R.a / R.b) / (double)N - EPS));
                if(t > int(floor((double)a / ((double)L.a / L.b) / (double)N + EPS)))return;
                Fraction X{a, (ll)t * N};
                if(L <= X && X <= R){
                    auto res = Fraction{(ll)K * t / a + 1, 1} * X;
                    if(res > val)val = res, ans = X;
                }
            };
            Cal(i), Cal(K / i);
        }

        Fraction res1 = Fraction{int(floor((double)_K / ((double)L.a / (double)L.b) / (double)_N + EPS)) + 1, 1} * L;
        if(res1 > val)val = res1, ans = L;
        Fraction res2 = Fraction{int(floor((double)_K / ((double)R.a / (double)R.b) / (double)_N + EPS)) + 1, 1} * R;
        if(res2 > val)val = res2, ans = R;

        // Fraction curX{K, (ll(floor((double)_K / ((double)R.a / (double)R.b) / (double)N + EPS)) + 1) * _N}; curX.Shrink();
        // if(L <= curX){
        //     Fraction res3 = curX * Fraction{int(floor((double)_K / ((double)curX.a / (double)curX.b) / (double)_N) + EPS) + 1, 1};
        //     if(res3 > val)val = res3, ans = curX;
        // }

        

        // ans.Desc();
        val.Desc();
    }


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