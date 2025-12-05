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

#define INF (0x3f3f3f3f)

template < typename T = int >
inline T read(void);

int N, M;
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[410000];
ROPNEW;
Edge* head[110000];
Edge* dhead[110000];
int val[110000];
bitset < 110000 > vis;
int rt(-1);
int siz[110000], mx[110000], root;

namespace HLD{
    int siz[110000], dep[110000], hson[110000], top[110000], fa[110000], dfn[110000], idx[110000];
    void dfs_pre(int p = 1, int fa = 0){
        dep[p] = dep[fa] + 1, fa[p] = fa, siz[p] = 1;
        for(auto i = head[p]; i; i = i->nxt)
    }

}

void dfs_root(int p = 1, int fa = 0){
    siz[p] = 1, mx[p] = 0;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_root(SON, p);
        siz[p] += siz[SON];
        mx[p] = max(mx[p], siz[SON]);
    }if(mx[p] < mx[root])root = p;
}

void dfs_build(int p){
    vis[p] = true;
    for(auto i = head[p]; i; i = i->nxt){
        if(vis[SON])continue;
        root = 0;
        dfs_root(SON, p);
        dhead[p] = new Edge{dhead[p], root};
        dhead[root] = new Edge{dhead[root], p};
        dfs_build(root);
    }
}

class BIT{
private:
    unordered_map < int, int > tr;
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x, int v){while(x <= N)tr[x] += v, x += lowbit(x);}
    int Query(int x){int ret(0); while(x)ret += tr[x], x -= lowbit(x); return ret;}
}bit[110000], bit2[110000];

void dfs_subt(int p, int fa, int rt, int dis = 0){
    bit[rt].Modify(dis, val[p]);
    for(auto i = dhead[p]; i; i = i->nxt)
        if(SON != fa)dfs_subt(SON, p, rt, dis + 1);
}
void dfs_subt2(int p, int fa, int rt, int dis = 1){
    bit2[rt].Modify(dis, val[p]);
    for(auto i = dhead[p]; i; i = i->nxt)
        if(SON != fa)dfs_subt(SON, p, rt, dis + 1);
}
void dfs_set(int p = rt, int fa = 0){
    dfs_subt(p, fa, p), dfs_subt2(p)
    for(auto i = dhead[p]; i; i = i->nxt)
        if(SON != fa)dfs_set(SON, p);
}

int main(){
    mx[0] = INF;
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)val[i] = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs_root(), dfs_build(rt = root), dfs_set();


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