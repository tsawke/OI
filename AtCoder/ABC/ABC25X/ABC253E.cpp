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

#define MOD (ll)(998244353ll)

template < typename T = int >
inline T read(void);

int N, M, K;
ll dp[1100][5100];
ll sum[5100];

int main(){
    N = read(), M = read(), K = read();
    for(int i = 1; i <= M; ++i)dp[1][i] = 1, sum[i] = i;
    for(int i = 2; i <= N; ++i){
        for(int j = 1; j <= M; ++j){
            (dp[i][j] += j + K <= M ? (sum[M] - sum[j + K - 1] + MOD) % MOD : 0) %= MOD;
            (dp[i][j] += j - K >= 1 ? sum[j - K] : 0) %= MOD;
            if(!K)(dp[i][j] += -(sum[j] - sum[j - 1]) + MOD) %= MOD;
        }
        for(int j = 1; j <= M; ++j)
            sum[j] = (sum[j - 1] + dp[i][j]) % MOD;
    }printf("%lld\n", sum[M]);
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