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
    int val;
    int idx;
    OPNEW;
}ed[1210000];
ROPNEW(ed);
Edge* head[310000];
Edge* thead[310000];

int N, M, K;
ll dis[310000];
bool vis[310000];
int idx[310000];
int from[310000];
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
            if(dis[tp] + i->val < dis[SON])
                dis[SON] = dis[tp] + i->val, idx[SON] = i->idx, from[SON] = tp, cur.push({dis[SON], SON});
    }
}
void dfs(int p = 1, int fa = 0){
    for(auto i = thead[p]; i; i = i->nxt){
        if(SON == fa)continue;
        printf("%d ", i->val);
        if(++curcnt == min(K, N - 1))printf("\n"), exit(0);
        dfs(SON, p);
    }
}

int main(){
    N = read(), M = read(), K = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v, i};
        head[t] = new Edge{head[t], s, v, i};
    }Dijk();
    for(int i = 2; i <= N; ++i){
        int s = i, t = from[i];
        thead[s] = new Edge{thead[s], t, idx[i]};
        thead[t] = new Edge{thead[t], s, idx[i]};
    }printf("%d\n", min(K, N - 1));
    if(min(K, N - 1) == 0)exit(0);
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