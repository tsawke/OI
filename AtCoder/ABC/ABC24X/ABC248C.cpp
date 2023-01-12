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

#define MOD (ll)(998244353)

template< typename T = int >
inline T read(void);

int N, M, K;
ll dp[60][3000];

int main(){
    N = read(), M = read(), K = read();
    dp[0][0] = 1;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= K; ++j)
            for(int lst = 1; lst <= M; ++lst)
                if(j - lst >= 0)
                    (dp[i][j] += dp[i - 1][j - lst]) %= MOD;
    ll ans(0);
    for(int i = 0; i <= K; ++i)(ans += dp[N][i]) %= MOD;
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