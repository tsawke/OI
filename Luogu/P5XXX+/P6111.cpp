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
    int val;
    OPNEW;
}ed[11000];
ROPNEW(ed);
Edge* head[5100];
vector < int > vert[5100];
int N, Q;

void dfs(int rt, int p, int fa = 0, int cur = 0){
    if(cur)vert[rt].emplace_back(cur);
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs(rt, SON, p, cur ? min(cur, i->val) : i->val);
}

int main(){
    N = read(), Q = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read(), val = read();
        head[s] = new Edge{head[s], t, val};
        head[t] = new Edge{head[t], s, val};
    }
    for(int i = 1; i <= N; ++i)dfs(i, i), sort(vert[i].begin(), vert[i].end());
    while(Q--){
        int dis = read(), p = read();
        printf("%d\n", (int)distance(lower_bound(vert[p].begin(), vert[p].end(), dis), vert[p].end()));
    }
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