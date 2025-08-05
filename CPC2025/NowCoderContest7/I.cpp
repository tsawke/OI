#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E  M_E

using namespace std;

mt19937_64 rnd(random_device{}());
int rndd(int l, int r){ return rnd() % (r - l + 1) + l; }

typedef unsigned int        uint;
typedef unsigned long long  unll;
typedef long long           ll;
using ull = unsigned long long;

template<typename T = int>
inline T read(void);

const ll MOD = 998244353ll;
const int DIM = 18;

ll qpow(ll a, ll b = MOD - 2){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

struct Mat {
    ll a[DIM][DIM]{};
    static Mat eye() { Mat I; for (int i = 0; i < DIM; ++i) I.a[i][i] = 1; return I; }
};
Mat operator*(const Mat& A, const Mat& B) {
    Mat C;
    for (int i = 0; i < DIM; ++i)
        for (int k = 0; k < DIM; ++k) if (A.a[i][k])
            for (int j = 0; j < DIM; ++j)
                C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % MOD;
    return C;
}
Mat mpow(Mat base, unsigned long long e) {
    Mat res = Mat::eye();
    while (e) {
        if (e & 1) res = base * res;
        base = base * base;
        e >>= 1;
    }
    return res;
}

int main() {
    const ll inv5 = qpow(5);
    int T = read();
    while (T--){
        ll N = read < ll >(), K = read < ll >();
        vector<int> D(K); for (int &x: D)x = read();
        ll invk = qpow(K);
        ll m = 0; for (int d: D) m = (m + d) % MOD;
        m = m * invk % MOD;
        ll low[16]{}, AvAnd[16]{}, AvOr[16]{}, AvXor[16]{};
        for (int a = 0; a < 16; ++a) {
            low[a] = a;
            ll s_and = 0, s_or = 0, s_xor = 0;
            for (int d: D) {
                s_and += (a & d);
                s_or += (a | d);
                s_xor += (a ^ d);
            }
            AvAnd[a] = s_and % MOD * invk % MOD;
            AvOr[a] = s_or % MOD * invk % MOD;
            AvXor[a] = s_xor % MOD * invk % MOD;
        }
        ll inv5k = inv5 * invk % MOD;
        ll T16[16][16]{};
        for (int a = 0; a < 16; ++a)
            for (int d: D) {
                T16[a][(a + d) & 15] = (T16[a][(a + d) & 15] + inv5k) % MOD;
                T16[a][(a * d) & 15] = (T16[a][(a * d) & 15] + inv5k) % MOD;
                T16[a][(a & d)] = (T16[a][(a & d)] + inv5k) % MOD;
                T16[a][(a | d)] = (T16[a][(a | d)] + inv5k) % MOD;
                T16[a][(a ^ d)] = (T16[a][(a ^ d)] + inv5k) % MOD;
            }
        Mat M;
        ll alpha = (3 + m) % MOD * inv5 % MOD;
        ll gamma = m * inv5 % MOD;
        ll beta[16];
        for (int a = 0; a < 16; ++a) {
            ll t = (AvAnd[a] + AvOr[a] + AvXor[a] - 2 * low[a]) % MOD;
            if (t < 0) t += MOD;
            beta[a] = t * inv5 % MOD;
        }
        M.a[0][0] = alpha;
        for (int a = 0; a < 16; ++a) M.a[0][1 + a] = beta[a];
        M.a[0][17] = gamma;
        for (int a = 0; a < 16; ++a)
            for (int b = 0; b < 16; ++b)
                M.a[1 + b][1 + a] = T16[a][b];
        M.a[17][17] = 1;
        ll w0[DIM]{};
        w0[0] = m;
        for (int d: D) w0[1 + (d & 15)] = (w0[1 + (d & 15)] + invk) % MOD;
        w0[17] = 1;
        ll ans;
        if (N == 1) ans = w0[0];
        else {
            Mat P = mpow(M, N - 1);
            ll res0 = 0;
            for (int j = 0; j < DIM; ++j)
                res0 = (res0 + P.a[0][j] * w0[j]) % MOD;
            ans = res0;
        }
        cout << ans << '\n';
    }
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