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

int N, D;
int P[110], Q[110];
ll dp[2100][1100];
ll sum[2100][1100];
ll sum2[2100][1100];
ll ans(0);

int main(){
    N = read(), D = read();
    for(int i = 1; i <= N; ++i)P[i] = read();
    for(int i = 1; i <= N; ++i)Q[i] = read();
    dp[0][0] = 1;
    for(int j = 0; j <= D * 2; ++j)
        for(int k = 0; k <= D; ++k)
            sum[j][k] = ((k - 1 >= 0 ? sum[j][k - 1] : 0) + dp[j][k]) % MOD,
            sum2[j][k] = ((j - 2 >= 0 && k - 1 >= 0 ? sum2[j - 2][k - 1] : 0) + dp[j][k]) % MOD;
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j <= D * 2; ++j)
            for(int k = 0; k <= D; ++k){
                int dis = abs(P[i] - Q[i]);
                dp[j][k] = j >= dis
                    ?
                        ((sum[j - dis][k] - (k - dis - 1 >= 0 ? sum[j - dis][k - dis - 1] : 0) + MOD) % MOD +
                        (j - dis - 2 >= 0 && k - 1 >= 0 ? sum2[j - dis - 2][k - 1] % MOD : 0) +
                        (j - dis - 2 >= 0 && k - dis - 1 >= 0 ? sum2[j - dis - 2][k - dis - 1] % MOD : 0)) % MOD
                    : 0;
            }
        memset(sum, 0, sizeof sum), memset(sum2, 0, sizeof sum2);
        for(int j = 0; j <= D * 2; ++j)
            for(int k = 0; k <= D; ++k)
                sum[j][k] = ((k - 1 >= 0 ? sum[j][k - 1] : 0) + dp[j][k]) % MOD,
                sum2[j][k] = ((j - 2 >= 0 && k - 1 >= 0 ? sum2[j - 2][k - 1] : 0) + dp[j][k]) % MOD;
    }
    for(int j = 0; j <= D * 2; ++j)for(int k = 0; k <= min(j, D); ++k)
        if(j - k <= D) (ans += dp[j][k]) %= MOD;
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