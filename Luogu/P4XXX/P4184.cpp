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

#define MOD (ll)(1e9 + 7)
#define GetSum1(x) ((x) > 0 ? sum1[x] : 0)
#define GetSum2(x) ((x) > 0 ? sum2[x] : 0)

template< typename T = int >
inline T read(void);

int N;
int y[110000];
int l[110000], r[110000], up[110000];
ll sum1[110000];
ll sum2[110000];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        int rx = read() + 1, ry = read() + 1;
        y[rx] = ry;
    }l[0] = INT_MAX; r[N + 1] = -1;
    for(int i = 1; i <= N; ++i)l[i] = min(l[i - 1], y[i]);
    for(int i = N; i >= 1; --i)r[i] = max(r[i + 1], y[i]);
    int cur = r[1];
    for(int i = 1; i <= N; ++i)while(cur && cur >= l[i])up[cur] = i, --cur;
    for(int i = 1; i <= N; ++i)sum1[i] = (sum1[i - 1] + up[i]) % MOD;
    for(int i = 1; i <= N; ++i)sum2[i] = (sum2[i - 1] + sum1[i]) % MOD;
    ll ans(0);
    for(int i = 1; i <= N; ++i){
        ans = (ans + ((ll)r[i] - l[i]) * (r[i] - l[i] + 1) / 2ll % MOD * i % MOD) % MOD;
        ans = (ans - GetSum2(r[i] - 1) + GetSum2(l[i] - 2) + MOD) % MOD;
        ans = (ans + ((ll)r[i] - l[i] + 1) * GetSum1(l[i] - 1) % MOD) % MOD;
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