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

template < typename T = int >
inline T read(void);

ll K, MOD;
ll pow10[51000000];
ll sum(1);
ll ans(LONG_LONG_MAX);
const ll mxCnt = (ll)(1e8 + 114514);

int main(){
    freopen("date_struct.in", "r", stdin);
    freopen("date_struct.out", "w", stdout);
    K = read < ll >(), MOD = read < ll >();
    ll lim = mxCnt / (MOD - 1);
    pow10[0] = 1;
    for(int i = 1; i <= MOD - 2; ++i)pow10[i] = pow10[i - 1] * 10 % MOD, (sum += pow10[i]) %= MOD;
    ll cur(0);
    for(int i = 0; i <= MOD - 2; ++i){
        (cur += pow10[i]) %= MOD;
        if(cur == K)printf("%d\n", i + 1), exit(0);
    }cur = 0;
    for(int i = 0; i <= MOD - 2; ++i){
        (cur += pow10[i]) %= MOD;
        for(int j = 1; j <= lim; ++j)
            if((cur + sum * j % MOD) % MOD == K)ans = min(ans, (ll)i + 1 + (MOD - 1) * j);
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