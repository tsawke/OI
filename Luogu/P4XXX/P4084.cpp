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

#define MOD (int)(1e9 + 7)

template< typename T = int >
inline T read(void);

int N, K;
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[210000];
ROPNEW(ed);
Edge* head[110000];
int dp[110000][4];

void dfs(int p = 1, int fa = 0){
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs(SON, p);
        dp[p][1] = ((ll)dp[p][1] * ((ll)dp[SON][2] + dp[SON][3])) % MOD;
        dp[p][2] = ((ll)dp[p][2] * ((ll)dp[SON][1] + dp[SON][3])) % MOD;
        dp[p][3] = ((ll)dp[p][3] * ((ll)dp[SON][1] + dp[SON][2])) % MOD;
    }
}

int main(){
    N = read(), K = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= 3; ++j)dp[i][j] = 1;
    for(int i = 1; i <= K; ++i){
        int p = read(), c = read();
        for(int j = 1; j <= 3; ++j)if(j != c)dp[p][j] = 0;
    }dfs();
    printf("%lld\n", ((ll)dp[1][1] + dp[1][2] + dp[1][3]) % MOD);
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