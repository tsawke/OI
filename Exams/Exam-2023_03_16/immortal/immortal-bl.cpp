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

ll qpow(ll a, ll b, ll mod){
    ll ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul % mod;
        b >>= 1;
        mul = mul * mul % mod;
    }return ret;
}
__int128_t qpow_without_mod(__int128_t a, __int128_t b){
    __int128_t ret(1), mul(a);
    while(b){
        if(b & 1)ret = ret * mul;
        b >>= 1;
        mul = mul * mul;
    }return ret;
}


int N;
// set < int > Prime;
// pair < int, ll > val[210000];

__int128_t val[210000];
__int128_t bval[210000];
// unordered_map < int, int > bfact[210000];

// struct Edge{
//     Edge* nxt;
//     int to;
//     OPNEW;
// }ed[410000];
// ROPNEW;
// Edge* head[210000];

int fa[210000];

// ll tag[210000];
int ans[210000];
// unordered_map < int, set < tuple < ll, int, int >, greater < tuple < ll, int, int > > > > mp;

int main(){
    // freopen("immortal.in", "r", stdin);
    // freopen("immortal.out", "w", stdout);
    N = read();
    for(int i = 2; i <= N; ++i){
        int s = read();//, t = i;
        // head[s] = new Edge{head[s], t};
        // head[t] = new Edge{head[t], s};

        fa[i] = s;
    }
    for(int i = 1; i <= N; ++i){
        int p = read(); ll a = read < ll >(), b = read < ll >();
        // val[i] = {p, a},
        val[i] = qpow_without_mod(p, a);
        bval[i] = b;// Prime.insert(p);
    }
    memset(ans, -1, sizeof ans);
    for(int i = 1; i <= N; ++i){
        auto w = val[i];
        int nxt = fa[i];
        while(nxt){
            w = qpow_without_mod(w, bval[nxt]);
            if(w % val[nxt] == 0){ans[i] = nxt; break;}
            nxt = fa[nxt];
        }
    }
    for(int i = 1; i <= N; ++i)printf("%d\n", ans[i]);

    // for(int i = 1; i <= N; ++i){
    //     if(MillerRabin::Check(bval[i])){
    //         if(bval[i] <= (ll)N && Prime.find(bval[i]) != Prime.end())bfact[i][bval[i]] = 1;
    //         continue;
    //     }
    //     ll sqr = (ll)sqrtl(bval[i]);
    //     if(sqr * sqr == bval[i] && MillerRabin::Check(sqr)){
    //         if(sqr <= (ll)N && Prime.find(sqr) != Prime.end())bfact[i][sqr] = 2;
    //         continue;
    //     }ll val = bval[i];
    //     for(auto p : Prime){
    //         if(p > val)break;
    //         while(val % p == 0)bfact[i][p]++, val /= p;
    //     }
    // }
    // auto dfs = [](auto&& self, int p = 1, int fa = 0, int dep = 1)->void{
    //     auto it = mp[val[p].first].lower_bound({val[p].second + tag[val[p].first], dep, N + 114514});
    //     if(it == mp[val[p].first].end())ans[p] = -1;
    //     ans[p] = it == mp[val[p].first].end() ? -1 : get < 2 >(*it);
    //     mp[val[p].first].insert({val[p].second, dep, p});
    //     for(auto fac : bfact[p])tag[fac.first] += fac.second;
    //     for(auto i = head[p]; i; i = i->nxt)
    //         if(SON != fa)self(self, SON, p, dep + 1);
    //     for(auto fac : bfact[p])tag[fac.first] -= fac.second;
    //     mp[val[p].first].erase({val[p].second, dep, p});
    // }; dfs(dfs);
    // for(int i = 1; i <= N; ++i)printf("%d\n", ans[i]);
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
/*
5
1 2 2 3
2 1 2
3 1 1
2 2 2
3 1 1
2 1 2
*/