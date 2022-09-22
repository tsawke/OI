#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define int ll

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    void* operator new(size_t);
    Edge(Edge* nxt, int to):nxt(nxt), to(to){;}
    Edge(void) = default;
}eData[2100000];
void* Edge::operator new(size_t){static Edge* P = eData; return ++P;}
Edge* head[1100000];

int N;
int dep[1100000], siz[1100000], dp[1100000];

void dfs_pre(int p = 1, int fa = 0){
    siz[p] = 1;
    dep[p] = dep[fa] + 1;
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs_pre(SON, p), siz[p] += siz[SON];
}
void dfs_make(int p = 1, int fa = 0){
    for(auto i = head[p]; i; i = i->nxt){
        if(SON != fa){
            dp[SON] = dp[p] - siz[SON] + N - siz[SON];
            dfs_make(SON, p);
        }
    }
}

signed main(){
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int f = read(), t = read();
        head[f] = new Edge(head[f], t);
        head[t] = new Edge(head[t], f);
    }
    dfs_pre();
    for(int i = 1; i <= N; ++i)dp[1] += dep[i];
    dfs_make();
    int ansp(0), ansv(-1);
    for(int i = 1; i <= N; ++i)if(dp[i] > ansv)ansv = dp[i], ansp = i;
    printf("%lld\n", ansp);

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