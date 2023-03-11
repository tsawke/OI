#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

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

int N, M;
struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[210000];
ROPNEW;
Edge* head[110000];

class UnionFind{
private:
    int fa[110000];
public:
    UnionFind(void){for(int i = 0; i <= 101000; ++i)fa[i] = i;}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int s, int t){int fs = Find(s), ft = Find(t); fa[fs] = ft;}
}uf;

struct Edg{int s, t, v;};
basic_string < Edg > edgs;
basic_string < Edg > trash;

int dep[110000], fa[110000], hson[110000], siz[110000], dfn[110000], idx[110000], top[110000];

void dfs_pre(int p = 1, int fa = 0){
    ::fa[p] = fa, dep[p] = dep[fa] + 1, siz[p] = 1;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_pre(SON, p);
        siz[p] += siz[SON];
        if(siz[SON] > siz[hson[p]])hson[p] = SON;
    }
}
void dfs_make(int p = 1, int top = 1){
    static int cdfn(0);
    dfn[p] = ++cdfn, idx[cdfn] = p, ::top[p] = top;
    if(hson[p])dfs_make(hson[p], top);
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa[p] && SON != hson[p])dfs_make(SON, SON);
}

ll ans(LONG_LONG_MAX);
int val[110000];

void PushdownVal(int p = 1, int fa = 0){
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)
            val[SON] = i->val, PushdownVal(SON, p);
}

class SegTree{
private:
    int mx[110000 << 2], mx2[110000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    SegTree(void){memset(mx, -1, sizeof mx), memset(mx2, -1, sizeof mx2);}
    void Pushup(int p){
        basic_string < int > vals;
        if(~mx[LS])vals += mx[LS];
        if(~mx[RS])vals += mx[RS];
        if(~mx2[LS])vals += mx2[LS];
        if(~mx2[RS])vals += mx2[RS];
        sort(vals.begin(), vals.end(), greater < int >());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        mx[p] = (int)vals.size() >= 1 ? *vals.begin() : -1;
        mx2[p] = (int)vals.size() >= 2 ? *next(vals.begin()) : -1;
    }
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return mx[p] = val[idx[gl = gr]], void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    pair < int, int > Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return {mx[p], mx2[p]};
        if(l > gr || r < gl)return {-1, -1};
        basic_string < int > vals;
        auto ret = Query(l, r, LS, gl, MID);
        if(~ret.first)vals += ret.first;
        if(~ret.second)vals += ret.second;
        ret = Query(l, r, RS, MID + 1, gr);
        if(~ret.first)vals += ret.first;
        if(~ret.second)vals += ret.second;
        sort(vals.begin(), vals.end(), greater < int >());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        return {(int)vals.size() >= 1 ? *vals.begin() : -1, (int)vals.size() >= 2 ? *next(vals.begin()) : -1};
    }
}st;

ll origin(0);

int QueryMx2(int s, int t, int ban){
    basic_string < int > vals;
    while(top[s] != top[t]){
        if(dep[top[s]] < dep[top[t]])swap(s, t);
        auto ret = st.Query(dfn[top[s]], dfn[s]);
        if(~ret.first)vals += ret.first;
        if(~ret.second)vals += ret.second;
        // printf("Querying %d->%d, [%d, %d], ret %d %d\n", top[s], s, dfn[top[s]], dfn[s], ret.first, ret.second);
        s = fa[top[s]];
    }if(dep[s] < dep[t])swap(s, t);
    auto ret = st.Query(dfn[hson[t]], dfn[s]);
    // printf("Querying %d->%d, [%d, %d], ret %d %d\n", hson[t], s, dfn[hson[t]], dfn[s], ret.first, ret.second);
    if(~ret.first)vals += ret.first;
    if(~ret.second)vals += ret.second;
    sort(vals.begin(), vals.end(), greater < int >());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int mx = (int)vals.size() >= 1 ? *vals.begin() : -1, mx2 = (int)vals.size() >= 2 ? *next(vals.begin()) : -1;
    return mx != ban ? mx : mx2;
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        if(s == t)continue;
        edgs += Edg{s, t, v};
    }sort(edgs.begin(), edgs.end(), [](const Edg &a, const Edg &b)->bool{return a.v < b.v;});
    for(auto edg : edgs){
        auto [s, t, v] = edg;
        if(uf.Find(s) != uf.Find(t))
            head[s] = new Edge{head[s], t, v},
            head[t] = new Edge{head[t], s, v},
            origin += v,
            uf.Union(s, t);
        else trash += edg;
    }dfs_pre(), dfs_make(), PushdownVal();
    st.Build();
    // printf("origin is %lld\n", origin);
    for(auto edg : trash){
        auto [s, t, v] = edg;
        int ret = QueryMx2(s, t, v);
        if(!~ret)continue;
        // printf("[%d - %d], v = %d, ret = %d\n", s, t, v, ret);
        ans = min(ans, origin - ret + v);
    }printf("%lld\n", ans);
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