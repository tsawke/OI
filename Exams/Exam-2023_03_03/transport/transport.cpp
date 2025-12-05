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

#define MOD (ll)(1e9 + 7)

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[410000];
ROPNEW;
Edge* head[210000];

int N, Q;
ll val[210000];
int siz[210000], fa[210000];
ll ans(0), cans(0), sum(0);

void dfs_pre(int p = 1, int fa = 0){
    ::fa[p] = fa, siz[p] = 1;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_pre(SON, p);
        siz[p] += siz[SON];
    }
}

void dfs_ans(int p, int fa, ll cur){
    (cur += val[p]) %= MOD;
    (cans += cur) %= MOD;
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs_ans(SON, p, cur);
}

void dfs(int p, int fa, int tsiz, ll cur){
    // printf("at p = %d, val = %lld\n", p, cur);
    (ans += cur) %= MOD;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs(SON, p, tsiz, ((cur - siz[SON] * val[p] % MOD + (tsiz - siz[SON]) * val[SON] % MOD) % MOD + MOD) % MOD);
    }
}
void dfs_valsum(int p, int fa){
    (sum += val[p]) %= MOD;
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa)dfs_valsum(SON, p);
}

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

class BIT{
private:
    ll tr[110000];
public:
    int lowbit(int x){return x & -x;}
    void Modify(int x, ll v){while(x <= N)(tr[x] += v) %= MOD, x += lowbit(x);}
    ll Query(int x){ll ret(0); while(x)(ret += tr[x]) %= MOD, x -= lowbit(x); return ret;}
}bit;

int main(){
    freopen("transport.in", "r", stdin);
    freopen("transport.out", "w", stdout);
    N = read(), Q = read();
    for(int i = 1; i <= N; ++i)val[i] = 1;
    if((N <= 10000 && Q <= 10000) || Q == 1 || (ll)N * Q <= (ll)(2e8)){
        for(int i = 1; i <= N - 1; ++i){
            int s = read(), t = read();
            head[s] = new Edge{head[s], t};
            head[t] = new Edge{head[t], s};
        }
        ll inv2 = qpow(2, MOD - 2);
        dfs_pre();
        while(Q--){
            int opt = read();
            if(opt == 1){
                int p = read(), v = read();
                (val[p] += v) %= MOD;
            }else{
                int p = read();
                ans = cans = sum = 0;
                dfs_valsum(p, fa[p]), dfs_ans(p, fa[p], 0), dfs(p, fa[p], siz[p], cans);
                printf("%lld\n", ((ans - (ans - sum + MOD) % MOD * inv2 % MOD) % MOD + MOD) % MOD);
            }
        }
    }else{
        for(int i = 1; i <= N - 1; ++i)read(), read();
        for(int i = 1; i <= N; ++i)bit.Modify(i, 1);
        while(Q--){
            int opt = read();
            if(opt == 1){
                int p = read(), v = read();
                bit.Modify(p, v);
            }else{
                int l = read(), r = N;
                printf("%lld\n", (bit.Query(r) - bit.Query(l - 1) + MOD) % MOD * (r - l + 1) % MOD);
            }
        }//fake
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