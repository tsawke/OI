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

int N;
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[1100000];
ROPNEW;
Edge* head[510000];
int dep[510000], siz[510000], hson[510000];
int ans[510000];
int mxdep[4500000], status[510000];

void dfs_pre(int p = 1, int fa = 0){
    siz[p] = 1, dep[p] = dep[fa] + 1, status[p] ^= status[fa];
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_pre(SON, p);
        siz[p] += siz[SON];
        if(siz[SON] > siz[hson[p]])hson[p] = SON;
    }
}
void ClearAll(int p, int fa){
    mxdep[status[p]] = -INF;
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)ClearAll(SON, p);
}
void Update(int p, int fa, int rt){
    ans[rt] = max(ans[rt], dep[p] + mxdep[status[p]]);
    for(int i = 0; i <= 21; ++i)ans[rt] = max(ans[rt], dep[p] + mxdep[status[p] ^ (1 << i)]);
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)Update(SON, p, rt);
}
void Insert(int p, int fa){
    mxdep[status[p]] = max(mxdep[status[p]], dep[p]);
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)Insert(SON, p);
}
void dfs_make(int p = 1, int fa = 0){
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa && SON != hson[p])dfs_make(SON, p), ClearAll(SON, p);
    if(hson[p])dfs_make(hson[p], p);
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa && SON != hson[p])Update(SON, p, p), Insert(SON, p);
    mxdep[status[p]] = max(mxdep[status[p]], dep[p]);
    ans[p] = max(ans[p], dep[p] + mxdep[status[p]]);
    for(int i = 0; i <= 21; ++i)
        ans[p] = max(ans[p], dep[p] + mxdep[status[p] ^ (1 << i)]);
    ans[p] -= dep[p] << 1;
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)ans[p] = max(ans[p], ans[SON]);
}

int main(){
    for(int i = 0; i < 4500000; ++i)mxdep[i] = -INF;
    N = read();
    for(int i = 2; i <= N; ++i){
        int s = read(), t = i;
        char c = getchar(); while(!islower(c))c = getchar();
        status[t] = 1 << (c - 'a');
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs_pre(), dfs_make();

    for(int i = 1; i <= N; ++i)printf("%d%c", ans[i], i == N ? '\n' : ' ');
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