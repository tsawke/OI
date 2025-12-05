#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

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
    OPNEW;
}ed[410000];
ROPNEW;
Edge* head[210000];

int N, Q;
int mxp(0);
int dep[210000];
int rtS(-1), rtT(-1);
struct MyPair{int first, second;};
basic_string < MyPair/*dis, idx*/ > qs[210000];
basic_string < int > cur; //clear
int ans[210000];

void dfs_dep(int p = 1, int fa = 0){
    dep[p] = dep[fa] + 1;
    if(dep[p] > dep[mxp])mxp = p;
    for(auto i = head[p]; i; i = i->nxt)if(SON != fa)dfs_dep(SON, p);
}
void UpdateMxp(int root = 1){
    mxp = 0;
    dfs_dep(root);
}
void dfs(int p, int fa = 0){
    cur += p;
    for(auto u : qs[p])
        ans[u.second] = u.first + 1 > (int)cur.size() ? (!ans[u.second] ? -1 : ans[u.second]) : cur.at((int)cur.size() - u.first - 1);
    for(auto i = head[p]; i; i = i->nxt)if(SON != fa)dfs(SON, p);
    cur.pop_back();
}

int main(){
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }UpdateMxp(), rtS = mxp, UpdateMxp(mxp), rtT = mxp;
    Q = read();
    for(int i = 1; i <= Q; ++i){
        int p = read(), d = read();
        qs[p] += MyPair{d, i};
    }dfs(rtS), dfs(rtT);
    for(int i = 1; i <= Q; ++i)printf("%d\n", ans[i]);
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