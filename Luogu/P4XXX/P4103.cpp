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

template < typename T = int >
inline T read(void);

struct Edge{
    Edge* nxt;
    int to;
    int val;
    OPNEW;
}ed[6100000];
ROPNEW;
Edge* head[4100000];
Edge* vhead[4100000];

int N, Q;
int dep[4100000], dfn[4100000], idx[4100000], top[4100000], fa[4100000], hson[4100000], siz[4100000];
basic_string < int > S;
bitset < 4100000 > isKey;

void dfs_pre(int p = 1, int fa = 0){
    ::fa[p] = fa;
    siz[p] = 1;
    dep[p] = dep[fa] + 1;
    for(auto i = head[p]; i; i = i->nxt){
        if(SON == fa)continue;
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
int dis(int s, int t){
    int dis(0);
    while(top[s] != top[t]){
        if(dep[top[s]] < dep[top[t]])swap(s, t);
        dis += dep[s] - dep[top[s]] + 1;
        s = fa[top[s]];
    }if(dep[s] < dep[t])swap(s, t);
    dis += dep[s] - dep[t];
    return dis;
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
        p = lca(*it, *next(it)), LinkVT(*next(it), p, dis(*next(it), p));
}

ll sum(0), smx(0), smn(LONG_LONG_MAX >> 1);
int tot;
int sizvt[4100000];
ll mx[4100000], mn[4100000];
ll mx1[4100000], mx2[4100000];
ll mn1[4100000], mn2[4100000];

void dfs_vt(int p, int fa = 0){
    if(isKey[p])sizvt[p] = 1;
    for(auto i = vhead[p]; i; i = i->nxt){
        if(SON == fa)continue;
        dfs_vt(SON, p);
        sizvt[p] += sizvt[SON];
        sum += (ll)sizvt[SON] * (tot - sizvt[SON]) * i->val;
        ll lenMx = mx[SON] + i->val, lenMn = (isKey[SON] ? 0 : mn[SON]) + i->val;
        if(sizvt[SON])mx[p] = max(mx[p], lenMx), mn[p] = min(mn[p], lenMn);
        if(lenMx > mx1[p])mx2[p] = mx1[p], mx1[p] = lenMx;
        else if(lenMx > mx2[p])mx2[p] = lenMx;
        if(lenMn < mn1[p])mn2[p] = mn1[p], mn1[p] = lenMn;
        else if(lenMn < mn2[p])mn2[p] = lenMn;
    }smx = max(smx, mx1[p] + mx2[p]), smn = min(smn, mn1[p] + mn2[p]);
    if(isKey[p])smx = max(smx, mx[p]), smn = min(smn, mn[p]);
}

int main(){
    memset(mn, 0x3f, sizeof mn);
    memset(mn1, 0x3f, sizeof mn1);
    memset(mn2, 0x3f, sizeof mn2);
    N = read();
    for(int i = 1; i <= N - 1; ++i){
        int s = read(), t = read();
        head[s] = new Edge{head[s], t};
        head[t] = new Edge{head[t], s};
    }dfs_pre(), dfs_make();
    Q = read();
    while(Q--){
        sum = 0, smx = 0, smn = LONG_LONG_MAX >> 1;
        for(auto p : S)vhead[p] = npt, isKey[p] = false, sizvt[p] = 0, mx[p] = mx1[p] = mx2[p] = 0, mn[p] = mn1[p] = mn2[p] = INFLL;
        S.clear();
        int cnt = read(); tot = cnt;
        while(cnt--){int p = read(); S += p, isKey[p] = true;}
        // bool flag(false);
        // for(auto p : S)if(isKey[fa[p]]){printf("-1\n"); flag = true; break;}
        // if(flag)continue;
        BuildVT();
        dfs_vt(*S.begin());
        printf("%lld %lld %lld\n", sum, smn, smx);
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