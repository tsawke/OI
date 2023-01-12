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

template < typename T = int >
inline T read(void);

int N;
int P[510];
ll dp[510][510][2];

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)P[i] = read(), dp[i][i][0] = 1;
    for(int len = 2; len <= N; ++len)
        for(int l = 1; l <= N - len + 1; ++l){
            int r = l + len - 1;
            (dp[l][r][0] += dp[l + 1][r][0] + dp[l + 1][r][1]) %= MOD;
            for(int sp = l; sp <= r - 1; ++sp)
                if(P[l] < P[sp + 1])
                    (dp[l][r][1] += dp[l][sp][0] * (dp[sp + 1][r][0] + dp[sp + 1][r][1]) % MOD) %= MOD;
        }
    printf("%lld\n", dp[1][N][0]);
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