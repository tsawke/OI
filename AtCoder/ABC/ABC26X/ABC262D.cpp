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
ll a[110];
ll dp[2][110][110][110];
ll ans(0);

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    for(int i = 1; i <= N; ++i)dp[1][0][i][0] = 1, dp[1][1][i][a[1] % i] = 1;
    for(int i = 1; i < N; ++i){
        for(int j = 0; j <= 100; ++j)for(int p = 0; p <= 100; ++p)for(int k = 0; k <= 100; ++k)dp[!(i & 1)][j][p][k] = 0;
        for(int j = 0; j <= i; ++j)
            for(int p = 1; p <= N; ++p)
                for(int k = 0; k < p; ++k)
                    (dp[!(i & 1)][j][p][k] += dp[i & 1][j][p][k]) %= MOD,
                    (dp[!(i & 1)][j + 1][p][(k + a[i + 1]) % p] += dp[i & 1][j][p][k]) %= MOD;
    }
    for(int i = 1; i <= N; ++i)(ans += dp[N & 1][i][i][0]) %= MOD;
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