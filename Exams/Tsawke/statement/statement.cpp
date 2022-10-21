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



template<typename T = int>
inline T read(void);

int N, M;
int Q;
int lca[110000];
int dep[110000];
pair < int, int > ask[110000];
ll ans[110000];
pair < int, int /*vertex, val*/ > ffa[110000];

struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[310000];
ROPNEW(ed);
Edge* head[110000];

namespace Tree{
    vector < pair < int, int > /*vertex, query_idx*/ > query[110000];
    bool vis[110000];
    class UnionFind{
    private:
        int fa[110000];
    public:
        UnionFind(void){for(int i = 1; i <= N; ++i)fa[i] = i;}
        int Find(int x){return x == fa[x] ? x : (fa[x] = Find(fa[x]));}
        void Union(int s, int t){fa[t] = Find(s);}
    }uf;
    void Init(void){
        for(int i = 1; i <= Q; ++i){
            int u = read(), v = read();
            ask[i] = {u, v};
            query[u].emplace_back(v, i);
            query[v].emplace_back(u, i);
        }
    }
    void dfs(int p = 1, int fa = 0){
        vis[p] = true;
        for(auto i = head[p]; i; i = i->nxt)if(SON != fa && !vis[SON])dfs(SON, p), uf.Union(p, SON);
        for(auto q : query[p])if(vis[q.first])lca[q.second] = uf.Find(q.first);
    }
    void dfs_dep(int p = 1, int fa = 0){
        dep[p] = dep[fa] + 1;
        for(auto i = head[p]; i; i = i->nxt)if(SON != fa)ffa[SON] = {p, i->val}, dfs_dep(SON, p);
    }
}

int main(){
    freopen("statement.in", "r", stdin);
    freopen("statement.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v};
        head[t] = new Edge{head[t], s, v};
    }Q = read();
    if(M == N - 1){
        Tree::Init();
        Tree::dfs();
        Tree::dfs_dep();
        for(int i = 1; i <= Q; ++i){
            ll anss(0);
            int cp(ask[i].first);
            while(cp != lca[i]){
                anss += ffa[cp].second;
                cp = ffa[cp].first;
            }
            cp = ask[i].second;
            while(cp != lca[i]){
                anss += ffa[cp].second;
                cp = ffa[cp].first;
            }
            printf("%lld\n", anss);
        }
        exit(0);
    }

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