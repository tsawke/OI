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

#define MOD (ll)(1e9 + 7)

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[11000];
ROPNEW(ed);
Edge* head[5100];

int N, K;
unordered_set < int > exist[5100];
ll dp[5100][5100];

void dfs(int p = 1, int fa = 0){
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs(SON, p);
    if(!head[p]->nxt && p != 1)
        for(auto ex : exist[p])dp[p][ex] = 1;
    else{
        for(auto ex : exist[p])
            for(auto i = head[p]; i; i = i->nxt)
                if(SON != fa)
                    for(auto exs : exist[SON])
                        if(exs != ex)
                            (dp[p][ex] += dp[SON][exs]) %= MOD;
    }
}

int main(){
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    N = read(), K = read();
    for(int i = 1; i <= N; ++i){
        int c = read();
        while(c--)exist[i].insert(read());
    }
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs();
    ll ans(0);
    for(auto ex : exist[1])(ans += dp[1][ex]) %= MOD;
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