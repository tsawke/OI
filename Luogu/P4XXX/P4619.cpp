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

#define LIM (110000)
#define MOD (ll)(1e9 + 7)

template < typename T = int >
inline T read(void);

int A, B, C;
ll mu[LIM + 100], smu[LIM + 100];
ll fa[LIM + 100], fb[LIM + 100], fc[LIM + 100];
int val[LIM + 100];
int deg[LIM + 100];
bitset < LIM + 100 > vis;
bitset < LIM + 100 > notPrime;
basic_string < int > Prime;

struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[LIM << 5];
ROPNEW;
Edge* head[LIM];

ll qpow(ll a, ll b){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % MOD;
        b >>= 1;
        mul = mul * mul % MOD;
    }return ret;
}

int main(){mu[1] = 1;
    for(int i = 2; i <= LIM; ++i){
        if(!notPrime[i])Prime += i, mu[i] = -1;
        for(auto p : Prime){
            if((ll)i * p > LIM)break;
            mu[i * p] = i % p == 0 ? 0 : mu[i] * mu[p];
            notPrime[i * p] = true;
            if(i % p == 0)break;
        }
    }
    int T = read();
    while(T--){
        ll ans(0);
        A = read(), B = read(), C = read();
        int mn = min({A, B, C}), mx = max({A, B, C});
        memset(fa, 0, sizeof fa), memset(fb, 0, sizeof fb), memset(fc, 0, sizeof fc);
        memset(deg, 0, sizeof deg), memset(head, 0, sizeof head);
        for(int i = 1; i <= A; ++i)
            for(int j = i; j <= mx; j += i)(fa[i] += A / j) %= MOD;
        for(int i = 1; i <= B; ++i)
            for(int j = i; j <= mx; j += i)(fb[i] += B / j) %= MOD;
        for(int i = 1; i <= C; ++i)
            for(int j = i; j <= mx; j += i)(fc[i] += C / j) %= MOD;
        for(int i = 1; i <= mn; ++i)(ans += fa[i] * fb[i] * fc[i] * mu[i] * mu[i] * mu[i]) %= MOD;
        struct Edg{int s, t, v;}; basic_string < Edg > edgs;
        for(int g = 1; g <= mn; ++g){
            for(int i = 1; (ll)i * g <= mx; ++i){
                if(!mu[i * g])continue;
                for(int j = i + 1; (ll)i * j * g <= mx; ++j){
                    if(!mu[j * g] || __gcd(i, j) != 1)continue;
                    int s = i * g, t = j * g, lcm = i * j * g;
                    (ans += ((mu[s] * mu[s] * mu[t] * ((fa[s] * fb[lcm] * fc[lcm] + fa[lcm] * fb[s] * fc[lcm] + fa[lcm] * fb[lcm] * fc[s]) % MOD)) + MOD) % MOD) %= MOD;
                    (ans += ((mu[s] * mu[t] * mu[t] * ((fa[t] * fb[lcm] * fc[lcm] + fa[lcm] * fb[t] * fc[lcm] + fa[lcm] * fb[lcm] * fc[t]) % MOD)) + MOD) % MOD) %= MOD;
                    ++deg[s], ++deg[t];
                    edgs += {s, t, lcm};
                    // head[s] = new Edge{head[s], t, lcm};
                    // head[t] = new Edge{head[t], s, lcm};
                }
            }
        }
        for(auto edg : edgs){
            auto [s, t, v] = edg;
            if(deg[s] < deg[t] || (deg[s] == deg[t] && s > t))swap(s, t);
            head[s] = new Edge{head[s], t, v};
        }
        for(int s = 1; s <= mx; ++s){
            if(!mu[s])continue;
            // vis.reset();
            // memset(val, 0, sizeof val);
            for(auto i = head[s]; i; i = i->nxt)vis[SON] = true, val[SON] = i->val;
            for(auto i = head[s]; i; i = i->nxt){
                if(!mu[SON])continue;
                for(auto j = head[SON]; j; j = j->nxt){
                    if(!vis[j->to] || !mu[j->to])continue;
                    (ans += mu[s] * mu[SON] * mu[j->to] * (
                        fa[val[j->to]] * fb[j->val] * fc[i->val] + fa[val[j->to]] * fb[i->val] * fc[j->val] +
                        fa[j->val] * fb[val[j->to]] * fc[i->val] + fa[j->val] * fb[i->val] * fc[val[j->to]] +
                        fa[i->val] * fb[val[j->to]] * fc[j->val] + fa[i->val] * fb[j->val] * fc[val[j->to]]
                    ) % MOD) %= MOD;
                }
            }
            for(auto i = head[s]; i; i = i->nxt)vis[SON] = false, val[SON] = 0;
        }printf("%lld\n", (ans % MOD + MOD) % MOD);
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