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

#define S(i) (S.at(i - 1))
#define INFLL (0x3f3f3f3f3f3f3f3fll)
#define INF (0x3f3f3f3f)
#define LIMIT (1100000)

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[3100000];
ROPNEW;
Edge* head[LIMIT];
Edge* vhead[LIMIT];

int N, Q;
int dep[LIMIT], dfn[LIMIT], idx[LIMIT], top[LIMIT], fa[LIMIT], hson[LIMIT], siz[LIMIT];
basic_string < int > S;
bitset < LIMIT > isKey;
int val[LIMIT];
ll ans(0);

class SegTree{
private:
    int tr[LIMIT << 2];
    #define LS (p << 1)
    #define RS (LS | 1)
    #define MID ((gl + gr) >> 1)
public:
    SegTree(void){memset(tr, 0x3f, sizeof tr);}
    void Pushup(int p){tr[p] = min(tr[LS], tr[RS]);}
    void Build(int p = 1, int gl = 1, int gr = N){
        if(gl == gr)return tr[p] = val[idx[gl = gr]], void();
        Build(LS, gl, MID), Build(RS, MID + 1, gr);
        Pushup(p);
    }
    int Query(int l, int r, int p = 1, int gl = 1, int gr = N){
        if(l <= gl && gr <= r)return tr[p];
        if(l > gr || r < gl)return INF;
        return min(Query(l, r, LS, gl, MID), Query(l, r, RS, MID + 1, gr));
    }
}st;

void dfs_pre(int p = 1, int fa = 0){
    ::fa[p] = fa;
    siz[p] = 1;
    dep[p] = dep[fa] + 1;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
        val[SON] = i->val;
        dfs_pre(SON, p);
        siz[p] += siz[SON];
        if(siz[SON] > siz[hson[p]])hson[p] = SON;
    }
}
void dfs_make(int p = 1, int top = 1){
    static int cdfn(0);
    dfn[p] = ++cdfn;
    idx[cdfn] = p;
    ::top[p] = top;
    if(hson[p])dfs_make(hson[p], top);
    for(auto i = head[p]; i; i = i->nxt)
        if(SON != fa[p] && SON != hson[p])dfs_make(SON, SON);
}
int lca(int s, int t){
    while(top[s] != top[t]){
        if(dep[top[s]] < dep[top[t]])swap(s, t);
        s = fa[top[s]];
    }if(dep[s] < dep[t])swap(s, t);
    return t;
}
int mdis(int s, int t){
    int mn(LIMIT);
    while(top[s] != top[t]){
        if(dep[top[s]] < dep[top[t]])swap(s, t);
        mn = min(mn, st.Query(dfn[top[s]], dfn[s]));
        s = fa[top[s]];
    }if(dep[s] < dep[t])swap(s, t);
    mn = min(mn, st.Query(dfn[hson[t]], dfn[s]));
    return mn;
}
void LinkVT(int s, int t, int val){
    vhead[s] = new Edge{vhead[s], t, val};
    vhead[t] = new Edge{vhead[t], s, val};
}
void BuildVT(void){
    int len = S.size();
    sort(S.begin(), S.end(), [](const int &a, const int &b){return dfn[a] < dfn[b];});
    for(int i = 1; i < len; ++i)S += lca(S(i), S(i + 1));
    sort(S.begin(), S.end(), [](const int &a, const int &b){return dfn[a] < dfn[b];});
    S.erase(unique(S.begin(), S.end()), S.end());
    int p;
    for(auto it = S.begin(); it != prev(S.end()); ++it)
        p = lca(*it, *next(it)), LinkVT(*next(it), p, mdis(*next(it), p));
}
void dfs_vt(int p = 1, int fa = 0, Edge* lst = npt){
    ll tot(0);
    for(auto i = vhead[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_vt(SON, p, i);
        tot += i->val;
    }if(p != 1 && !isKey[p] && tot)lst->val = min((ll)lst->val, tot);
}


int main(){
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read(), v = read();
        head[s] = new Edge{head[s], t, v};
        head[t] = new Edge{head[t], s, v};
    }dfs_pre(), dfs_make(), st.Build();
    Q = read();
    while(Q--){
        ans = 0;
        for(auto p : S)vhead[p] = npt, isKey[p] = false;
        S.clear(); S += 1;
        int cnt = read();
        while(cnt--){int p = read(); S += p, isKey[p] = true;}
        
        // bool flag(false);
        // for(auto p : S)if(isKey[fa[p]]){printf("-1\n"); flag = true; break;}
        // if(flag)continue;
        BuildVT();
        dfs_vt();
        for(auto i = vhead[1]; i; i = i->nxt)
            ans += i->val;
        // dfs_vt(*S.begin());
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