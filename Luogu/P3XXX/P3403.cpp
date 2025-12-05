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

ll H;
int x, y, z;

struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[210000];
ROPNEW;
Edge* head[110000];

bitset < 110000 > vis;
ll dis[110000];
ll ans(0);

void Dijkstra(void){
    memset(dis, 0x3f, sizeof dis);
    static priority_queue < pair < ll, int >, vector < pair < ll, int > >, greater < pair < ll, int > > > cur;
    dis[1] = 1, cur.push({0, 1});
    while(!cur.empty()){
        int p = cur.top().second; cur.pop();
        if(vis[p])continue;
        vis[p] = true;
        for(auto i = head[p]; i; i = i->nxt)
            if(dis[p] + i->val < dis[SON])
                dis[SON] = dis[p] + i->val, cur.push({dis[SON], SON});
    }
}

int main(){
    H = read < ll >();
    x = read(), y = read(), z = read();
    if(x == 1 || y == 1 || z == 1)printf("%lld\n", H), exit(0);
    for(int i = 0; i < x; ++i)
        head[i] = new Edge{head[i], (i + y) % x, y},
        head[i] = new Edge{head[i], (i + z) % x, z};
    Dijkstra();
    for(int i = 0; i < x; ++i)
        if(H >= dis[i])
            ans += (H - dis[i]) / x + 1;
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