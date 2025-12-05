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

template< typename T = int >
inline T read(void);

int N; int MOD;
int dp[3100][3100][2];

int main(){
    N = read(), MOD = read();
    dp[1][0][1] = dp[1][1][0] = 1;
    for(int i = 1; i <= N - 1; ++i)
        for(int j = 0; j <= N - 1; ++j)
            dp[i + 1][j + 1][0] = ((ll)dp[i + 1][j + 1][0] + dp[i][j][0]) % MOD,
            dp[i + 1][j][1] = ((ll)dp[i + 1][j][1] + dp[i][j][0]) % MOD,
            dp[i + 1][j + 1][1] = ((ll)dp[i + 1][j + 1][1] + dp[i][j][1] * 2ll) % MOD,
            dp[i + 1][j][1] = ((ll)dp[i + 1][j][1] + dp[i][j][1]) % MOD,
            dp[i + 1][j + 2][0] = ((ll)dp[i + 1][j + 2][0] + dp[i][j][1] * 2ll) % MOD,
            dp[i + 1][j + 1][1] = ((ll)dp[i + 1][j + 1][1] + dp[i][j][1]) % MOD;
    for(int i = 1; i <= N - 1; ++i)printf("%d%c", dp[N][i][1], i == N - 1 ? '\n' : ' ');
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