#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}
#define ROPNEW_NODE void* Node::operator new(size_t){static Node* P = nd; return P++;}

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

int N, R, G, B, M, MOD;
int tot(0);
int len[110];
int nxt[110];
bitset < 110 > vis;
int dp[30][30][30];
int ans(0);

int main(){
    R = read(), B = read(), G = read(), M = read(), MOD = read();
    N = R + G + B;
    auto Make = [](void)->int{
        vis.reset(), tot = 0;
        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 1;
        for(int s = 1; s <= N; ++s){
            if(vis[s])continue;
            vis[s] = true;
            int clen(1);
            int cur = nxt[s];
            while(cur != s)vis[cur] = true, cur = nxt[cur], ++clen;
            len[++tot] = clen;
        }
        for(int c = 1; c <= tot; ++c)
            for(int i = R; i >= 0; --i)
                for(int j = G; j >= 0; --j)
                    for(int k = B; k >= 0; --k){
                        if(i >= len[c])(dp[i][j][k] += dp[i - len[c]][j][k]) %= MOD;
                        if(j >= len[c])(dp[i][j][k] += dp[i][j - len[c]][k]) %= MOD;
                        if(k >= len[c])(dp[i][j][k] += dp[i][j][k - len[c]]) %= MOD;
                    }
        return dp[R][G][B];
    };
    for(int i = 1; i <= M; ++i){
        for(int j = 1; j <= N; ++j)nxt[j] = read();
        (ans += Make()) %= MOD;
    }
    for(int i = 1; i <= N; ++i)nxt[i] = i;
    (ans += Make()) %= MOD;
    auto qpow = [](ll a, ll b)->ll{
        ll ret(1), mul(a);
        while(b){
            if(b & 1)ret = ret * mul % MOD;
            b >>= 1;
            mul = mul * mul % MOD;
        }return ret;
    };
    printf("%lld\n", ans * qpow(M + 1, MOD - 2) % MOD);
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