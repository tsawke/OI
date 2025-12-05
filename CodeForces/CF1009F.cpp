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

int N;
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[2100000];
ROPNEW;
Edge* head[1100000];
int siz[1100000], hson[1100000], dep[1100000];
int cnt[1100000];
ll ans[1100000];
int mxp(0);
queue < int > trash;

void dfs_pre(int p = 1, int fa = 0){
    siz[p] = 1, dep[p] = dep[fa] + 1;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_pre(SON, p);
        siz[p] += siz[SON];
        if(siz[SON] > siz[hson[p]])hson[p] = SON;
    }
}
void Insert(int p){
    ++cnt[dep[p]], trash.push(dep[p]);
    if(cnt[dep[p]] > cnt[mxp])mxp = dep[p];
    else if(cnt[dep[p]] == cnt[mxp])mxp = min(mxp, dep[p]);
}
void InsertSubt(int p, int fa){
    Insert(p);
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)InsertSubt(SON, p);
}
void RemoveAll(void){
    while(!trash.empty())--cnt[trash.front()], trash.pop();
    mxp = 0;
}
void dfs_make(int p = 1, int fa = 0){
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa && SON != hson[p])
            dfs_make(SON, p), RemoveAll();
    if(hson[p])dfs_make(hson[p], p);
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa && SON != hson[p])
            InsertSubt(SON, p);
    Insert(p), ans[p] = mxp - dep[p];
}

int main(){
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs_pre(), dfs_make();
    for(int i = 1; i <= N; ++i)printf("%lld\n", ans[i]);
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