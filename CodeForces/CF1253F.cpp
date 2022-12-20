#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

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
    ll val;
    OPNEW;
}ed[610000];
ROPNEW(ed);
Edge* head[110000];

struct Node{int idx, to;};
basic_string < Node > nods[110000];

int N, M, K;
bitset < 110000 > vis;
ll dis[110000];
ll ans[310000];
priority_queue < tuple < ll, int, int >, vector < tuple < ll, int, int > >, greater < tuple < ll, int, int > > > edgs;

class UnionFind{
private:
    int fa[110000];
    int siz[110000];
public:
    UnionFind(void){for(int i = 1; i <= 101000; ++i)fa[i] = i, siz[i] = 1;}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int origin, int son, ll val){
        int s = Find(origin), t = Find(son);
        if(s != t){
            if(siz[s] < siz[t])swap(s, t);
            siz[s] += siz[t];
            fa[t] = s;
            // if(s != origin)nods[origin].clear(), nods[origin].shrink_to_fit();
            // if(t != son)nods[son].clear(), nods[son].shrink_to_fit();
            for(auto p : nods[t]){
                if(Find(t) == Find(p.to))ans[p.idx] = min(ans[p.idx], val);
                else nods[s] += p;
            }//nods[t].clear(), nods[t].shrink_to_fit();
            // for(auto p : nods[s])if(Find(s) == Find(p.to))ans[p.idx] = min(ans[p.idx], val);
            // for(auto p : nods[t])if(Find(t) == Find(p.to))ans[p.idx] = min(ans[p.idx], val);
        }
    }
}uf;

void Dijk(void){
    memset(dis, 0x3f, sizeof dis);
    priority_queue < pair < ll, int >, vector < pair < ll, int > >, greater < pair < ll, int > > > cur;
    for(int i = 1; i <= K; ++i)cur.push({dis[i] = 0, i});
    while(!cur.empty()){
        int p = cur.top().second; cur.pop();
        if(vis[p])continue;
        vis[p] = true;
        for(auto i = head[p]; i; i = i->nxt)
            if(dis[p] + i->val < dis[SON])
                dis[SON] = dis[p] + i->val, cur.push({dis[SON], SON});
    }
}
int main(){
    memset(ans, 0x3f, sizeof ans);
    N = read(), M = read(), K = read(); int Q = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v};
        head[t] = new Edge{head[t], s, v};
    }Dijk();
    for(int p = 1; p <= N; ++p)
        for(auto i = head[p]; i; i = i->nxt)
            edgs.push({i->val + dis[p] + dis[SON], p, SON});
    for(int q = 1; q <= Q; ++q){
        int s = read(), t = read();
        nods[s] += Node{q, t}, nods[t] += Node{q, s};
    }
    while(!edgs.empty()){
        ll val; int s, t; tie(val, s, t) = edgs.top(); edgs.pop();
        // printf("val = %lld, s = %d, t = %d\n", val, s, t);
        // printf("Fa:2 = %d, Fa:3 = %d\n", uf.Find(2), uf.Find(3));
        uf.Union(s, t, val);
        
    }
    for(int i = 1; i <= Q; ++i)printf("%lld\n", ans[i]);
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