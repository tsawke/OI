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


int N, M;

class UnionFind{
private:
    int fa[MAXNM];
public:
    UnionFind(void){for(int i = 1; i <= 201000; ++i)fa[i] = i;}
    void Reset(void){for(int i = 1; i <= N; ++i)fa[i] = i;}
    int Find(int x){return fa[x] == x ? x : fa[x] = Find(fa[x]);}
    void Union(int origin, int son){fa[Find(son)] = Find(origin);}
}uf;

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


int main(){
    // freopen("tree.in", "r", stdin);
    // freopen("tree.out", "w", stdout);
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        edges.emplace_back(Edges{v, s, t, i});
        qs[i] = {s, t, v};
    }sort(edges.begin(), edges.end());
    for(int i = 1; i <= M; ++i){
        ll ans(0);
        uf.Reset();
        int s, t, v; tie(s, t, v) = qs[i];
        uf.Union(s, t);
        ans += v;
        for(auto e : edges)
            if(uf.Find(e.s) != uf.Find(e.t))
                uf.Union(e.s, e.t),
                    ans += e.val;
        printf("%lld\n", ans);
    }


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