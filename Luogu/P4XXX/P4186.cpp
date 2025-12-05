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

int N, S;
int ans(0);
struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[210000];
ROPNEW(ed);
Edge* head[110000];

int mn[110000];
int dep[110000];
int dfs_pre(int p = S, int fa = 0){
    dep[p] = dep[fa] + 1;
    if(!head[p]->nxt)mn[p] = dep[p];
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)
            mn[p] = min(mn[p], dfs_pre(SON, p));
    return mn[p];
}
void dfs(int p = S, int fa = 0){
    if(dep[p] > mn[p] - dep[p])return ++ans, void();
    for(auto i = head[p]; i; i = i->nxt)if(SON != fa)dfs(SON, p);
}
int main(){
    memset(mn, 0x3f, sizeof mn);
    N = read(), S = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }if(!head[S]->nxt)printf("1\n"), exit(0);
    dfs_pre();
    dfs();
    printf("%d\n", ans);
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