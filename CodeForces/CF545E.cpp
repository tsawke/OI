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
}ed[610000];
ROPNEW(ed);
Edge* head[310000];

int N, M;
int S;
ll dis[310000];
ll edval[310000];
bool vis[310000];
int idx[310000];

void Dijk(void){
    memset(dis, 0x3f, sizeof dis);
    priority_queue < pair < ll, int >, vector < pair < ll, int> >, greater < pair < ll, int > > > cur;
    dis[S] = 0, cur.push({dis[S], S});
    while(!cur.empty()){
        int tp = cur.top().second; cur.pop();
        if(vis[tp])continue;
        vis[tp] = true;
        for(auto i = head[tp]; i; i = i->nxt){
            if(dis[tp] + i->val < dis[SON])
                dis[SON] = dis[tp] + i->val, idx[SON] = i->idx, cur.push({dis[SON], SON});
            else if(dis[tp] + i->val == dis[SON] && i->val < edval[idx[SON]])idx[SON] = i->idx;
        }
    }
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v, i};
        head[t] = new Edge{head[t], s, v, i};
        edval[i] = v;
    }S = read();
    Dijk();
    ll sum(0);
    for(int i = 1; i <= N; ++i)if(i != S)sum += edval[idx[i]];
    printf("%lld\n", sum);
    for(int i = 1; i <= N; ++i)if(i != S)printf("%d ", idx[i]);
    printf("\n");
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