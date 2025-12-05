#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define npt nullptr

/******************************
abbr

******************************/

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int percent){return rndd(1, 100) <= percent;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define int ll

bitset < 110 > wharf[22];
int blocked[22];

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    int val;
    void* operator new(size_t);
    Edge(Edge* nxt, int to, int val):nxt(nxt), to(to), val(val){;}
    Edge(void) = default;
}eData[410];
void* Edge::operator new(size_t){static Edge* P = eData; return ++P;}
Edge* head[22];

int N, M, K, E;

bool vis[22];
ll dis[22];
void Dijk(int);

priority_queue < 
    pair < ll, int > /*distance, vertex*/,
    vector < pair < ll, int > >,
    // [](pair < int, int > x, pair < int, int > y) ->bool{
    // }
    greater < pair < ll, int > >
 > vert;
signed main(){
    freopen("plan.in", "r", stdin);
    freopen("plan.out", "w", stdout);
    N = read(), M = read(), K = read(), E = read();
    for(int i = 1; i <= E; ++i){
        int f = read(), t = read(), val = read();
        if(f == t)continue;
        head[f] = new Edge(head[f], t, val);
        head[t] = new Edge(head[t], f, val);
    }
    int D = read();
    while(D--){
        int p = read(), a = read(), b = read();
        for(int i = a; i <= b; ++i)wharf[p][i] = true;
    }
    for(int i = 1; i <= M; ++i)blocked[i] = wharf[i]._Find_next(0);
    ll ans(0);
    ll lastcost(-1);
    for(int i = 1; i <= N; ++i){
        Dijk(i);
        ll cost = dis[M];
        ans += cost;
        if(i != 1 && cost != lastcost)ans += K;
        lastcost = cost;
    }
    while((double)clock() / CLOCKS_PER_SEC < 0.7){
        for(int i = 1; i <= M; ++i){
            for(auto j = head[i]; j; j = j->nxt){
                if(rnddd(10))j->val *= 1.05;
            }
            blocked[i] = wharf[i]._Find_next(0);
        }
        ll anss(0);
        ll lastcostt(-1);
        for(int i = 1; i <= N; ++i){
            Dijk(i);
            ll costt = dis[M];
            anss += costt;
            if(i != 1 && costt != lastcostt)anss += K;
            lastcostt = costt;
        }
        ans = min(ans, anss);
    }
    printf("%lld\n", ans);
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}


void Dijk(int day){
    bool block[22];
    memset(block, false, sizeof(block));
    for(int i = 1; i <= M; ++i){
        if(day == blocked[i]){
            block[i] = true;
            if(blocked[i] <= N)blocked[i] = wharf[i]._Find_next(blocked[i]);
        }
    }
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= M; ++i)dis[i] = LLONG_MAX / 2ll - 10ll;
    dis[1] = 0ll;
    vert.push(make_pair(dis[1], 1));
    while(!vert.empty()){
        int p;
        tie(ignore, p) = vert.top();
        vert.pop();
        if(vis[p] || block[p])continue;
        vis[p] = true;
        for(auto i = head[p]; i; i = i->nxt){
            if(dis[p] + i->val < dis[i->to]){
                dis[i->to] = dis[p] + i->val;
                if(!vis[i->to])vert.push(make_pair(dis[i->to], i->to));
            }
        }
    }
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

/*

5 5 10 8
1 2 1
1 3 3
1 4 2
2 3 2
2 4 4
3 4 1
3 5 2
4 5 2
4
2 2 3
3 1 1
3 3 3
4 4 5

*/