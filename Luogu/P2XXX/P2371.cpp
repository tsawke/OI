#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

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
    ll val;
    OPNEW;
}ed[7100000];
ROPNEW;
Edge* head[510000];

int N;
int P;
ll l, r;
int A[510000];
ll dis[510000];
ll ans(0);
bitset < 510000 > vis;

void Dijkstra(void){
    memset(dis, 0x3f, sizeof dis);
    priority_queue < pair < ll, int >, vector < pair < ll, int > >, greater < pair < ll, int > > > cur;
    dis[0] = 0, cur.push({0, 0});
    while(!cur.empty()){
        int p = cur.top().second; cur.pop();
        if(vis[p])continue;
        vis[p] = true;
        for(auto i = head[p]; i; i = i->nxt)
            if(dis[SON] > dis[p] + i->val)
                dis[SON] = dis[p] + i->val, cur.push({dis[SON], SON});
    }
}

int main(){
    N = read(), l = read < ll >(), r = read < ll >();
    for(int i = 1; i <= N; ++i)A[i] = read();
    P = A[1];
    for(int i = 0; i < P; ++i)
        for(int j = 2; j <= N; ++j)
            head[i] = new Edge{head[i], (i + A[j]) % P, A[j]};
    Dijkstra();
    ll H = r;
    for(int i = 0; i < P; ++i)
        if(H >= dis[i])
            ans += (H - dis[i]) / P + 1;
    H = l - 1;
    for(int i = 0; i < P; ++i)
        if(H >= dis[i])
            ans -= (H - dis[i]) / P + 1;
    printf("%lld\n", ans);
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