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

#define MOD (998244353ll)

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[610000];
ROPNEW(ed);
Edge* head[310000];

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

int N;
int mxdep;
int inv2;
int dep[310000];
int fa[310000];
ll ans(0);
ll sum[310000][21], sum2[310000][21];

ll DP(int p, int i){
    if(i == 1)return 1;
    return ((sum[p][i] * sum[p][i] % MOD - sum2[p][i]) % MOD + MOD) % MOD * inv2 % MOD;
}
void dfs(int p = 1, int fa = 0){
    dep[p] = dep[fa] + 1;
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs(SON, p);
}

int main(){
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    inv2 = qpow(2, MOD - 2);
    N = read();
    if(N == 1)printf("1\n"), exit(0);
    mxdep = (int)log2(N);
    for(int i = 2; i <= N; ++i){
        fa[i] = read();
        head[i] = new Edge{head[i], fa[i]};
        head[fa[i]] = new Edge{head[fa[i]], i};
    }dfs();
    for(int cp = 1; cp <= N; ++cp){
        if(dep[cp] <= mxdep){
            sum[cp][1] = sum2[cp][1] = 1;
            ll cnt(1), cur(cp), lst(-1), lstDP(0);
            while(cur != 1){
                lst = cur;
                cur = fa[cur], ++cnt;
                ll tmp = DP(cur, cnt);
                (((sum[cur][cnt] -= lstDP) %= MOD) += MOD) %= MOD;
                (((sum2[cur][cnt] -= lstDP * lstDP % MOD) %= MOD) += MOD) %= MOD;
                lstDP = tmp;
                (sum[cur][cnt] += DP(lst, cnt - 1)) %= MOD;
                (sum2[cur][cnt] += DP(lst, cnt - 1) * DP(lst, cnt - 1) % MOD) %= MOD;
            }
        }ans = 0;
        for(int i = 1; i <= mxdep; ++i)(ans += DP(1, i)) %= MOD;
        printf("%lld\n", ans);
    }
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