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

#define int ll
#define INF (ll)(1e16)

template<typename T = int>
inline T read(void);

int dis[110][110];
int G[110][110];
int ans(LLONG_MAX);
signed main(){
    // memset(dis, 0x3f, sizeof(dis));
    int N = read(), M = read();
    for(int i = 1; i <= N; ++i)for(int j = 1; j <= N; ++j)dis[i][j] = INF;
    for(int i = 1; i <= N; ++i)dis[i][i] = 0;
    for(int i = 1; i <= M; ++i){
        int f = read(), t = read(), v = read();
        dis[f][t] = dis[t][f] = min(dis[f][t], v);
    }
    memcpy(G, dis, sizeof(dis));
    for(int k = 1; k <= N; ++k){
        for(int i = 1; i <= k - 1; ++i)
            for(int j = i + 1; j <= k - 1; ++j)
                ans = min(ans, dis[i][j] + G[i][k] + G[j][k]);
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    if(ans >= INF)printf("No solution.\n");
    else printf("%lld\n", ans);
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