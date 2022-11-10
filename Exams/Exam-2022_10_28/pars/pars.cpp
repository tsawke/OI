#define USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long unll;
typedef unsigned int uint;
typedef long double ld;

template < typename T = int >
inline T read(void){
    T ret(0);
    short flag(1);
    char c = getchar();
    while(!isdigit(c) && c != '-')c = getchar();
    if(c == '-')flag = -1, c = getchar();
    while(isdigit(c)){
        ret *= 10;
        ret += int(c - '0');
        c = getchar();
    }return ret * flag;
}

struct Edge{
    Edge* nxt;
    int to;
    void* operator new(size_t);
}ed[11000];
void* Edge::operator new(size_t){static Edge* P = ed; return ++P;}
Edge* head[5100];

int N;
ll f[5100];
int ffa[5100];
bool del[20];
bool vis[20];
int siz[5100];
vector < int > rnk;
ll ans(LONG_LONG_MAX / 2);

void dfs_siz(int p = 1, int fa = 0){
    siz[p] = 1;
    ffa[p] = fa;
    for(auto i = head[p]; i; i = i->nxt){
        if(i->to != fa){
            dfs_siz(i->to, p);
            if(!del[i->to])
                siz[p] += siz[i->to];
        }
    }
}

void del_son(int p){
    for(int i = 1; i <= N; ++i)printf("%d%c", ffa[i], i == N ? '\n' : ' ');
    printf("cur = %d\n", p);
    del[p] = true;
    for(auto i = head[p]; i; i = i->nxt){
        if(i->to != ffa[p])del_son(i->to);
    }
}

bool check(void){
    for(int i = 1; i <= N; ++i){
        if(i == 1)continue;
        if(!del[i])return false;
    }return true;
}

void Build(void){
    int cnt(0);
    ll cur(0);
    memset(del, false, sizeof del);
    for(auto p : rnk){
        if(del[p])continue;
        del_son(p);
        del[p] = false;
        dfs_siz();
        cur += f[siz[p]];
    }
    ans = min(ans, cur);
}

void dfs(int dep = 1){
    if((double)clock() / CLOCKS_PER_SEC > 0.8){
        printf("%lld\n", min(ans, f[N]));
        exit(0);
    }
    if(dep > N){
        Build();
    }
    for(int i = 1; i <= N; ++i){
        if(vis[i])continue;
        vis[i] = true;
        rnk.emplace_back(i);
        dfs(dep + 1);
        rnk.pop_back();
        vis[i] = false;
    }
}

int main(){
    freopen("pars.in", "r", stdin);
    freopen("pars.out", "w", stdout);
    N = read();
    for(int i = 2; i <= N; ++i)f[i] = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }
    dfs_siz();
    dfs();
    printf("%lld\n", min(ans, f[N]));
    return 0;
}