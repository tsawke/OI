#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD 998244353
#define int ll

template< typename T = int >
inline T read(void);

int N, K;
ll a[1100000];
ll sum[1100000];
ll sumsq[1100000];
ll ans(0);

signed main(){
    N = read(), K = read();
    int sp(0);
    for(int i = 1; i <= N; ++i)
        a[i] = read(),
        sum[i] = (sum[i - 1] + a[i] + MOD) % MOD,
        sumsq[i] = (sumsq[i - 1] + a[i] * a[i] % MOD) % MOD,
        sp = a[i] < 0 ? i : sp;
    for(int k = 1; k <= K; ++k){
        while(sp && abs(a[sp] + 1) < abs(a[sp] + k))--sp;
        ans = (
            ans +
            (sumsq[N] +
                (
                    2ll * sum[sp] % MOD +
                    (sp +
                    (2 * k % MOD * ((sum[N] - sum[sp] + MOD) % MOD)) % MOD +
                    (N - sp) * k % MOD * k % MOD
                    ) % MOD
                ) % MOD
            )
        ) % MOD;
    }printf("%lld\n", ans);

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}



template < typename T >
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