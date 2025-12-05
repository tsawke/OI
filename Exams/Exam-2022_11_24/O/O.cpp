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

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[110000];
ROPNEW(ed);
Edge* head[51000];

int N, Q;
ll val[51000];
bool all1(true);

int dep[51000], dfn[51000], ffa[51000], top[51000], idx[51000], siz[51000], hson[51000];

void dfs_pre(int p = 1, int fa = 0){
    ffa[p] = fa;
    dep[p] = dep[fa] + 1;
    siz[p] = 1;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_pre(SON, p);
        siz[p] += siz[SON];
        if(siz[SON] > siz[hson[p]])hson[p] = SON;
    }
}
void dfs(int p = 1, int tp = 1){
    static int cdfn(0);
    dfn[p] = ++cdfn;
    idx[cdfn] = p;
    top[p] = tp;
    if(hson[p])dfs(hson[p], tp);
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == ffa[p] || SON == hson[p])continue;
        dfs(SON, SON);
    }
}

int GetPathLen(int s, int t){
    int ret(0);
    while(top[s] != top[t]){
        if(dep[top[s]] < dep[top[t]])swap(s, t);
        ret += dfn[top[s]] - dfn[s] + 1;
        s = ffa[top[s]];
    }if(dep[s] < dep[t])swap(s, t);
    ret += dfn[s] - dfn[t] + 1;
    return ret;
}

int main(){
    freopen("O.in", "r", stdin);
    freopen("O.out", "w", stdout);
    N = read();
    for(int i = 1; i <= N; ++i){
        val[i] = read < ll >();
        if(val[i] != 1)all1 = false;
    }
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }

    if(all1){
        dfs_pre(), dfs();
        int Q = read();
        while(Q--){
            int opt = read();
            if(opt == 0){
                read(), read(), read();
                continue;
            }else{
                int s = read(), t = read(), k = read();
                int len = GetPathLen(s, t);
                printf("%d\n", len / k + (len % k == 0 ? 0 : 1));
            }
        }
        exit(0);
    }
    for(int i = 1; i <= 114514; ++i)printf("qwq\n");
    exit(0);

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