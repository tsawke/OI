#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define PI M_PI
#define E M_E
#define npt nullptr

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef long long ll;
typedef unsigned long long unll;

template <typename T = int>
inline T read(void);
int N, M;
struct Edge{
    Edge* nxt;
    Edge* rev;
    int to;
    ll val;
    void* operator new(size_t);
    Edge(Edge* _nxt, Edge* _rev, int _to, ll _val):nxt(_nxt), rev(_rev), to(_to), val(_val){;}
    Edge(void) = default;
}eData[3100];
void* Edge::operator new(size_t){static Edge* P = eData; return ++P;}
Edge *head[50], *cur[50];

int S = 1, T;
int dep[50];

ll dfs(int p = S, ll curFlow = INT_MAX){
    if(p == T)return curFlow;
    ll cost(0);
    for(auto &i = cur[p]; i; i = i->nxt){
        if(i->val > 0 && dep[i->to] == dep[p] - 1){
            ll icost = dfs(i->to, min(curFlow - cost, i->val));
            cost += icost;
            i->val -= icost;
            i->rev->val += icost;
        }
        if(cost == curFlow)break;
    }
    if(!cost)dep[p] = INT_MAX;
    return cost;
}

bool bfs(void){
    copy(head + 1, head + N + 1, cur + 1);
    memset(dep, 0, sizeof(dep));
    queue < int > q;
    q.push(T);
    dep[T] = 1;
    while(!q.empty()){
        int t = q.front(); q.pop();
        for(auto i = head[t]; i; i = i->nxt){
            if(!dep[i->to] && i->rev->val > 0){
                dep[i->to] = dep[t] + 1;
                q.push(i->to);
            }
        }
    }
    return dep[S];
}

ll Dinic(void){
    ll ret(0), tmp;
    while(bfs())while((tmp = dfs()))ret += tmp;
    return ret;
}

int main(){
    // freopen("control.in", "r", stdin);
    // freopen("control.out", "w", stdout);
    N = read(), M = read();
    T = N;
    for(int i = 1; i <= M; ++i){
        int f = read(), t = read(), v = read<ll>();
        head[f] = new Edge(head[f], npt, t, v);
        head[t] = new Edge(head[t], npt, f, 0);
        head[f]->rev = head[t];
        head[t]->rev = head[f];
    }
    printf("%lld", Dinic());
    // for(int i = 1; i <= N; ++i){
    //     for(auto j = head[i]; j; j = j->nxt){
    //         if(!j->val && !j->rev->val)j->rev->val = 1, j->val = 0;
    //     }
    // }
    for(int i = 1; i <= N; ++i){
        for(auto j = head[i]; j; j = j->nxt){
            // if(!j->val && !j->rev->val)continue;
            if(!j->val)j->val = 1;
            else j->val = INT_MAX;
        }
    }
    printf(" %lld\n", Dinic());
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
inline T read(void){
    T ret(0);
    T flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-')flag = 1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }
    ret *= flag;
    return ret;
}

/* Examples:



*/