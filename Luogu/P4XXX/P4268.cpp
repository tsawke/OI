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
}ed[210000];
ROPNEW(ed);
Edge* head[110000];

int N;
ll f[110000];
int leaf[110000], w[110000];
ll dis[110000];
ll mn;

void dfs_pre(int p = 1, int fa = 0){
    if(p != 1 && !head[p]->nxt)leaf[p] = 1, f[1] += dis[fa] + w[p];
    else dis[p] = p == 1 ? 0 : dis[fa] + w[p] + 1;
    for(auto i = head[p]; i; i = i->nxt)if(SON != fa)dfs_pre(SON, p), leaf[p] += leaf[SON];
}
void dfs(int p = 1, int fa = 0){
    if(p != 1 && head[p]->nxt)f[p] = f[fa] - (ll)leaf[p] * (w[p] + 1) + (ll)(leaf[1] - leaf[p]) * 3, mn = min(mn, f[p]);
    for(auto i = head[p]; i; i = i->nxt)if(SON != fa)dfs(SON, p);
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i){
        string dir;
        cin >> dir;
        w[i] = i == 1 ? 0 : (int)dir.size();
        int M = read();
        for(int j = 1; j <= M; ++j){
            int son = read();
            head[i] = new Edge{head[i], son};
            head[son] = new Edge{head[son], i};
        }
    }
    dfs_pre();
    mn = f[1];
    dfs();
    printf("%lld\n", mn);
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