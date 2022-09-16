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


// bitset < 110 > wharf[22];

bool blocked[22][110][110];

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
int Dijk(int, int);

priority_queue < 
    pair < ll, int > /*distance, vertex*/,
    vector < pair < ll, int > >,
    // [](pair < int, int > x, pair < int, int > y) ->bool{
    // }
    greater < pair < ll, int > >
 > vert;
signed main(){
//     freopen("plan.in", "r", stdin);
//     freopen("plan.out", "w", stdout);
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
        for(int i = a; i <= b; ++i){
            for(int j = 1; j <= N; ++j){
                blocked[p][i][j] = blocked[p][j][i] = true;
            }
        }
        // for(int i = a; i <= b; ++i)blocked[p][i] = true;
    }
    // for(int i = 1; i <= M; ++i)blocked[i] = wharf[i]._Find_next(0);
    // ll ans(0);
    // ll lastcost(-1);
    ll cost[110][110];
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= i; ++j)
            cost[j][i] = Dijk(j, i);
    ll dp[110];
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= N; ++i){
        dp[i] = i * cost[1][i];
        for(int j = 0; j < i; ++j){
            if(cost[j + 1][i] > 0x3f3f3f3f)continue;
            dp[i] = min(dp[i], dp[j] + cost[j + 1][i] * (i - j - 1 + 1) + K);
        }
    }

    printf("%lld\n", dp[N]);
    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}


int Dijk(int l, int r){
    // bool block[22];
    // memset(block, false, sizeof(block));
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= M; ++i)dis[i] = LLONG_MAX / 2ll - 10ll;
    dis[1] = 0ll;
    vert.push(make_pair(dis[1], 1));
    while(!vert.empty()){
        int p;
        tie(ignore, p) = vert.top();
        vert.pop();
        if(vis[p] || blocked[p][l][r])continue;
        vis[p] = true;
        for(auto i = head[p]; i; i = i->nxt){
            if(dis[p] + i->val < dis[i->to]){
                dis[i->to] = dis[p] + i->val;
                if(!vis[i->to])vert.push(make_pair(dis[i->to], i->to));
            }
        }
    }
    return dis[M];
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