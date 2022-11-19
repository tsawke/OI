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

#define int ll

template< typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[210000];
ROPNEW(ed);
Edge* head[110000];

int N;
int val[110000];
int dp[110000];
int sumc[110000];
int mn(LONG_LONG_MAX);

void dfs_pre(int p = 1, int fa = 0){
    sumc[p] += val[p];
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_pre(SON, p);
        dp[1] += sumc[SON] * i->val;
        sumc[p] += sumc[SON];
    }
}
void dfs(int p = 1, int fa = 0){
    mn = min(mn, dp[p]);
    // printf("p = %d, dp = %d\n", p, dp[p]);
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dp[SON] = dp[p] + (sumc[1] - sumc[SON]) * i->val - sumc[SON] * i->val;
        dfs(SON, p);
    }
}

signed main(){
    // freopen("P2986_7.in", "r", stdin);
    N = read();
    for(int i = 1; i <= N; ++i)val[i] = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v};
        head[t] = new Edge{head[t], s, v};
    }dfs_pre(); dfs();
    printf("%lld\n", mn);
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