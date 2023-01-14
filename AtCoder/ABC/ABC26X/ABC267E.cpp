#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template < typename T = int >
inline T read(void);

int N, M;
ll A[210000];
ll cost[210000];
ll ans(LONG_LONG_MIN);
bitset < 210000 > vis;

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[410000];
ROPNEW;
Edge* head[210000];

tree < pair < ll, int >, null_type, less < pair < ll, int > >, rb_tree_tag, tree_order_statistics_node_update > tr;

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)A[i] = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
        cost[s] += A[t], cost[t] += A[s];
    }make_pair(cost[1], 1);
    for(int i = 1; i <= N; ++i)tr.insert({cost[i], i});
    for(int c = 1; c <= N; ++c){
        auto it = tr.find_by_order(0);
        ans = max(ans, it->first);
        vis[it->second] = true;
        for(auto i = head[it->second]; i; i = i->nxt)
            if(!vis[SON])
                tr.erase({cost[SON], SON}),
                tr.insert({cost[SON] -= A[it->second], SON});
        tr.erase({it->first, it->second});
    }printf("%lld\n", ans);
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