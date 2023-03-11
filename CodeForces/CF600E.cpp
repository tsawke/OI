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
}ed[210000];
ROPNEW;
Edge* head[110000];
int col[110000];
int siz[110000], hson[110000];
int cnt[110000];
ll ans[110000];
int mxp(0);
ll mxv(0);
queue < int > trash;

void dfs_pre(int p = 1, int fa = 0){
    siz[p] = 1;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_pre(SON, p);
        siz[p] += siz[SON];
        if(siz[SON] > siz[hson[p]])hson[p] = SON;
    }
}
void Insert(int p){
    ++cnt[col[p]], trash.push(col[p]);
    if(mxp == col[p] || cnt[col[p]] > cnt[mxp])mxp = col[p], mxv = col[p];
    else if(cnt[col[p]] == cnt[mxp])mxv += col[p];
}
void InsertSubt(int p, int fa){
    Insert(p);
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)InsertSubt(SON, p);
}
void RemoveAll(void){
    while(!trash.empty())--cnt[trash.front()], trash.pop();
    mxp = mxv = 0;
}
void dfs_make(int p = 1, int fa = 0){
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa && SON != hson[p])
            dfs_make(SON, p), RemoveAll();
    if(hson[p])dfs_make(hson[p], p);
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa && SON != hson[p])
            InsertSubt(SON, p);
    Insert(p), ans[p] = mxv;
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)col[i] = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs_pre(), dfs_make();
    for(int i = 1; i <= N; ++i)printf("%lld%c", ans[i], i == N ? '\n' : ' ');
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