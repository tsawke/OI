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

#define MAXN 310000

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[610000];
ROPNEW(ed);
Edge* head[MAXN << 1];

int N, M;
ll ans[MAXN];
ll d[MAXN];
int dep[MAXN];
vector < pair < int, int > /*depth, value*/ > mdf[MAXN];

void dfs(int p = 1, int fa = 0, ll cur = 0){
    dep[p] = dep[fa] + 1;
    cur += d[dep[p]];
    for(auto m : mdf[p])
        cur += m.second,
        (dep[p] + m.first + 1 < MAXN) ? (void)(d[dep[p] + m.first + 1] -= m.second) : void();
    ans[p] = cur;
    for(auto i = head[p]; i; i = i->nxt)
        SON != fa ? dfs(SON, p, cur) : void();
    for(auto m : mdf[p])
        if(dep[p] + m.first + 1 < MAXN)d[dep[p] + m.first + 1] += m.second;
}

int main(){
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }M = read();
    for(int i = 1; i <= M; ++i){
        int vt = read(), dep = read(), val = read();
        mdf[vt].push_back({dep, val});
    }dfs();
    for(int i = 1; i <= N; ++i)printf("%lld%c", ans[i], i == N ? '\n' : ' ');
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
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