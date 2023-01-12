#define _USE_MATH_DEFINES
#include <bits/extc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW(arr) void* Edge::operator new(size_t){static Edge* P = arr; return P++;}

using namespace std;
using namespace __gnu_pbds;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD 998244353

template< typename T = int >
inline T read(void);

int N;
int P[210000], Q[210000];
int cnt[210000];
int pos[210000][2];
int f[210000];
bool vis[210000];
int ans(1);

class UnionFind{
private:
public:
    int fa[210000];
    int siz[210000];
    UnionFind(void){for(int i = 1; i <= 201000; ++i)fa[i] = i, siz[i] = 1;}
    int Find(int x){return x == fa[x] ? x : fa[x] = Find(fa[x]);}
    void Union(int origin, int son){
        if(Find(origin) == Find(son))return;
        siz[Find(origin)] += siz[Find(son)], fa[Find(son)] = Find(origin);
    }
}uf;

int main(){
    N = read();
    f[1] = 1, f[2] = 3;
    for(int i = 3; i <= N; ++i)f[i] = (ll)(f[i - 1] + f[i - 2]) % MOD;
    for(int i = 1; i <= N; ++i)P[i] = read(), pos[P[i]][cnt[P[i]]++] = i;
    for(int i = 1; i <= N; ++i)Q[i] = read(), pos[Q[i]][cnt[Q[i]]++] = i;
    for(int i = 1; i <= N; ++i)
        uf.Union(i, pos[P[i]][0] ^ pos[P[i]][1] ^ i),
        uf.Union(i, pos[Q[i]][0] ^ pos[Q[i]][1] ^ i);
    for(int i = 1; i <= N; ++i)if(uf.Find(i) == i)ans = (ll)ans * f[uf.siz[uf.Find(i)]] % MOD;
    printf("%d\n", ans);
    fprintf(stderr, "Time: %.6lf\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}

template < typename T >
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