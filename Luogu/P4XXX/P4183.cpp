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

template< typename T = int >
inline T read(void);

int N;
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[210000];
ROPNEW(ed);
Edge* head[110000];

int ans[110000];
bool vis[110000];
int deg[110000], dep[110000], dleaf[110000];

void dfs_pre(int p = 1, int fa = 0){
    if(deg[p] == 1)dleaf[p] = 0;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_pre(SON, p);
        dleaf[p] = min(dleaf[p], dleaf[SON] + 1);
    }
}
void dfs_pre_from_root(int p = 1, int fa = 0){
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dleaf[SON] = min(dleaf[SON], dleaf[p] + 1);
        dfs_pre_from_root(SON, p);
    }
}

int mx[110000];
int siz[110000];
int rt(0);
void ResetRoot(void){rt = 0, mx[rt] = N;}
void dfs_rt(int p = 1, int fa = 0, int Siz = N){
    siz[p] = 1; mx[p] = 0;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa || vis[SON])continue;
        dfs_rt(SON, p, Siz);
        siz[p] += siz[SON];
        mx[p] = max(mx[p], siz[SON]);
    }mx[p] = max(mx[p], Siz - siz[p]);
    if(mx[p] < mx[rt])rt = p;
}

struct Status{
    int dep, val;
    friend const bool operator < (const Status &a, const Status &b){return a.dep < b.dep;}
}idx[110000], nod[110000];
int cnt(0);
void dfs_dep(int p, int fa, int cur = 0){
    dep[p] = cur;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa || vis[SON])continue;
        dfs_dep(SON, p, cur + 1);
    }
}
void dfs_upd(int p, int fa){
    idx[++cnt] = Status{dep[p], p},
    nod[cnt] = Status{dleaf[p] - dep[p], 2 - deg[p]};
    for(auto i = head[p]; i; i = i->nxt)if(SON != fa && !vis[SON])dfs_upd(SON, p);
}

void Cal(int p, int fa, int flag){
    cnt = 0;
    dfs_upd(p, fa);
    sort(idx + 1, idx + cnt + 1), sort(nod + 1, nod + cnt + 1);
    int sum(0), sp(0);
    for(int i = 1; i <= cnt; ++i){
        while(sp <= cnt - 1 && nod[sp + 1].dep <= idx[i].dep)sum += nod[++sp].val;
        ans[idx[i].val] += flag * sum;
    }
}
void Make(int p){
    vis[p] = true;
    dfs_dep(p, 0);
    Cal(p, 0, 1);
    for(auto i = head[p]; i; i = i->nxt){
        if(vis[SON])continue;
        Cal(SON, p, -1);
        ResetRoot();
        dfs_rt(SON, p, siz[SON]);
        Make(rt);
    }
}

int main(){
	// freopen("P4183_3.in", "r", stdin);
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
        ++deg[s], ++deg[t];
    }memset(dleaf, 0x3f, sizeof(dleaf));
    dfs_pre(); dfs_pre_from_root();
    ResetRoot(); dfs_rt(); /*dfs_rt(rt);*/ Make(rt);
    for(int i = 1; i <= N; ++i)printf("%d\n", deg[i] == 1 ? 1 : ans[i]);
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