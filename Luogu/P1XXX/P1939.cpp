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

#define MOD (ll)(1e9 + 7)

template < typename T = int >
inline T read(void);

class Matrix3{
private:
public:
    ll v[3][3];
    Matrix3(void){memset(v, 0, sizeof v);}
    friend Matrix3 operator * (const Matrix3 &a, const Matrix3 &b){
        Matrix3 ret;
        for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)for(int k = 0; k <= 2; ++k)
            (ret.v[i][j] += a.v[i][k] * b.v[k][j] % MOD) %= MOD;
        return ret;
    }
    void Print(void){
        for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)
            printf("%lld%c", v[i][j], j == 2 ? '\n' : ' ');
    }
};
Matrix3 qpow(Matrix3 a, ll b){
    Matrix3 ret, mul(a);
    for(int i = 0; i <= 2; ++i)ret.v[i][i] = 1;
    while(b){
        if(b & 1)ret = ret * mul;
        b >>= 1;
        mul = mul * mul;
    }return ret;
}

int main(){
    Matrix3 base;
    ll tmp[3][3] = {{1, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    copy(tmp, tmp + 9, base.v);
    base.Print();

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