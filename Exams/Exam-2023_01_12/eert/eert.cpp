#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;



template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[21000];
ROPNEW;
Edge* head[11000];

int N, M;
int cnt(0);
int dep[11000];
ll ans[11000];
struct Query{short p; int idx;};
basic_string < Query > qs[11000];
bitset < 11000 > vis;
int lca[110000000];
struct Q{int l, r, z;}q[11000];

class UnionFind{
private:
    int fa[11000];
public:
    UnionFind(void){for(int i = 1; i <= 10000; ++i)fa[i] = i;}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int x, int y){fa[Find(y)] = Find(x);}
}uf;

void dfs(int p = 1, int fa = 0){
    dep[p] = dep[fa] + 1;
    for(auto i = head[p]; i; i = i->nxt)if(SON != fa)dfs(SON, p);
}
void Tarjan(int p = 1, int fa = 0){
    vis[p] = true;
    for(auto i = head[p]; i; i = i->nxt)if(SON != fa)Tarjan(SON, p), uf.Union(p, SON);
    for(auto q : qs[p])if(vis[q.p])lca[q.idx] = uf.Find(q.p);
}

int main(){
    freopen("eert.in", "r", stdin);
    freopen("eert.out", "w", stdout);
    N = read(), M = read();
    for(int i = 2; i <= N; ++i){
        int s = i, t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs();
    for(int i = 1; i <= M; ++i){
        q[i].l = read(), q[i].r = read(), q[i].z = read();
        for(int p = q[i].l; p <= q[i].r; ++p)qs[q[i].z] += Query{(short)p, ++cnt}, qs[p] += Query{(short)q[i].z, cnt};
    }Tarjan();
    int cur(0);
    for(int i = 1; i <= M; ++i){
        for(int ccnt = cur + 1; ccnt <= cur + (q[i].r - q[i].l + 1); ++ccnt)ans[i] += dep[lca[ccnt]];
        cur += (q[i].r - q[i].l + 1);
    }
    for(int i = 1; i <= M; ++i)printf("%lld\n", ans[i]);
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