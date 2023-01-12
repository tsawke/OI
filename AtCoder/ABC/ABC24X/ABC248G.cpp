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

#define MOD (ll)(998244353)

template< typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[210000];
ROPNEW(ed);
Edge* head[110000];

int N;
ll ans(0);
int a[110000];
struct Paths{
    ll sum, cnt;
    friend const Paths operator + (const Paths &a, const Paths &b){
        return Paths{(a.sum + b.sum) % MOD, (a.cnt + b.cnt) % MOD};
    }
    friend Paths operator += (Paths &origin, const Paths &add){
        return origin = origin + add;
    }
};

ll Cal(const map < int, Paths > &a, const map < int, Paths > &b){
    ll ret(0);
    for(auto mpa : a)for(auto mpb : b)
        (ret += (ll)__gcd(mpa.first, mpb.first) * (
            mpa.second.sum * mpb.second.cnt % MOD +
            mpa.second.cnt * mpb.second.sum % MOD +
            mpa.second.cnt * mpb.second.cnt % MOD
        )) %= MOD;
    return ret;
}
auto Extend(const map < int, Paths > &origin, int val){
    map < int, Paths > ret;
    for(auto mp : origin)ret[__gcd(mp.first, val)] += Paths{mp.second.sum + mp.second.cnt, mp.second.cnt};
    return ret;
}
void Union(map < int, Paths > &origin, const map < int, Paths > add){
    for(auto mp : add)origin[mp.first] += mp.second;
}
map < int, Paths > dfs(int p = 1, int fa = 0){
    map < int, Paths > ret;
    ret.insert({a[p], Paths{0, 1}});
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        auto son = Extend(dfs(SON, p), a[p]);
        (ans += Cal(ret, son)) %= MOD;
        Union(ret, son);
    }return ret;
}

int main(){
    N = read();
    for(int i = 1; i <= N; ++i)a[i] = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs();
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