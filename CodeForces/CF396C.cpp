#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
// using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (1000000007)

template<typename T = int>
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[610000];
ROPNEW(ed);
Edge* head[310000];

int N, Q;
int idx[310000];
int dep[310000], siz[310000];

void dfs(int p = 1, int fa = 0){
    static int cnt(0);
    idx[p] = ++cnt;
    dep[idx[p]] = dep[idx[fa]] + 1;
    ++siz[idx[p]];
    for(auto i = head[p]; i; i = i->nxt)if(SON != fa)dfs(SON, p), siz[idx[p]] += siz[idx[SON]];
}

class BIT{
private:
    pair < ll, ll > tr[310000];
public:
    int lowbit(int x){return x & -x;}
    void add(int x, int u, ll base, ll k){
        while(x <= N)
            tr[x] = {
                ((tr[x].first + base + MOD) % MOD + (dep[u] * k + MOD) % MOD + MOD) % MOD,
                (tr[x].second + k + MOD) % MOD
            },
            x += lowbit(x);
    }
    void modify(int l, int r, int u, ll base, ll k){
        // printf("Modifying [%d, %d] => u = %d, x = %lld, k = %lld\n", l, r, u, base, k);
        add(l, u, base, k);
        add(r + 1, u, -base, -k);
    }
    ll query(int x){
        int rx = x;
        ll ret(0);
        while(x)ret = ((ret + tr[x].first) % MOD - tr[x].second * dep[rx] % MOD + MOD) % MOD, x -= lowbit(x);
        return ret;
    }
}bit;

int main(){
    N = read();
    for(int i = 2; i <= N; ++i){
        int fa = read();
        head[i] = new Edge{head[i], fa};
        head[fa] = new Edge{head[fa], i};
    }dfs();
    Q = read();
    while(Q--){
        // for(int i = 1; i <= N; ++i)printf("%lld%c", ta.query(i), i == N ? '\n' : ' ');
        int opt = read();
        if(opt == 1){
            int v = read(), x = read(), k = read();
            bit.modify(idx[v], idx[v] + siz[idx[v]] - 1, idx[v], x, k);
        }else{
            int v = read();
            printf("%lld\n", bit.query(idx[v]) % MOD);
        }
    }

    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
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