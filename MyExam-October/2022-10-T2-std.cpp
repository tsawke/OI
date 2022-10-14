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

#define MAXN 110000
#define MAX_TIME (double)(3.5)
#define CURRENT_TIME ((double)clock() / CLOCKS_PER_SEC)

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    ll val;
    OPNEW;
}ed[MAXN * 6];
ROPNEW(ed);

int N;
Edge* head[4][MAXN];
ll dis[4][MAXN];
bool vis[4][MAXN];
bool used[MAXN];
ll ans(-1);

void dfs(int p, int ver, int fa = -1){
    for(auto i = head[ver][p]; i; i = i->nxt){
        if(SON == fa)continue;
        dis[ver][SON] = dis[ver][p] + i->val;
        dfs(SON, ver, p);
    }
}
void Luangao(int f1, int f2, int f3){
    int rt = rndd(1, N);
    while(used[rt] && CURRENT_TIME < MAX_TIME)rt = rndd(1, N);
    int T = 10;
    while(T--){
        if(used[rt])break;
        used[rt] = true;
        for(int i = 1; i <= 3; ++i)dis[i][rt] = 0, dfs(rt, i);
        ll mx(0);
        for(int i = 1; i <= N; ++i){
            ans = max(dis[1][i] + dis[2][i] + dis[3][i], ans);
            if(!used[i] && dis[1][i] * f1 + dis[2][i] * f2 + dis[3][i] * f3 > mx)
                mx = dis[1][i] * f1 + dis[2][i] * f2 + dis[3][i] * f3, rt = i;
        }
    }
}
signed main(){
    freopen("escape_from_llq.in", "r", stdin);
    freopen("escape_from_llq.out", "w", stdout);
    N = read();
    for(int i = 1; i <= 3; ++i)
        for(int j = 1; j <= N - 1; ++j){
            int s = read(), t = read(); ll v = read<ll>();
            head[i][s] = new Edge{head[i][s], t, v};
            head[i][t] = new Edge{head[i][t], s, v};
        }
    for(int i = 1; i <= 10 && CURRENT_TIME < MAX_TIME; ++i)Luangao(1, 1, 1);
    for(int i = 0; i <= 1; ++i)for(int j = 0; j <= 1; ++j)for(int k = 0; k <= 1; ++k)
        if(CURRENT_TIME < MAX_TIME)Luangao(i, j, k);
    
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