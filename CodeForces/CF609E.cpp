#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
// using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MAXNM (210000)

template< typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    ll val;
    OPNEW;
}ed[410000];
ROPNEW(ed);
Edge* head[MAXNM];
ll val[210000];

class UnionFind{
private:
    int fa[MAXNM];
public:
    UnionFind(void){for(int i = 1; i <= 201000; ++i)fa[i] = i;}
    int Find(int x){return fa[x] == x ? x : fa[x] = Find(fa[x]);}
    void Union(int origin, int son){fa[Find(son)] = Find(origin);}
}uf;

int N, M;
bool intree[MAXNM];
ll ans[MAXNM];
ll origin(0);
struct Edges{
    int val;
    int s, t;
    int idx;
    friend const bool operator < (const Edges &a, const Edges &b){return a.val < b.val;}
};
vector < Edges > edges;
tuple < int, int, int > qs[210000];

int dfn[MAXNM], fa[MAXNM], hson[MAXNM], siz[MAXNM], dep[MAXNM], top[MAXNM], idx[MAXNM];

void dfs_edge_to_vertex(int p = 1, int ffa = 0){
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != ffa)val[SON] = i->val, dfs_edge_to_vertex(SON, p);
}

void dfs_pre(int p = 1, int ffa = 0){
    // printf("pre : %d\n", p);
    fa[p] = ffa;
    siz[p] = 1;
    dep[p] = dep[ffa] + 1;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == ffa)continue;
        dfs_pre(SON, p);
        siz[p] += siz[SON];
        if(!hson[p] || siz[SON] > siz[hson[p]])hson[p] = SON;
    }
}
void dfs(int p = 1, int tp = 1){
    // printf("dfs: %d, %d\n", p, tp);
    static int curdfn(0);
    dfn[p] = ++curdfn;
    idx[curdfn] = p;
    top[p] = tp;
    if(hson[p])dfs(hson[p], tp);
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa[p] && SON != hson[p])dfs(SON, SON);
}

class SegTree{
private:
    ll tr[MAXNM << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){tr[p] = max(tr[LS], tr[RS]);}
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = val[idx[gl = gr]], void();
        Build(LS, gl, MID);
        Build(RS, MID + 1, gr);
        Pushup(p);
    }
    ll QueryMax(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l > r || !l || !r)return -1;
        // printf("Querying l = %d, t = %d, p = %d, gl = %d, gr = %d\n", l, r, p, gl, gr);
        if(l <= gl && gr <= r)return tr[p];
        return max(
            l <= MID ? QueryMax(l, r, LS, gl, MID) : -1,
            MID + 1 <= r ? QueryMax(l, r, RS, MID + 1, gr) : -1
        );
    }
}st;

ll QueryMax(int s, int t){
    ll ret(0);
    while(top[s] != top[t]){
        if(dep[top[s]] < dep[top[t]])swap(s, t);
        ret = max(ret, st.QueryMax(dfn[top[s]], dfn[s]));
        // printf("s = %d, t = %d, tps = %d, dfntp = %d, dfn = %d Max:%lld\n", s, t, top[s], dfn[top[s]], dfn[s], st.QueryMax(dfn[top[s]], dfn[s]));
        s = fa[top[s]];
    }if(dep[s] < dep[t])swap(s, t);
    return max(ret, st.QueryMax(dfn[hson[t]], dfn[s]));
}

int main(){
    // freopen("tree.in", "r", stdin);
    // freopen("tree.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        edges.emplace_back(Edges{v, s, t, i});
        qs[i] = {s, t, v};
    }sort(edges.begin(), edges.end());
    for(auto e : edges)
        if(uf.Find(e.s) != uf.Find(e.t))
            uf.Union(e.s, e.t),
            head[e.s] = new Edge{head[e.s], e.t, e.val},
            head[e.t] = new Edge{head[e.t], e.s, e.val},
            intree[e.idx] = true,
            origin += e.val;
    dfs_edge_to_vertex();
    dfs_pre();
    dfs();//dfn[0] = 1;
    st.Build();
    // printf("%d\n", st.QueryMax(5, 5));
    for(int i = 1; i <= M; ++i){
        if(intree[i]){ans[i] = origin; continue;}
        int s, t, v; tie(s, t, v) = qs[i];
        // printf("Edge:%d, %d->%d max = %lld\n", i, s, t, QueryMax(s, t));
        ans[i] = origin - QueryMax(s, t) + v;
    }
    for(int i = 1; i <= M; ++i)printf("%lld\n", ans[i]);
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
/*
5 7
1 2 3
1 3 1
1 4 5
2 3 2
2 5 3
3 4 2
4 5 4
*/