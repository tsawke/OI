#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define PI M_PI
#define E M_E
#define npt nullptr
#define SON i->to
#define OPNEW void* operator new(size_t)
#define ROPNEW void* Edge::operator new(size_t){static Edge* P = ed; return P++;}

using namespace std;

mt19937 rnd(random_device{}());
int rndd(int l, int r){return rnd() % (r - l + 1) + l;}
bool rnddd(int x){return rndd(1, 100) <= x;}

typedef unsigned int uint;
typedef unsigned long long unll;
typedef long long ll;
typedef long double ld;

#define MOD (201314)

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    OPNEW;
}ed[110000];
ROPNEW;
Edge* head[51000];

int N, M;
struct Query{
    int endp;
    int val;
    int idx;
    bool flag; //false -> [1, l - 1], true -> [1, r]
};
basic_string < Query > qs;
ll ans[51000];

class SegTree{
private:
    ll tr[51000 << 2];
    ll lz[51000 << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    void Pushup(int p){tr[p] = (tr[LS] + tr[RS]) % MOD;}
    void Pushdown(int p, int gl, int gr){
        if(!lz[p])return;
        (lz[LS] += lz[p]) %= MOD, (lz[RS] += lz[p]) %= MOD;
        (tr[LS] += lz[p] * (MID - gl + 1) % MOD) %= MOD, (tr[RS] += lz[p] * (gr - (MID + 1) + 1) % MOD) %= MOD;
        lz[p] = 0;
    }
    ll Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p];
        if(gr < l || r < gl)return 0;
        Pushdown(p, gl, gr);
        return (Query(l, r, LS, gl, MID) + Query(l, r, RS, MID + 1, gr)) % MOD;
    }
    void Modify(int l, int r, int v = 1, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return (tr[p] += (gr - gl + 1) * v % MOD) %= MOD, (lz[p] += v) %= MOD, void();
        Pushdown(p, gl, gr);
        if(l <= MID)Modify(l, r, v, LS, gl, MID);
        if(MID + 1 <= r)Modify(l, r, v, RS, MID + 1, gr);
        Pushup(p);
    }
}st;

int dep[51000], dfn[51000], fa[51000], hson[51000], siz[51000], top[51000], idx[51000];

void dfs_pre(int p = 1, int ffa = 0){
    fa[p] = ffa;
    dep[p] = dep[ffa] + 1;
    siz[p] = 1;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == ffa)continue;
        dfs_pre(SON, p);
        siz[p] += siz[SON];
        if(siz[SON] > siz[hson[p]])hson[p] = SON;
    }
}
void dfs_make(int p = 1, int tp = 1){
    top[p] = tp;
    static int cdfn(0);
    dfn[p] = ++cdfn;
    idx[cdfn] = p;
    if(hson[p])dfs_make(hson[p], tp);
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa[p] || SON == hson[p])continue;
        dfs_make(SON, SON);
    }
}
void ModifyTree(int p){
    while(top[p] != 1)
        st.Modify(dfn[top[p]], dfn[p]), p = fa[top[p]];
    st.Modify(1, dfn[p]);
}
ll QueryTree(int p){
    ll ret(0);
    while(top[p] != 1)
        (ret += st.Query(dfn[top[p]], dfn[p])) %= MOD, p = fa[top[p]];
    (ret += st.Query(1, dfn[p])) %= MOD;
    return ret;
}

int main(){
    N = read(), M = read();
    for(int i = 2; i <= N; ++i){
        int s = i, t = read() + 1;
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs_pre(), dfs_make();
    for(int i = 1; i <= M; ++i){
        int l = read() + 1, r = read() + 1, p = read() + 1;
        qs += {Query{l - 1, p, i, false}, Query{r, p, i, true}};
    }sort(qs.begin(), qs.end(), [](const Query &a, const Query &b)->bool{return a.endp < b.endp;});
    int cur(0);
    for(auto q : qs){
        for(int i = cur + 1; i <= q.endp; ++i)ModifyTree(i);
        cur = q.endp;
        ans[q.idx] += (q.flag ? 1 : -1) * QueryTree(q.val);
    }
    for(int i = 1; i <= M; ++i)printf("%lld\n", (ans[i] % MOD + MOD) % MOD);
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