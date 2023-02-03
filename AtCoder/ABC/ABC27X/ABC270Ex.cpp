#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

struct Matrix2{
    ll v00, v01, v10, v11;
    friend Matrix2 operator * (const Matrix2 &a, const Matrix2 &b){
        return Matrix2{
            (a.v00 * b.v00 % MOD + a.v01 * b.v10 % MOD) % MOD,
            (a.v00 * b.v01 % MOD + a.v01 * b.v11 % MOD) % MOD,
            (a.v10 * b.v00 % MOD + a.v11 * b.v10 % MOD) % MOD,
            (a.v10 * b.v01 % MOD + a.v11 * b.v11 % MOD) % MOD
        };
    }
};
Matrix2 base{1, 0, 0, 1};

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
ll inv(ll v){return qpow(v, MOD - 2);}
Matrix2 qpow(Matrix2 a, ll b){
    Matrix2 ret(base), mul(a);
    while(b){
        if(b & 1)ret = ret * mul;
        b >>= 1;
        mul = mul * mul;
    }return ret;
}

int N;
ll A[210000];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)A[i] = read < ll >();
    Matrix2 ans{0, 1, 0, 0};
    ll cur(0);
    for(int i = N - 1; i >= 1; --i){
        ll B = N * inv(i) % MOD, C = (N - cur) * inv(i) % MOD;
        ans = ans * qpow(Matrix2{B, 0, C, 1}, A[i + 1] - A[i]);
        (cur += ans.v00) %= MOD;
    }printf("%lld\n", (ans.v00 % MOD + MOD) % MOD);
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