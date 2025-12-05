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

int N;
int a[210000];
int ans(INT_MAX);
bitset < 12 > vis;
bitset < 12 > exist[12];
bool flag(true);
int cnt(0);
basic_string < int > cur;

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[1100000];
ROPNEW(ed);
Edge* head[12];

void dfs_vis(int p, int fa = 0){
    vis[p] = true, ++cnt;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        if(vis[SON]){flag = false; return;}
        dfs_vis(SON, p);
    }
}
bool Check(void){
    memset(head, 0, sizeof head);
    for(int i = 0; i <= 11; ++i)exist[i].reset();
    vis.reset();
    int tot = cur.size();
    if(tot <= 1)return true;
    for(auto p : cur){
        int mn(INT_MAX), mnp(-1);
        for(auto q : cur)
            if(q != p && (a[p] ^ a[q]) < mn)mn = a[p] ^ a[q], mnp = q;
        if(exist[p][mnp])continue;
        exist[p][mnp] = exist[mnp][p] = true;
        head[p] = new Edge{head[p], mnp};
        head[mnp] = new Edge{head[mnp], p};
    }flag = true, cnt = 0; dfs_vis(cur.front());
    return flag && cnt == tot;
}
void dfs(int p = 1){
    if(p > N){
        if(Check())ans = min(ans, N - (int)cur.size());
        return;
    }
    dfs(p + 1);
    cur += p;
    dfs(p + 1);
    cur.pop_back();
}

int main(){
    freopen("star.in", "r", stdin);
    freopen("star.out", "w", stdout);
    N = read();
    if(N > 10)printf("qwq\n"), exit(0);
    for(int i = 1; i <= N; ++i)a[i] = read();
    dfs();
    printf("%d\n", ans);
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