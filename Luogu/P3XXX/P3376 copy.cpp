#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define npt nullptr
#define upd(from, to, val) \
    head[from] = new Edge(head[from], npt, to, val); \
    head[to] = new Edge(head[to], npt, from, 0); \
    head[from]->rev = head[to], head[to]->rev = head[from]

#define abbr
#define rev reverse

#define int ll

template<typename T = int>
inline T read(void);

struct Edge{
    Edge *nxt;
    Edge *rev;
    int to;
    int val;
    bool used;
    void* operator new(size_t);
    Edge(Edge *_nxt = npt, Edge *_rev = npt, int _to = -1, int _val = 0):nxt(_nxt), rev(_rev), to(_to), val(_val), used(false){;}
}eData[11000];
void* Edge::operator new(size_t){ static Edge* P = eData; return ++P;}
Edge *head[210], *cur[210];
int N, M, S, T;
int dep[210];
bool bfs(void);
int dfs(int = S, int = INT_MAX);
int Dinic(void);
signed main(){
    N = read(), M = read(), S = read(), T = read();
    for(int i = 1; i <= M; ++i){
        int from = read(), to = read(), val = read();
        if(from == to)continue;
        upd(from, to, val);
    }
    printf("%lld\n", Dinic());
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}
int Dinic(void){
    int ret(0), tmp;
    while(bfs()) while((tmp = dfs())) ret += tmp;
    return ret;
}
bool bfs(void){
    copy(head + 1, head + N + 1, cur + 1);
    memset(dep, 0, sizeof(dep));
    queue < int > q;
    q.push(T);
    dep[T] = 1;
    while(!q.empty()){ 
        int from = q.front(); q.pop();
        for(auto i = head[from]; i; i = i->nxt){
            if(i->rev->val > 0 && !dep[i->to]){
                q.push(i->to);
                dep[i->to] = dep[from] + 1;
            }
        }
        if(dep[S])break;
    }
    return dep[S];
}
int dfs(int p, int flow){
    if(p == T)return flow;
    int cost(0);
    for(auto &i = cur[p]; i; i = i->nxt){
        if(i->val > 0 && dep[p] - 1 == dep[i->to]){
            int icost = dfs(i->to, min(flow - cost, i->val));
            cost += icost;
            i->val -= icost;
            i->rev->val += icost;
            if(cost == flow)break;
        }
    }
    if(!cost)dep[p] = INT_MAX;
    return cost;
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