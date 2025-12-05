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



template<typename T = int>
inline T read(void);

class UnionFind{
    private:
        int fa[510000];
    public:
        UnionFind(void){for(int i = 0; i <= 501000; ++i)fa[i] = i;}
        int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}
        void merge(int base, int x){fa[x] = find(base);}
}uf;
int N, Q;

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}eData[1100000];
ROPNEW(eData);

Edge* head[510000];
vector < pair < int, int > > ask[510000];
int ans[510000];
bool vis[510000];

void Tarjan(int p, int fa = -1){
    vis[p] = true;
    for(auto i = head[p]; i; i = i->nxt)if(!vis[i->to] && i->to != fa)Tarjan(i->to, p), uf.merge(p, i->to);
    for(auto i : ask[p]){if(vis[i.first])ans[i.second] = uf.find(i.first);}
}

int main(){
    N = read(), Q = read(); int rt = read();
    for(int i = 1; i <= N - 1; ++i){
        int f = read(), t = read();
        head[f] = new Edge{head[f], t};
        head[t] = new Edge{head[t], f};
    }
    for(int q = 1; q <= Q; ++q){
        int u = read(), v = read();
        ask[u].push_back({v, q});
        ask[v].push_back({u, q});
    }
    Tarjan(rt);
    for(int i = 1; i <= Q; ++i)printf("%d\n", ans[i]);

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