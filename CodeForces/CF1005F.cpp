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
    int idx;
    OPNEW;
}ed[410000];
ROPNEW(ed);
Edge* head[210000];

int N, M, K;
ll T(1);
ll dis[210000];
int cnt[210000];
bitset < 210000 > vis;
basic_string < int > path[210000];
bitset < 210000 > ans;
int curcnt(0);

void Dijk(void){
    memset(dis, 0x3f, sizeof dis);
    priority_queue < pair < ll, int >, vector < pair < ll, int> >, greater < pair < ll, int > > > cur;
    dis[1] = 0, cur.push({dis[1], 1});
    while(!cur.empty()){
        int tp = cur.top().second; cur.pop();
        if(vis[tp])continue;
        vis[tp] = true;
        for(auto i = head[tp]; i; i = i->nxt)
            if(dis[tp] + 1 < dis[SON])
                dis[SON] = dis[tp] + 1,
                cnt[SON] = 1,
                path[SON].clear(),
                path[SON] += i->idx,
                cur.push({dis[SON], SON});
            else if(dis[tp] + 1 == dis[SON])
                ++cnt[SON],
                path[SON] += i->idx;
    }
}

void dfs(int dep = 2){
    static basic_string < int > cur;
    if(dep > N){
        for(int i = 1; i <= M; ++i)printf("%d", ans[i] ? 1 : 0);
        printf("\n");
        if(++curcnt == min(T, (ll)K))exit(0);
    }
    for(auto id : path[dep]){
        cur += id;
        ans[id] = true;
        dfs(dep + 1);
        cur.pop_back();
        ans[id] = false;
    }
}

int main(){
    N = read(), M = read(), K = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t, i};
        head[t] = new Edge{head[t], s, i};
    }Dijk();
    for(int i = 2; i <= N; ++i)T *= cnt[i], T = min(T, (ll)K);
    printf("%lld\n", T);
    dfs();
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