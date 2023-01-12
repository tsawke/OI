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
#define A(x, y) (a.val[x][y])
#define B(x, y) (b.val[x][y])

template < typename T = int >
inline T read(void);

ll ans(0);
ll N, D;
ll fact[11000], inv[11000];

class Matrix2{
private:
public:
    ll val[2][2];
    Matrix2(void) = default;
    Matrix2(ll v11, ll v12, ll v21, ll v22){
        val[0][0] = v11, val[0][1] = v12, val[1][0] = v21, val[1][1] = v22;
    }
    friend const Matrix2 operator * (const Matrix2 &a, const Matrix2 &b){
        return Matrix2(
            (A(0, 0) * B(0, 0) % MOD + A(0, 1) * B(1, 0) % MOD) % MOD,
            (A(0, 0) * B(0, 1) % MOD + A(0, 1) * B(1, 1) % MOD) % MOD,
            (A(1, 0) * B(0, 0) % MOD + A(1, 1) * B(1, 0) % MOD) % MOD,
            (A(1, 0) * B(0, 1) % MOD + A(1, 1) * B(1, 1) % MOD) % MOD
        );
    }
    friend const Matrix2 operator ^ (const Matrix2 &a, ll b){
        Matrix2 ret(1, 0, 0, 1), mul(a);
        while(b){
            if(b & 1)ret = ret * mul;
            b >>= 1;
            mul = mul * mul;
        }return ret;
    }
}G;

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}
void Init(void){
    fact[0] = 1;
    for(int i = 1; i <= 10100; ++i)fact[i] = fact[i - 1] * i % MOD;
    inv[10100] = qpow(fact[10100], MOD - 2);
    for(int i = 10099; i >= 0; --i)inv[i] = inv[i + 1] * (i + 1) % MOD;
}
ll GetC(int n, int m){
    if(m > n || n < 0 || m < 0)return 0;
    return fact[n] * inv[m] % MOD * inv[n - m] % MOD;
}

int main(){Init();
    N = read < ll >(), D = read();
    for(int k = 0; k <= D + 1; ++k){
        G = Matrix2(GetC(D - 1, k - 2), GetC(D - 1, k - 1), GetC(D - 1, k - 1), GetC(D - 1, k));
        auto ret = G ^ N;
        (ans += ret.val[0][0] + ret.val[1][1]) %= MOD;
        // printf("val: %lld, %lld, %lld, %lld\n", G.val[0][0], G.val[0][1], G.val[1][0], G.val[1][1]);
    }
    printf("%lld\n", ans);
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