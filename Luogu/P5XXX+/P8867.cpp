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
    Edge* rev;
    int to;
    bool vis;
    OPNEW;
}ed[4100000];
ROPNEW(ed);
Edge* head[1100000];
Edge* ehead[1100000];

int N, M;
int dfn[1100000], low[1100000], eBCC(0), belong[1100000];
int cnte[1100000], cntv[1100000];
int sume[1100000];
bool inS[1100000];
ll dp[1100000][2];
ll pow2[2100000];
ll ans(0);

void Tarjan(int p = 1){
    static stack < int > cur;
    static int cdfn(0);
    cur.push(p); inS[p] = true;
    low[p] = dfn[p] = ++cdfn;
    for(auto i = head[p]; i; i = i->nxt){
        if(i->vis)continue;
        i->vis = i->rev->vis = true;
        if(!dfn[SON]){
            Tarjan(SON);
            low[p] = min(low[p], low[SON]);
            if(low[SON] > dfn[p]){
                ++eBCC;
                while(true){
                    int tp = cur.top(); cur.pop();
                    belong[tp] = eBCC;
                    inS[tp] = false;
                    ++cntv[eBCC];
                    if(tp == SON)break;
                }
            }
        }else if(inS[SON])
            low[p] = min(low[p], dfn[SON]);
    }
    if(p == 1 && !cur.empty()){
        ++eBCC;
        while(true){
            int tp = cur.top(); cur.pop();
            belong[tp] = eBCC;
            inS[tp] = false;
            ++cntv[eBCC];
            if(tp == p)break;
        }
    }
}
void dfs_edge(int p = 1, int fa = 0){
    sume[p] = cnte[p];
    for(auto i = ehead[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_edge(SON, p);
        sume[p] += sume[SON] + 1;
    }
}
void MakeDP(int p = 1, int fa = 0){
    dp[p][0] = pow2[cnte[p]];
    dp[p][1] = (pow2[cntv[p]] - 1) * pow2[cnte[p]] % MOD;
    for(auto i = ehead[p]; i; i = i->nxt){
        if(SON == fa)continue;
        MakeDP(SON, p);
        dp[p][1] = (dp[p][1] * dp[SON][0] * 2 % MOD + dp[p][1] * dp[SON][1] % MOD + dp[p][0] * dp[SON][1] % MOD) % MOD;
        dp[p][0] = dp[p][0] * dp[SON][0] * 2 % MOD;
    }(ans += (p == 1 ? dp[p][1] : dp[p][1] * pow2[sume[1] - sume[p] - 1] % MOD)) %= MOD;
}

int main(){
    N = read(), M = read();
    pow2[0] = 1;
    for(int i = 1; i <= 2010000; ++i)pow2[i] = pow2[i - 1] * 2 % MOD;
    for(int i = 1; i <= M; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], npt, t};
        head[t] = new Edge{head[t], npt, s};
        head[s]->rev = head[t], head[t]->rev = head[s];
    }Tarjan();
    for(int p = 1; p <= N; ++p)
        for(auto i = head[p]; i; i = i->nxt)
            if(belong[p] != belong[SON])
                ehead[belong[p]] = new Edge{ehead[belong[p]], npt, belong[SON]};
            else ++cnte[belong[p]];
    for(int i = 1; i <= eBCC; ++i)cnte[i] >>= 1;
    dfs_edge();
    MakeDP();
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