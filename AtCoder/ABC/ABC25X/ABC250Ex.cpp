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
}ed[410000];
ROPNEW(ed);
Edge* head[210000];

int N, M, K;
bitset < 210000 > vis;
ll dis[210000];
priority_queue < tuple < ll, int, int >, vector < tuple < ll, int, int > >, greater < tuple < ll, int, int > > > edgs;

class UnionFind{
private:
    int fa[210000];
public:
    UnionFind(void){for(int i = 1; i <= 201000; ++i)fa[i] = i;}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int origin, int son){fa[Find(son)] = Find(origin);}
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
    N = read(), M = read(), K = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v};
        head[t] = new Edge{head[t], s, v};
    }Dijk();
    for(int p = 1; p <= N; ++p)
        for(auto i = head[p]; i; i = i->nxt)
            edgs.push({i->val + dis[p] + dis[SON], p, SON});
    int Q = read();
    while(Q--){
        int s = read(), t = read(); ll lim = read < ll >();
        while(!edgs.empty() && get < 0 >(edgs.top()) <= lim)
            uf.Union(get < 1 >(edgs.top()), get < 2 >(edgs.top())), edgs.pop();
        printf("%s\n", uf.Find(s) == uf.Find(t) ? "Yes" : "No");
    }
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