#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;

#define LIM (210000)
#define MOD (998244353ll)

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    void* operator new(size_t);
}ed[LIM << 1];
void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
Edge* head[LIM];

int N, M, K;
pair < int, int > edgs[LIM];
int son_of_edge[LIM];
int fa[LIM];
int val[LIM];
bitset < LIM > vis;

int route[LIM];
ll cnt[1 << 24];

ll dp[1 << 24];
ll fact[LIM], invf[LIM];

int MASK;

int main(){
    auto qpow = [](ll a, ll b)->ll{
        ll ret(1), mul(a);
        while(b){
            if(b & 1)ret = ret * mul % MOD;
            b >>= 1, mul = mul * mul % MOD;
        }return ret;
    };
    fact[0] = 1;
    for(int i = 1; i < LIM; ++i)fact[i] = fact[i - 1] * i % MOD;
    invf[LIM - 1] = qpow(fact[LIM - 1], MOD - 2);
    for(int i = LIM - 1 - 1; i >= 0; --i)invf[i] = invf[i + 1] * (i + 1) % MOD;

    N = read(), M = read(), K = read();

    MASK = (1 << M) - 1;

    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
        edgs[i] = {s, t};
    }
    
    auto dfs_son = [](auto&& self, int p = 1)->void{
        vis[p] = true;
        for(auto i = head[p]; i; i = i->nxt)
            if(!vis[i->to])fa[i->to] = p, self(self, i->to);
    }; dfs_son(dfs_son);

    for(int i = 1; i <= M; ++i){
        int t = read();
        int son = fa[edgs[t].second] == edgs[t].first ? edgs[t].second : edgs[t].first;
        val[son] |= 1 << (i - 1);
    }

    vis.reset();
    auto dfs = [](auto&& self, int p = 1, int cur = 0)->void{
        val[p] |= cur, vis[p] = true;
        for(auto i = head[p]; i; i = i->nxt)
            if(!vis[i->to])self(self, i->to, val[p]);
    }; dfs(dfs);
    
    for(int i = 1; i <= K; ++i){
        int s = read(), t = read();
        ++cnt[route[i] = val[s] ^ val[t]];


        // printf("Route of %d is: ", i);
        // for(int j = 0; j < M; ++j)printf("%d ", (route[i] >> j) & 1 ? 1 : 0);
        // printf(",  val = %d\n", route[i]);
    }

    if(cnt[MASK]){
        printf("1 %lld\n", cnt[MASK]);
        return 0;
    }

    memcpy(dp, cnt, sizeof cnt);

    // for(int S = 0; S <= MASK; ++S)printf("cnt[%d] = %lld\n", S, cnt[S]);

    for(int i = 0; i < M; ++i)
        for(int S = 0; S <= MASK; ++S)
            if((S >> i) & 1)(dp[S] += dp[S ^ (1 << i)]) %= MOD;
    
    // for(int S = 0; S <= MASK; ++S)printf("dp[%d] = %lld\n", S, dp[S]);

    auto C = [](ll N, ll M)->ll{
        if(M > N || M < 0 || N < 0)return 0;
        return fact[N] * invf[M] % MOD * invf[N - M] % MOD;
    };

    for(int d = 2; d <= M; ++d){
        ll ans(0);
        for(int S = 0; S <= MASK; ++S){
            ans +=
                (((__builtin_popcount(S)) & 1) ? -1 : 1) *
                C(dp[MASK ^ S], d) %
                MOD;
            ans = (ans % MOD + MOD) % MOD;
        }
        if(ans){
            printf("%lld %lld\n", d, ans);
            return 0;
        }
    }
    printf("-1\n");


    // fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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