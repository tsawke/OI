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

#define MOD (ll)(1e9 + 7)

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    int val;
    int idx;
    bool exist;
    OPNEW;
}ed[1100000];
ROPNEW(ed);
Edge* head[2000];

int N, M;
int S;
bitset < 2000 > vis;
int dis[2000];
int from[2000];
ll cnt[5100];
int cntup[2000], cntdown[2000];
int ind[2000];

void Topo(void){
    memset(cntup, 0, sizeof cntup);
    memset(cntdown, 0, sizeof cntdown);
    queue < int > cur;
    basic_string < int > arr;
    arr += S, cur.push(S), cntup[S] = 1;
    while(!cur.empty()){
        int p = cur.front(); cur.pop();
        for(auto i = head[p]; i; i = i->nxt){
            if(!i->exist)continue;
            (cntup[SON] += cntup[p]) %= MOD;
            --ind[SON];
            if(!ind[SON])arr += SON, cur.push(SON);
        }
    }
    for(auto it = arr.rbegin(); it != arr.rend(); ++it){
        int p = *it;
        cntdown[p] = 1;
        for(auto i = head[p]; i; i = i->nxt)
            if(i->exist)
                (cntdown[p] += cntdown[SON]) %= MOD;
    }
}
void SetAns(void){
    for(int p = 1; p <= N; ++p)
        for(auto i = head[p]; i; i = i->nxt)
            if(i->exist)
                (cnt[i->idx] += (ll)cntup[p] * cntdown[SON] % MOD) %= MOD;
}

void Dijk(void){
    memset(dis, 0x3f, sizeof dis);
    memset(ind, 0, sizeof ind);
    vis.reset();
    priority_queue < pair < int, int >, vector < pair < int, int > >, greater < pair < int, int > > > cur;
    dis[S] = 0; cur.push({dis[S], S});
    while(!cur.empty()){
        int p = cur.top().second; cur.pop();
        if(vis[p])continue;
        vis[p] = true;
        for(auto i = head[p]; i; i = i->nxt)
            if(dis[p] + i->val < dis[SON])
                dis[SON] = dis[p] + i->val, cur.push({dis[SON], SON});
    }
    for(int p = 1; p <= N; ++p)
        for(auto i = head[p]; i; i = i->nxt){
            i->exist = dis[p] + i->val == dis[SON];
            if(i->exist)++ind[SON];
        }
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v, i};
    }
    for(int i = 1; i <= N; ++i){
        S = i;
        Dijk();
        Topo();
        SetAns();
    }
    for(int i = 1; i <= M; ++i)printf("%lld\n", cnt[i]);
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