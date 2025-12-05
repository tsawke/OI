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

template < typename T = int >
inline T read(void);

int N;
ll S;
ll P[110000];

class Matrix3{
private:
public:
    ll v[3][3];
    Matrix3(ll v11 = 0, ll v12 = 0, ll v13 = 0, ll v21 = 0, ll v22 = 0, ll v23 = 0, ll v31 = 0, ll v32 = 0, ll v33 = 0){
        v[0][0] = v11, v[0][1] = v12, v[0][2] = v13,
        v[1][0] = v21, v[1][1] = v22, v[1][2] = v23,
        v[2][0] = v31, v[2][1] = v32, v[2][2] = v33;
    }
    friend const Matrix3 operator * (const Matrix3 &a, const Matrix3 &b){
        Matrix3 ret;
        for(int i = 0; i <= 2; ++i)for(int j = 0; j <= 2; ++j)for(int k = 0; k <= 2; ++k)
            (ret.v[i][j] += a.v[i][k] * b.v[k][j] % MOD) %= MOD;
        return ret;
    }
    friend const Matrix3 operator ^ (const Matrix3 &a, ll b){
        Matrix3 ret(1, 0, 0, 0, 1, 0, 0, 0, 1), mul(a);
        while(b){
            if(b & 1)ret = ret * mul;
            b >>= 1;
            mul = mul * mul;
        }return ret;
    }
};

int main(){
    N = read(), S = read < ll >();
    for(int i = 1; i <= N; ++i)P[i] = read < ll >();
    Matrix3 base(1, 1, 0, 0, 0, 1, 1, 1, 0);
    Matrix3 ans(1, 0, 0);
    for(int i = 1; i <= N; ++i)ans = ans * (base ^ (P[i] - P[i - 1])), ans.v[0][0] = 0;
    ans = ans * (base ^ (S - P[N]));
    printf("%lld\n", ans.v[0][0]);
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