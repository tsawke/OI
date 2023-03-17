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

namespace MillerRabin{
    int radix[10] = {0, 2, 3, 5, 7, 11, 13, 19, 17};
    ll qpow(ll a, ll b, ll MOD){
        ll ret(1), mul(a);
        while(b){
            if(b & 1)ret = (__int128_t)ret * mul % MOD;
            b >>= 1;
            mul = (__int128_t)mul * mul % MOD;
        }return ret;
    }
    bool Check(ll N){
        if(N <= 2 || !(N & 1))return N == 2;
        ll base(N - 1); int cpow(0);
        while(base % 2 == 0)base >>= 1, ++cpow;
        for(int t = 1; t <= 8; ++t){
            if(radix[t] % N == 0)continue;
            ll cur = qpow(radix[t] % N, base, N);
            if(cur == 1)continue;
            for(int i = 1; i <= cpow; ++i){
                if(cur == N - 1)break;
                cur = (__int128_t)cur * cur % N;
                if(i == cpow)return false;
            }
        }return true;
    }
}

int N;
set < int > Prime;
pair < int, ll > val[210000];
ll bval[210000];
unordered_map < int, int > bfact[210000];

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[410000];
ROPNEW;
Edge* head[210000];

ll tag[210000];
int ans[210000];

struct Node{
    Node *ls, *rs;
    int mxdep;
    OPNEW;
}nd[21000000];
ROPNEW_NODE;
// Node* root[210000];

const ll LIM = (ll)(1e18);

#define mxp(p) (p ? p->mxdep : 0)
#define MID ((gl + gr) >> 1)
void Pushup(Node* p){
    if(!p)return;
    p->mxdep = max(mxp(p->ls), mxp(p->rs));
}
Node* Insert(ll idx, int val, Node* lst, ll gl = 1, ll gr = LIM){
    // printf("Inserting idx = %lld, val = %d, gl = %lld, gr = %lld\n", idx, val, gl, gr);
    Node* p = lst ? new Node(*lst) : new Node{npt, npt, 0};
    if(gl == gr)return p->mxdep = max(p->mxdep, val), p;
    if(idx <= MID)p->ls = Insert(idx, val, p->ls, gl, MID);
    else p->rs = Insert(idx, val, p->rs, MID + 1, gr);
    return Pushup(p), p;
}
int Query(ll mxidx, Node* p, ll gl = 1, ll gr = LIM){
    if(!p)return 0;
    if(gr <= mxidx)return p->mxdep;
    if(mxidx < gl)return 0;
    if(mxidx <= MID)return Query(mxidx, p->ls, gl, MID);
    else return max(mxp(p->ls),  Query(mxidx, p->rs, MID + 1, gr));
}


unordered_map < int, unordered_map < int, Node* > > root;
unordered_map < int, int > cnt;
int ridx[210000];

// unordered_map < int, set < tuple < ll, int, int >, greater < tuple < ll, int, int > > > > mp;

unordered_map < int, set < int, greater < int > > > mp;

namespace BL{
    __int128_t qpow_without_mod(__int128_t a, __int128_t b){
        __int128_t ret(1), mul(a);
        while(b){
            if(b & 1)ret = ret * mul;
            b >>= 1;
            mul = mul * mul;
        }return ret;
    }
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
void Make(void){
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
}

}

int main(){
    freopen("immortal.in", "r", stdin);
    freopen("immortal.out", "w", stdout);
    N = read();
    if(N <= 1000){
        BL::Make();
        exit(0);
    }
    for(int i = 2; i <= N; ++i){
        int s = read(), t = i;
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }
    bool all1(true);
    for(int i = 1; i <= N; ++i){
        int p = read(); ll a = read < ll >(), b = read < ll >();
        val[i] = {p, a}, bval[i] = b; Prime.insert(p);
        if(b != 1)all1 = false;
    }
    if(false/*all1*/){

        auto dfs = [](auto&& self, int p = 1, int fa = 0, int dep = 1)->void{
            ll vpow = val[p].second;
            // for(auto )
            ridx[dep] = p;
            // auto it = mp[val[p].first].lower_bound({val[p].second + tag[val[p].first], dep, N + 114514});
            // printf("tot : ");
            // for(auto v : mp[val[p].first])printf("(%lld, %d, %d),  ", get < 0 >(v), get < 1 >(v), get < 2 >(v));
            // printf("\n");
            // if(it == mp[val[p].first].end())ans[p] = -1;
            // ans[p] = it == mp[val[p].first].end() ? -1 : get < 2 >(*it);
            // printf("p = %d, prime = %d, tag = %lld\n", p, val[p].first, tag[val[p].first]);
            __int128_t lim = (__int128_t)val[p].second + tag[val[p].first];
            auto ret = Query(lim > LIM ? LIM : lim, root[val[p].first][cnt[val[p].first]]);
            // for(auto p : Prime)ret = max(ret, Query(tag[p], root[p][cnt[p]]));
            ans[p] = ret ? ridx[ret] : -1;
            // if(it != mp[val[p].first].end())printf("Find p = %d, dep = %d, find = (%lld, %d, %d)\n", p, dep, get < 0 >(*it), get < 1 >(*it), get < 2 >(*it));
            // mp[val[p].first].insert({val[p].second, dep, p});
            ++cnt[val[p].first];
            root[val[p].first][cnt[val[p].first]] = Insert(lim > LIM ? LIM : lim, dep, root[val[p].first][cnt[val[p].first] - 1]);
            // printf("test querying p = %d, md = %d\n", p, root[val[p].first][cnt[val[p].first]]->mxdep);
            for(auto fac : bfact[p])tag[fac.first] += fac.second;//, printf("tag added %d <- %d\n", fac.first, fac.second);
            for(auto i = head[p]; i; i = i->nxt)
                if(SON != fa)self(self, SON, p, dep + 1);
            for(auto fac : bfact[p])tag[fac.first] -= fac.second;
            // mp[val[p].first].erase({val[p].second, dep, p});
            --cnt[val[p].first];
        };

        exit(0);
    }
    for(int i = 1; i <= N; ++i){
        if(MillerRabin::Check(bval[i])){
            if(bval[i] <= (ll)N && Prime.find(bval[i]) != Prime.end())bfact[i][bval[i]] = 1;
            continue;
        }
        ll sqr = (ll)sqrtl(bval[i]);
        if(sqr * sqr == bval[i] && MillerRabin::Check(sqr)){
            if(sqr <= (ll)N && Prime.find(sqr) != Prime.end())bfact[i][sqr] = 2;
            continue;
        }ll val = bval[i];
        for(auto p : Prime){
            if(p > val)break;
            while(val % p == 0)bfact[i][p]++, val /= p;
        }
    }
    auto dfs = [](auto&& self, int p = 1, int fa = 0, int dep = 1)->void{
        ridx[dep] = p;
        // auto it = mp[val[p].first].lower_bound({val[p].second + tag[val[p].first], dep, N + 114514});
        // printf("tot : ");
        // for(auto v : mp[val[p].first])printf("(%lld, %d, %d),  ", get < 0 >(v), get < 1 >(v), get < 2 >(v));
        // printf("\n");
        // if(it == mp[val[p].first].end())ans[p] = -1;
        // ans[p] = it == mp[val[p].first].end() ? -1 : get < 2 >(*it);
        // printf("p = %d, prime = %d, tag = %lld\n", p, val[p].first, tag[val[p].first]);
        __int128_t lim = (__int128_t)val[p].second + tag[val[p].first];
        auto ret = Query(lim > LIM ? LIM : lim, root[val[p].first][cnt[val[p].first]]);
        // for(auto p : Prime)ret = max(ret, Query(tag[p], root[p][cnt[p]]));
        ans[p] = ret ? ridx[ret] : -1;
        // if(it != mp[val[p].first].end())printf("Find p = %d, dep = %d, find = (%lld, %d, %d)\n", p, dep, get < 0 >(*it), get < 1 >(*it), get < 2 >(*it));
        // mp[val[p].first].insert({val[p].second, dep, p});
        ++cnt[val[p].first];
        root[val[p].first][cnt[val[p].first]] = Insert(lim > LIM ? LIM : lim, dep, root[val[p].first][cnt[val[p].first] - 1]);
        // printf("test querying p = %d, md = %d\n", p, root[val[p].first][cnt[val[p].first]]->mxdep);
        for(auto fac : bfact[p])tag[fac.first] += fac.second;//, printf("tag added %d <- %d\n", fac.first, fac.second);
        for(auto i = head[p]; i; i = i->nxt)
            if(SON != fa)self(self, SON, p, dep + 1);
        for(auto fac : bfact[p])tag[fac.first] -= fac.second;
        // mp[val[p].first].erase({val[p].second, dep, p});
        --cnt[val[p].first];
    }; dfs(dfs);
    for(int i = 1; i <= N; ++i)printf("%d\n", ans[i]);
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