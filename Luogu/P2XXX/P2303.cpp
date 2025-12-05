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

#define MOD (ll)(LONG_LONG_MAX)

template< typename T = int >
inline T read(void);

ll N;
int tot(0);
pair < ll, int > fact[1100000];
int cur[1100000];
__int128_t ans(0);

__int128_t qpow(ll a, ll b){
    __int128_t ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

void dfs(int p = 1, ll base = 1, __int128_t phi = 1, __int128_t div = 1){
    if(p > tot){
        phi *= base, phi /= div, phi %= MOD;
        ans = (ans + phi * N / base/*(qpow(2, N / base)*/ % MOD) % MOD;
        return;
    }
    dfs(p + 1, base, phi, div);
    phi *= fact[p].first - 1;
    div *= fact[p].first;
    for(int i = 1; i <= fact[p].second; ++i)
        base *= fact[p].first, dfs(p + 1, base, phi, div);
}

int main(){
    N = read < ll >();
    ll tmp(N); ll cur(2), cnt(0);
    while(tmp > 1){
        if(cur * cur > tmp)break;
        while(tmp % cur == 0)tmp /= cur, ++cnt;
        if(cnt)fact[++tot] = {cur, cnt}, cnt = 0;
        ++cur;
    }if(tmp > 1)fact[++tot] = {tmp, 1};
    dfs();
    // ans = ((((ans + 2 - N) % MOD) - qpow(2, N)) % MOD + MOD) % MOD;
    printf("%lld\n", (ll)ans);
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