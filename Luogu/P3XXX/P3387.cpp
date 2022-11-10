#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

template< typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[410000];
ROPNEW(ed);
Edge* head[110000];
Edge* shead[110000];

int N, M;
int val[110000];
int SCC(0), cnt(0);
stack < int > cur;
int belong[110000], dfn[110000], low[110000], inS[110000], sum[110000];
int dis[110000], ind[110000];

void Tarjan(int p){
    low[p] = dfn[p] = ++cnt;
    cur.push(p), inS[p] = true;
    for(auto i = head[p]; i; i = i->nxt){
        if(!dfn[SON])Tarjan(SON), low[p] = min(low[p], low[SON]);
        else if(inS[SON])low[p] = min(low[p], dfn[SON]);
    }
    if(low[p] == dfn[p]){
        ++SCC;
        while(true){
            int tp = cur.top(); cur.pop();
            inS[tp] = false, belong[tp] = SCC;
            sum[SCC] += val[tp];
            if(tp == p)break;
        }
    }
}
int Topo(void){
    queue < int > q;
    for(int i = 1; i <= SCC; ++i)if(!ind[i])q.push(i), dis[i] = sum[i];
    while(!q.empty()){
        int tp = q.front(); q.pop();
        for(auto i = shead[tp]; i; i = i->nxt){
            dis[SON] = max(dis[SON], dis[tp] + sum[SON]);
            --ind[SON];
            if(!ind[SON])q.push(SON);
        }
    }
    int mx(-1);
    for(int i = 1; i <= SCC; ++i)mx = max(mx, dis[i]);
    return mx;
}

int main(){
    N = read(), M = read();
    for(int i = 1; i <= N; ++i)val[i] = read();
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
    }
    for(int i = 1; i <= N; ++i)if(!dfn[i])Tarjan(i);
    for(int p = 1; p <= N; ++p)
        for(auto i = head[p]; i; i = i->nxt)
            if(belong[p] != belong[SON])
                shead[belong[p]] = new Edge{shead[belong[p]], belong[SON]}, ++ind[belong[SON]];
    printf("%d\n", Topo());
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
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