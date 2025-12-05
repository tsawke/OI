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

struct Edge{
    Edge* nxt;
    int to;
    int idx;
    OPNEW;
}ed[110000];
ROPNEW(ed);
Edge* head[51000];

int ans[51000], nod_idx[51000];

int N, M;
int dep[51000], dfn[51000], idx[51000], top[51000], siz[51000], fa[51000], hson[51000];

struct Node{
    int l, r;
    mutable int val;
    friend const bool operator < (const Node &a, const Node &b){
        return a.l < b.l;
    }
};

class ODT{
private:
    set < Node > tr;
public:
    auto Insert(Node x){return tr.insert(x);}
    auto Split(int p){
        auto it = tr.lower_bound(Node{p});
        if(it != tr.end() && it->l == p)return it;
        --it;
        // printf("%d %d %d\n", it->l, it->r, it->val);
        int l = it->l, r = it->r, v = it->val;
        tr.erase(it), Insert(Node{l, p - 1, v});
        return Insert(Node{p, r, v}).first;
    }
    void Assign(int l, int r, int v){
        if(l > r)return;
        // printf("assigning %d~%d, %d\n", l, r, v);
        auto itR = Split(r + 1), itL = Split(l);
        tr.erase(itL, itR);
        Insert(Node{l, r, v});
    }
    void SetAns(void){
        for(auto nod : tr)
            for(int i = nod.l; i <= nod.r; ++i)
                ans[nod_idx[idx[i]]] = nod.val;
    }
}odt;

struct Edges{
    int s, t;
    int val;
    friend const bool operator < (const Edges &a, const Edges &b){
        return a.val > b.val;
    }
};
vector < Edges > es;

void dfs_pre(int p = 1, int ffa = 0){
    fa[p] = ffa;
    dep[p] = dep[ffa] + 1;
    siz[p] = 1;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == ffa)continue;
        nod_idx[SON] = i->idx;
        dfs_pre(SON, p);
        siz[p] += siz[SON];
        if(siz[SON] > siz[hson[p]])hson[p] = SON;
    }
}
void dfs(int p = 1, int tp = 1){
    static int cdfn(0);
    top[p] = tp;
    dfn[p] = ++cdfn;
    idx[cdfn] = p;
    if(hson[p])dfs(hson[p], tp);
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa[p] || SON == hson[p])continue;
        dfs(SON, SON);
    }
}

void AssignRange(int s, int t, int val){
    while(top[s] != top[t]){
        if(dep[top[s]] < dep[top[t]])swap(s, t);
        odt.Assign(dfn[top[s]], dfn[s], val);
        s = fa[top[s]];
    }if(dep[s] < dep[t])swap(s, t);
    odt.Assign(dfn[t] + 1, dfn[s], val);
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t, i};
        head[t] = new Edge{head[t], s, i};
    }dfs_pre(), dfs();
    // for(int i = 1; i <= N; ++i)printf("[%d]: dfn: %d, fa: %d, dep: %d, top: %d, hson: %d\n", i, dfn[i], fa[i], dep[i], top[i], hson[i]);
    // for(int i = 1; i <= N; ++i)printf("nodidx[%d]: %d\n", i, nod_idx[i]);
    odt.Insert(Node{1, N, -1});
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        es.emplace_back(Edges{s, t, v});
    }sort(es.begin(), es.end());
    for(auto e : es)AssignRange(e.s, e.t, e.val);
    odt.SetAns();
    for(int i = 1; i <= N - 1; ++i)printf("%d\n", ans[i]);
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