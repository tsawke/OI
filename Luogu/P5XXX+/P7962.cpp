#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

/******************************
abbr

******************************/

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template<typename T = int>
inline T read(void);

int N;
int cnt0(0);
int a[11000];
int d[11000], s[11000];
int dp[2][6100000];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    for(int i = 1; i < N; ++i)d[i] = a[i + 1] - a[i];
    sort(d + 1, d + N);
    for(int i = 1; i < N; ++i)if(!d[i])++cnt0;
    for(int i = 1; i < N; ++i)s[i] = s[i - 1] + d[i];
    // for(int i = 0; i <= N; ++i)
        // for(int j = 0; j <= s[i] * i; ++j)
        //     dp[j] = 0x3f3f3f3f;
    // dp[0][0] = 0;
    #define LASTI ((i & 1) ^ 1)
    for(int i = 1; i <= a[N] * N; ++i)dp[cnt0 & 1][i] = 0x3f3f3f3f;
    for(int i = cnt0 + 1; i <= N - 1; ++i){
        for(int S = 0; S <= a[N] * N; ++S)dp[i & 1][S] = 0x3f3f3f3f;
        for(int S = 0; S <= a[N] * N; ++S){
            if(dp[LASTI][S] >= 0x3f3f3f3f)continue;
            dp[i & 1][S + i * d[i]] = min(dp[i & 1][S + i * d[i]], dp[LASTI][S] + 2 * S * d[i] + i * d[i] * d[i]);
            dp[i & 1][S + s[i]] = min(dp[i & 1][S + s[i]], dp[LASTI][S] + s[i] * s[i]);
        }
    }
    ll ans = LONG_LONG_MAX;
    for(int S = 0; S <= a[N] * N; ++S)
        ans = min(ans, (ll)N * dp[((N & 1) ^ 1)][S] - (ll)S * S);
    printf("%lld\n", ans);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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